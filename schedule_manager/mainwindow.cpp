#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui -> loginButton,
            &QPushButton::clicked,
            this,
            &MainWindow::login);

    connect(ui -> registerButton,
            &QPushButton::clicked,
            this,
            &MainWindow::registerUser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{

    QString username = ui -> usernameEdit -> text();


    QString password = ui -> passwordEdit -> text();


    if(userManager.login(username,password))
    {

        QMessageBox::information(
                    this,
                    "登录",
                    "登录成功"
                    );

    }
    else
    {

        QMessageBox::warning(
                    this,
                    "登录",
                    "用户名或密码错误"
                    );

    }

}

void MainWindow::registerUser()
{
    QString username = ui -> usernameEdit -> text();


    QString password = ui -> passwordEdit -> text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(
                    this,
                    "注册",
                    "用户名或密码不能为空");
        return;
    }

    if (userManager.registerUser(username,password))
    {
        QMessageBox::information(
                    this,
                    "注册",
                    "注册成功");
    }

    else
    {
        QMessageBox::warning(
                    this,
                    "注册",
                    "用户名已存在");
    }

}

