#include "staffitem.h"
#include "ui_staffitem.h"
#include <QDebug>

staffitem::staffitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staffitem)
{
    ui->setupUi(this);
}

staffitem::~staffitem()
{
    delete ui;
}

/* 设置自定义条目信息 */
void staffitem::setstaffinfo(const QString& number,const QString &account, const QString &passwd)
{
    ui->numberLabel->setText(number);
    ui->accountLabel->setText(account);
    ui->passwdLabel->setText(passwd);
}

/* 修改信息 */
void staffitem::on_changeButton_clicked()
{
    QString account = ui->accountLabel->text();
    QString passwd = ui->passwdLabel->text();

    QString inputAccount = QInputDialog::getText(this,"修改信息","请输入新的账号名");
    QString inputpasswd = QInputDialog::getText(this,"修改信息","请输入新的账号名");

    if(inputAccount == "" && !inputpasswd.isEmpty())
    {
        ui->accountLabel->setText(account);
        ui->passwdLabel->setText(inputpasswd);
    }
    if(inputpasswd == "" && !inputAccount.isEmpty())
    {
        ui->accountLabel->setText(inputAccount);
        ui->passwdLabel->setText(passwd);
    }
    if(inputAccount == "" && inputpasswd == "")
    {
        ui->accountLabel->setText(account);
        ui->passwdLabel->setText(passwd);
    }
    //
}
