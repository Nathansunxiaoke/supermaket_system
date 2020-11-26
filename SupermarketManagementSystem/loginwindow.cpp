#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QtDebug>

loginWindow::loginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);

    initStaffData();
    loginFlag = false;
    // 创建消息提示框
    loginTimes = 3;
    loginMsg = new QMessageBox;
    loginMsg->setWindowTitle("登陆提示");
    // 固定登录界面窗口大小
    this->setFixedSize(this->width(),this->height());
}

loginWindow::~loginWindow()
{
    delete ui;
}

/* 系统登陆按钮 */
void loginWindow::on_loginButton_clicked()
{
    // 获取输入栏上的账号和密码
    QString account = ui->accountLineEdit->text();
    QString passwd = ui->passwdLineEdit->text();
    // 判断是用户登陆还是管理员登陆
   if(loginFlag)
   {
       // 选择员工,判断员工账号和密码
       if(chechStaffLogin(account,passwd) < 0 )
       {
           return;
       }
       else {
           this->close();
           staffManagerWin *staffMeun = new staffManagerWin;
           staffMeun->show();
       }
   }
   else {
       // 选择管理员 账号名 ："root" 密码 "123456"
       // 判断管理员账号和密码
       if(chechAdminLogin(account,passwd) < 0)
       {
           return;
       }
       else {
           // 进入管理员界面
           this->close();
           adminWindow *adminMeun = new adminWindow(this,&this->staffList);
           adminMeun->show();
       }
   }
}

/* 员工登陆 */
void loginWindow::on_staffButton_clicked()
{
    // 员工登陆
    loginFlag = true;
}

/* 管理与登陆 */
void loginWindow::on_adminButton_clicked()
{
    // 管理员登陆
    loginFlag = false;
}

/* 初始化员工信息 */
void loginWindow::initStaffData()
{
    // 创建文件对象
    QFile file("./../supermarketData/staffData.txt");

    // 打开文件
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array = file.readAll();
        getStaffData(array);
    }
    file.close();
}

/* 检查管理员账号和密码 */
int loginWindow::chechAdminLogin(const QString &account, const QString &passwd)
{
    if(account == "root" && passwd == "123456")
    {
        // 账号和密码正确
        return  0;
    }
    // 账号或密码不正确
    if(loginTimes > 0)
    {
       QString text = QString("账号或密码不正确,请核对后在登陆!你还有%1次机会").arg(--this->loginTimes);
       loginMsg->setText(text);
       loginMsg->exec();
     }
     else {
     // 关闭信息
     this->close();
     }
    return  -1;
}

/* 检查员工账号和密码 */
int loginWindow::chechStaffLogin(const QString &account, const QString &passwd)
{
    // 遍历Qlist检查用户名和密码
    for(int i = 0;i < staffList.size();i++)
    {
        if(account == QString::fromStdString(staffList.at(i).getAccount()) &&
           passwd == QString::fromStdString(staffList.at(i).getPasswd()))
        {
            // 密码和账号正确
            qDebug()<<"zhhhh";
            return 0;
        }
    }
    // 账号或密码不正确
    if(loginTimes > 0)
    {
        qDebug()<<"ddddd";
        QString text = QString("账号或密码不正确,请核对后在登陆!你还有%1次机会").arg(--this->loginTimes);
        loginMsg->setText(text);
        loginMsg->exec();

     }
     else {
     // 关闭信息
     this->close();
     }
    return -1;
}

/* 解析Jsong格式的员工数据 */
void loginWindow::getStaffData(const QByteArray &array)
{
    // 将json数据转换车工QjsonDocumen文本呢对象
    QJsonDocument doc = QJsonDocument::fromJson(array);

    // 将QjosnDocumen转换成QJsonObject对象
    QJsonObject object = doc.object();

    // 根据文本格式解析存到QList
    QJsonArray jsonArray = object.value("user").toArray();
    qDebug()<<jsonArray.size();

    // 将QJsonarray里元素转换成QjsonOnject
    for(int i = 0;i < jsonArray.size();i++)
    {
        QJsonObject dataObject = jsonArray.at(i).toObject();
        QString number = dataObject.value("number").toString();
        QString name = dataObject.value("name").toString();
        QString passwd = dataObject.value("password").toString();

        Staff staff(number.toStdString(),name.toStdString(),passwd.toStdString());
        staffList.append(staff);
    }
}
























