#include "addacountwindow.h"
#include "ui_addacountwindow.h"
#include "adminwindow.h"

addAcountWindow::addAcountWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addAcountWindow)
{
    ui->setupUi(this);
}

addAcountWindow::~addAcountWindow()
{
    delete ui;
}

/* 添加员工 */
void addAcountWindow::on_addButton_clicked()
{
    // 获取账号和密码
    QString account = ui->accountLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    // 判断是账号和密码是否有输入
    if(account == "" || passwd == "")
    {
         QMessageBox::warning(this,"添加员工","添加失败,用户名或密码不能为空!");
         return;
        }
    emit(addStaffInfo(account,passwd));
    this->close();
}
