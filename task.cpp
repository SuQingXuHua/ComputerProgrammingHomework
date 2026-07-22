#include "task.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

// ============================================================
// 时间工具函数
// ============================================================

// 检查字符是否为数字 '0'-'9'
static bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

// 检查时间字符串格式：YYYY-MM-DD HH:MM
// 手动逐字符检查
bool isValidTimeFormat(const std::string &timeStr)
{
    // 长度必须是 16 个字符："YYYY-MM-DD HH:MM"
    if (timeStr.length() != 16)
        return false;

    // 逐位置检查格式：YYYY-MM-DD HH:MM
    // 位置: 0123-56-89 12:45
    // YYYY: 0-3,  MM: 5-6,  DD: 8-9,  HH: 11-12,  MM: 14-15

    // 检查年份 (位置 0-3)
    if (!isDigit(timeStr[0]) || !isDigit(timeStr[1]) ||
        !isDigit(timeStr[2]) || !isDigit(timeStr[3]))
        return false;

    // 检查连字符 (位置 4)
    if (timeStr[4] != '-')
        return false;

    // 检查月份 (位置 5-6)：01-12
    if (!isDigit(timeStr[5]) || !isDigit(timeStr[6]))
        return false;
    int month = (timeStr[5] - '0') * 10 + (timeStr[6] - '0');
    if (month < 1 || month > 12)
        return false;

    // 检查连字符 (位置 7)
    if (timeStr[7] != '-')
        return false;

    // 检查日期 (位置 8-9)：01-31
    if (!isDigit(timeStr[8]) || !isDigit(timeStr[9]))
        return false;
    int day = (timeStr[8] - '0') * 10 + (timeStr[9] - '0');
    if (day < 1 || day > 31)
        return false;

    // 检查空格 (位置 10)
    if (timeStr[10] != ' ')
        return false;

    // 检查小时 (位置 11-12)：00-23
    if (!isDigit(timeStr[11]) || !isDigit(timeStr[12]))
        return false;
    int hour = (timeStr[11] - '0') * 10 + (timeStr[12] - '0');
    if (hour < 0 || hour > 23)
        return false;

    // 检查冒号 (位置 13)
    if (timeStr[13] != ':')
        return false;

    // 检查分钟 (位置 14-15)：00-59
    if (!isDigit(timeStr[14]) || !isDigit(timeStr[15]))
        return false;
    int minute = (timeStr[14] - '0') * 10 + (timeStr[15] - '0');
    if (minute < 0 || minute > 59)
        return false;

    return true;
}

// 比较两个时间字符串
int compareTime(const std::string &t1, const std::string &t2)
{
    if (t1 < t2)
        return -1; // t1 更早
    if (t1 > t2)
        return 1; // t1 更晚
    return 0;     // 相同
}

// 获取当前系统时间字符串
std::string getCurrentTimeString()
{
    // 获取当前时间点
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    // 转换为本地时间结构体
    std::tm tm;
#ifdef _WIN32
    localtime_s(&tm, &t); // Windows 安全版本
#else
    localtime_r(&t, &tm); // POSIX 版本
#endif

    // 使用 stringstream 格式化为 "YYYY-MM-DD HH:MM"
    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(4) << (tm.tm_year + 1900) << "-"
        << std::setw(2) << (tm.tm_mon + 1) << "-"
        << std::setw(2) << tm.tm_mday << " "
        << std::setw(2) << tm.tm_hour << ":"
        << std::setw(2) << tm.tm_min;
    return oss.str();
}

// ============================================================
// TaskManager 实现
// ============================================================

TaskManager::TaskManager()
    : m_nextId(1) // 任务 ID 从 1 开始
{
}

