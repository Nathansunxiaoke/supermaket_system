#include "addstaff.h"
#include "ui_addstaff.h"

addStaff::addStaff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStaff)
{
    ui->setupUi(this);
}

addStaff::~addStaff()
{
    delete ui;
}

/* 添加员工 */
void addStaff::on_addButton_clicked()
{
    // 获取输入的账号和密码
    QString account = ui->accountLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    emit(addStaffInfo(account,passwd));
    // 关闭当前窗口
}
