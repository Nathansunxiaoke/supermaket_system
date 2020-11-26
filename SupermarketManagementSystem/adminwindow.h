#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "staff.h"
#include "staffitem.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "addacountwindow.h"
#include "goodsitemsinfo.h"
#include "addgoodswindow.h"
#include "goods.h"
#include "goodsitem.h"
#include "staffinfobar.h"
#include "loginwindow.h"

namespace Ui {
class adminWindow;
}

class adminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminWindow(QWidget *parent = nullptr,QList<Staff> *staffList = nullptr);
    ~adminWindow();
private slots:
    void on_addStaffButton_clicked();

    void on_delStaffButton_clicked();

    void on_funComboBox_activated(const QString &arg1);
    /* 连接添加用户槽函数*/
    void getStaffInfo(const QString& account,const QString& passwd);
    void getGoodsInfo(const QString& name,const QString& kind,
                      int purchasingPrice,int retailPrice,
                      int quentityStcok);
    void on_goodsListButton_clicked();

    void on_buyGoodsButton_clicked();
    void on_retuenLoginButton_clicked();

    /* 修改后的信息 */
    void rcvStaffMeg(const QString& number,const QString& account,const QString& passwd);
private:
    /*读取Goods的文本数据 */
    void goodsReadFile();
    /* 初始胡员工条目 */
    void initStaffItem();
    /* 初始化货物信息 */
    void initGoodsData();
    /* 保存新员工的数据到文件 */
    void saveStaffInfo(const QString& number,const QString& account,const QString& passwd,bool mode);
    // 保存数据
    void saveGoodsData(Goods goodsList);



private:
    Ui::adminWindow *ui;
    QList<Staff> *staffList;
    QList<Goods> goodsList;
    static int number;
};

#endif // ADMINWINDOW_H