int TaskManager::addTask(const std::string &name, const std::string &startTime,
                         const std::string &priority, const std::string &category,
                         const std::string &reminderTime)
{
    // ---- 加锁：保护共享数据 ----
    m_mutex.lock();

    // ---- 1. 验证必填字段 ----
    if (name.empty() || startTime.empty())
    {
        std::cerr << "错误：任务名称和开始时间为必填项。" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 2. 验证开始时间格式 ----
    if (!isValidTimeFormat(startTime))
    {
        std::cerr << "错误：开始时间格式不正确。请使用格式：YYYY-MM-DD HH:MM" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 3. 验证提醒时间格式（如果有的话） ----
    if (!reminderTime.empty() && !isValidTimeFormat(reminderTime))
    {
        std::cerr << "错误：提醒时间格式不正确。请使用格式：YYYY-MM-DD HH:MM" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 4. 处理优先级：空值用默认值 "medium" ----
    std::string prio = priority;
    if (prio.empty())
    {
        prio = "medium";
    }
    if (prio != "high" && prio != "medium" && prio != "low")
    {
        std::cerr << "错误：优先级必须是 high（高）、medium（中）或 low（低）。" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 5. 处理分类：空值用默认值 "life" ----
    std::string cat = category;
    if (cat.empty())
    {
        cat = "life";
    }
    if (cat != "study" && cat != "entertainment" && cat != "life")
    {
        std::cerr << "错误：分类必须是 study（学习）、entertainment（娱乐）或 life（生活）。" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 6. 检查开始时间唯一性 ----
    if (!isStartTimeUnique(startTime, -1))
    {
        std::cerr << "错误：开始时间为 '" << startTime << "' 的任务已存在。" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 7. 检查"名称+开始时间"唯一性 ----
    if (!isNameTimeUnique(name, startTime, -1))
    {
        std::cerr << "错误：名称为 '" << name << "'、开始时间为 '"
                  << startTime << "' 的任务已存在。" << std::endl;
        m_mutex.unlock();
        return -1;
    }

    // ---- 8. 创建任务并添加到列表 ----
    Task task;
    task.id = m_nextId;
    m_nextId = m_nextId + 1; // ID 自增
    task.name = name;
    task.startTime = startTime;
    task.priority = prio;
    task.category = cat;
    task.reminderTime = reminderTime;

    m_tasks.push_back(task);

    std::cout << "任务添加成功。ID：" << task.id << std::endl;

    m_mutex.unlock();
    return task.id;
}

bool TaskManager::deleteTask(int id)
{
    m_mutex.lock();

    // 查找要删除的任务
    int targetIndex = -1;
    for (size_t i = 0; i < m_tasks.size(); ++i)
    {
        if (m_tasks[i].id == id)
        {
            targetIndex = static_cast<int>(i);
            break;
        }
    }

    // 没找到
    if (targetIndex == -1)
    {
        std::cerr << "错误：未找到 ID 为 " << id << " 的任务。" << std::endl;
        m_mutex.unlock();
        return false;
    }

    // 删除：将后面的元素前移
    m_tasks.erase(m_tasks.begin() + targetIndex);

    // 同时从已提醒集合中移除
    m_remindedIds.erase(id);

    std::cout << "任务 " << id << " 删除成功。" << std::endl;

    m_mutex.unlock();
    return true;
}

std::vector<Task> TaskManager::getTasks() const
{
    m_mutex.lock();

    // 复制一份任务列表
    std::vector<Task> sorted = m_tasks;

    m_mutex.unlock();

    // ---- 冒泡排序：按开始时间升序排列 ----
    size_t n = sorted.size();
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n - 1 - i; ++j)
        {
            // 如果前面的任务开始时间更晚，交换
            if (compareTime(sorted[j].startTime, sorted[j + 1].startTime) > 0)
            {
                Task temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    return sorted;
}

void TaskManager::displayTasks() const
{
    // 获取排序后的任务列表
    std::vector<Task> tasks = getTasks();

    if (tasks.empty())
    {
        std::cout << "暂无任务。" << std::endl;
        return;
    }

    // ---- 列宽设置 ----
    const int idW = 5;
    const int nameW = 20;
    const int startW = 18;
    const int prioW = 10;
    const int catW = 14;
    const int remindW = 18;

    // ---- 打印表头 ----
    std::cout << std::left
              << std::setw(idW) << "ID"
              << std::setw(nameW) << "任务名称"
              << std::setw(startW) << "开始时间"
              << std::setw(prioW) << "优先级"
              << std::setw(catW) << "分类"
              << std::setw(remindW) << "提醒时间"
              << std::endl;

    // ---- 打印分隔线 ----
    int totalWidth = idW + nameW + startW + prioW + catW + remindW;
    for (int i = 0; i < totalWidth; ++i)
    {
        std::cout << '-';
    }
    std::cout << std::endl;

    // ---- 打印每条任务 ----
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        const Task &t = tasks[i];

        // 如果名称太长，截断并加 "..."
        std::string displayName = t.name;
        if (displayName.length() > static_cast<size_t>(nameW - 1))
        {
            displayName = displayName.substr(0, nameW - 4) + "...";
        }

        // 优先级转为中文显示
        std::string prioDisplay;
        if (t.priority == "high")
        {
            prioDisplay = "高";
        }
        else if (t.priority == "medium")
        {
            prioDisplay = "中";
        }
        else
        {
            prioDisplay = "低";
        }

        // 分类转为中文显示
        std::string catDisplay;
        if (t.category == "study")
        {
            catDisplay = "学习";
        }
        else if (t.category == "entertainment")
        {
            catDisplay = "娱乐";
        }
        else
        {
            catDisplay = "生活";
        }

        // 提醒时间为空时显示 "-"
        std::string remindDisplay = t.reminderTime;
        if (remindDisplay.empty())
        {
            remindDisplay = "-";
        }

        std::cout << std::left
                  << std::setw(idW) << t.id
                  << std::setw(nameW) << displayName
                  << std::setw(startW) << t.startTime
                  << std::setw(prioW) << prioDisplay
                  << std::setw(catW) << catDisplay
                  << std::setw(remindW) << remindDisplay
                  << std::endl;
    }

    std::cout << "\n共 " << tasks.size() << " 个任务" << std::endl;
}

std::vector<Task> TaskManager::getDueReminders(const std::string &now)
{
    m_mutex.lock();

    std::vector<Task> due; // 存储到期且未提醒的任务

    for (size_t i = 0; i < m_tasks.size(); ++i)
    {
        const Task &t = m_tasks[i];

        // 条件1：设置了提醒时间
        if (t.reminderTime.empty())
            continue;

        // 条件2：提醒时间 <= 当前时间
        if (compareTime(t.reminderTime, now) > 0)
            continue;

        // 条件3：还没提醒过
        if (m_remindedIds.count(t.id) > 0)
            continue;

        // 满足所有条件 → 需要提醒
        due.push_back(t);

        // 标记为已提醒，防止重复
        m_remindedIds.insert(t.id);
    }

    m_mutex.unlock();
    return due;
}

void TaskManager::loadTasks(const std::vector<Task> &tasks)
{
    m_mutex.lock();

    m_tasks = tasks;
    m_remindedIds.clear(); // 清空已提醒记录

    // 找到当前最大的 ID，设置 nextId
    m_nextId = 1;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i].id >= m_nextId)
        {
            m_nextId = tasks[i].id + 1;
        }
    }

    m_mutex.unlock();
}

std::vector<Task> TaskManager::getTasksForSave() const
{
    m_mutex.lock();
    std::vector<Task> copy = m_tasks;
    m_mutex.unlock();
    return copy;
}

void TaskManager::setNextId(int id)
{
    m_nextId = id;
}

int TaskManager::getNextId() const
{
    return m_nextId;
}

// ---- 私有辅助函数 ----

bool TaskManager::isStartTimeUnique(const std::string &startTime, int excludeId) const
{
    for (size_t i = 0; i < m_tasks.size(); ++i)
    {
        const Task &t = m_tasks[i];
        // 如果有相同开始时间，且不是被排除的任务本身 → 不唯一
        if (t.startTime == startTime && t.id != excludeId)
        {
            return false;
        }
    }
    return true;
}

bool TaskManager::isNameTimeUnique(const std::string &name, const std::string &startTime, int excludeId) const
{
    for (size_t i = 0; i < m_tasks.size(); ++i)
    {
        const Task &t = m_tasks[i];
        // 如果名称和开始时间都相同，且不是被排除的任务本身 → 不唯一
        if (t.name == name && t.startTime == startTime && t.id != excludeId)
        {
            return false;
        }
    }
    return true;
}

