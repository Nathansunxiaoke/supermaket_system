#ifndef STAFFMANAGERWIN_H
#define STAFFMANAGERWIN_H

#include <QMainWindow>
#include "goods.h"
#include <QListWidgetItem>
#include "shopbar.h"
#include "commodity.h"
#include "buygoods.h"
#include "buygoodsinfo.h"
#include <QMessageBox>


namespace Ui {
class staffManagerWin;
}

class staffManagerWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit staffManagerWin(QWidget *parent = nullptr);
    ~staffManagerWin();
private slots:
    void on_goodsListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_shopListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_retunLoginButton_clicked();

    void on_closeButton_clicked();

private:
    /* 初始胡商店信息列表 */
    void initGoodsList();
    /* 加载信息到条目 */
    void initItemList();
    /* 加载购物车信息到条目 */
    void initBuyItemList();
    /* 加载购物栏 */
    void initshopbar();
    /* 计算购物车消费 */
    void calcBill();
    /* 增加商店数量 */
    void addGoodscount(const QString& oldname);
    /* 保存货物文件信息 */
    void savegoodsDatafile();
private:
    Ui::staffManagerWin *ui;
    QList<Goods> goodsList;
    QList<buyGoods> buyList;
};

#endif // STAFFMANAGERWIN_H
