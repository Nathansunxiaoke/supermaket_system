#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "staff.h"
#include "adminwindow.h"
#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "staffmanagerwin.h"

namespace Ui {
class loginWindow;
}

class loginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

private slots:
    void on_loginButton_clicked();

    void on_staffButton_clicked();

    void on_adminButton_clicked();
private:
    /* 初始化员工信息 */
    void initStaffData();
    /* 检查员工账号和密码 */
    int chechAdminLogin(const QString& account,const QString& passwd);
    /* 检查管理员账号和密码 */
    int chechStaffLogin(const QString& account,const QString& passwd);
    /* 解析Jsong格式的员工数据 */
    void getStaffData(const QByteArray& array);
private:
    Ui::loginWindow *ui;

    QList<Staff> staffList; // 存储员工链表
    bool loginFlag;         // true 员工登陆 false 管理员登陆
    QMessageBox *loginMsg;  // 登陆监测提示框
    int loginTimes;         // 登陆次数
};

#endif // LOGINWINDOW_H
