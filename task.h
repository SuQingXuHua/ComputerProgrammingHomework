#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>
#include <mutex>
#include <set>

// ============================================================
// Task 结构体：存储单个任务的所有信息
// ============================================================
struct Task
{
    int id;                   // 唯一任务编号（自动分配）
    std::string name;         // 任务名称
    std::string startTime;    // 开始时间，格式 "YYYY-MM-DD HH:MM"
    std::string priority;     // 优先级："high"（高）/ "medium"（中）/ "low"（低）
    std::string category;     // 分类："study"（学习）/ "entertainment"（娱乐）/ "life"（生活）
    std::string reminderTime; // 提醒时间，格式 "YYYY-MM-DD HH:MM"（可为空表示不提醒）
};

// ============================================================
// TaskManager 类：管理所有任务（增删查）
// 使用互斥锁（mutex）保护数据，支持多线程安全访问
// ============================================================
class TaskManager
{
public:
    TaskManager();

    // 添加任务：成功返回任务 ID，失败返回 -1
    int addTask(const std::string &name, const std::string &startTime,
                const std::string &priority, const std::string &category,
                const std::string &reminderTime);

    // 删除任务：成功返回 true
    bool deleteTask(int id);

    // 获取所有任务（按开始时间排序后的副本）
    std::vector<Task> getTasks() const;

    // 显示所有任务（表格形式，按列对齐）
    void displayTasks() const;

    // 获取提醒时间已到的任务，并标记为"已提醒"避免重复提醒
    // now: 当前时间字符串 "YYYY-MM-DD HH:MM"
    std::vector<Task> getDueReminders(const std::string &now);

    // 从外部加载任务列表（替换内存中的全部任务）
    void loadTasks(const std::vector<Task> &tasks);

    // 获取任务列表用于保存到文件
    std::vector<Task> getTasksForSave() const;

    // 设置/获取下一个可用的任务 ID
    void setNextId(int id);
    int getNextId() const;

private:
    // 检查开始时间是否唯一（不允许两个任务同时开始）
    bool isStartTimeUnique(const std::string &startTime, int excludeId) const;
    // 检查"名称+开始时间"组合是否唯一
    bool isNameTimeUnique(const std::string &name, const std::string &startTime, int excludeId) const;

    std::vector<Task> m_tasks;   // 所有任务
    std::set<int> m_remindedIds; // 已提醒过的任务 ID（防止重复提醒）
    int m_nextId;                // 下一个可分配的任务 ID
    mutable std::mutex m_mutex;  // 互斥锁：保护多线程访问
};

// ============================================================
// 时间相关的工具函数
// ============================================================

// 检查时间字符串格式是否正确（YYYY-MM-DD HH:MM）
bool isValidTimeFormat(const std::string &timeStr);

// 比较两个时间字符串：返回 -1（t1更早）、0（相同）、1（t1更晚）
int compareTime(const std::string &t1, const std::string &t2);

// 获取当前系统时间，格式为 "YYYY-MM-DD HH:MM"
std::string getCurrentTimeString();

#endif // TASK_H

