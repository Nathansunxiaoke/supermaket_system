#include "staffmanagerwin.h"
#include "ui_staffmanagerwin.h"
#include "adminwindow.h"
#include <QtDebug>

staffManagerWin::staffManagerWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::staffManagerWin)
{
    ui->setupUi(this);
    // 初始胡商店信息列表
    initGoodsList();

    // 加载信息到条目
    initItemList();

    // 加载购物栏
    initshopbar();
}

staffManagerWin::~staffManagerWin()
{
    delete ui;
}

/* 初始胡商店信息列表 */
void staffManagerWin::initGoodsList()
{
    // 创建文件对象
    QFile file("./../supermarketData/goodsData.txt");

    // 打开文件
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array = file.readAll();
        // 将json数据转换车工QjsonDocumen文本呢对象
        QJsonDocument doc = QJsonDocument::fromJson(array);

        // 将QjosnDocumen转换成QJsonObject对象
        QJsonObject object = doc.object();

        // 根据文本格式解析存到QList
        QJsonArray jsonArray = object.value("goods").toArray();

        // 将QJsonarray里元素转换成QjsonOnject
        for(int i = 0;i < jsonArray.size();i++)
        {
            QJsonObject dataObject = jsonArray.at(i).toObject();

            Goods goods;
            goods.setNameGoods(dataObject.value("name").toString().toStdString());
            goods.setKingGoods(dataObject.value("kind").toString().toStdString());

            goods.setPurchasingPrice((dataObject.value("purchasingPrice").toString().toInt()));
            goods.setRetailPrice(dataObject.value("retailPrice").toString().toInt());
            goods.setQuentityStcok(dataObject.value("quentityStock").toString().toInt());

            goodsList.append(goods);
        }
    }
    file.close();
}

/* 加载信息到条目 */
void staffManagerWin::initItemList()
{
    // 开启货物管理功能，清空员工条目,加载货物
    ui->goodsListWidget->clear();

    // 遍历goodsList
    for(int i = 0;i < goodsList.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        ui->goodsListWidget->addItem(item);

        commodity *com = new commodity;
        com->setCommodityInfo(QString::fromStdString(goodsList.at(i).getNameGoods()),
                              QString::fromStdString(goodsList.at(i).getKingGoods()),
                              goodsList.at(i).getRetailPrice(),
                              goodsList.at(i).getQuentityStcok());

        QSize size(500,60);
        item->setSizeHint(size);

        // 关联自定义空间
        ui->goodsListWidget->setItemWidget(item,com);
    }
}

/* 加载购物车信息到条目 */
void staffManagerWin::initBuyItemList()
{
    // 清空购物车条目
    ui->shopListWidget->clear();
    initshopbar();

    // 遍历goodsList
    for(int i = 0;i < buyList.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        ui->shopListWidget->addItem(item);

        qDebug()<<QString::fromStdString(buyList.at(i).getBuyGoodsName());
        BuyGoodsInfo *buy = new BuyGoodsInfo;

        buy->setGoodsInfo(QString::fromStdString(buyList.at(i).getBuyGoodsName()),
                          buyList.at(i).getCount());


        QSize size(500,40);
        item->setSizeHint(size);

        // 关联自定义空间
        ui->shopListWidget->setItemWidget(item,buy);
    }
    // 计算花费多钱
    calcBill();
}

/* 加载购物栏 */
void staffManagerWin::initshopbar()
{
    QListWidgetItem *item = new QListWidgetItem;
    ui->shopListWidget->addItem(item);

    shopBar *shoppingBar = new shopBar;
    QSize size(250,40);
    item->setSizeHint(size);

    ui->shopListWidget->setItemWidget(item,shoppingBar);
}

/* 计算购物车消费 */
void staffManagerWin::calcBill()
{
    int sum = 0;
    for(int i = 0;i < buyList.size();i++)
    {
        sum += (buyList.at(i).getCount() * buyList.at(i).getBuyprice()) ;
    }
    // 显示到ui
    ui->sumlabel->setText(QString::number(sum));
}

/* 增加商店数量 */
void staffManagerWin::addGoodscount(const QString& oldname)
{
    // 数量加一
    Goods goods;
    for(int i = 0;i < goodsList.size();i++)
    {
        if(oldname == QString::fromStdString(goodsList.at(i).getNameGoods()))
        {

            goods = goodsList.at(i);
            int addCount = goods.getQuentityStcok() + 1;
            goods.setQuentityStcok(addCount);
            goodsList.removeAt(i);
            goodsList.insert(i,goods);
            initItemList();
            break;
        }
    }
}

/* 保存货物文件信息 */
void staffManagerWin::savegoodsDatafile()
{
    QJsonArray array;
    // 创建需要打包的QJsonObject对象
    for(int i = 0;i < goodsList.size();i++)
    {
        QJsonObject object;
        object.insert("name",QString::fromStdString(goodsList.at(i).getNameGoods()));
        object.insert("kind",QString::fromStdString(goodsList.at(i).getKingGoods()));

        object.insert("purchasingPrice",QString::number(goodsList.at(i).getPurchasingPrice()));
        object.insert("retailPrice",QString::number(goodsList.at(i).getRetailPrice()));
        object.insert("quentityStock",QString::number(goodsList.at(i).getQuentityStcok()));

        array.append(object);
    }
    // 将QjonsArray创建成QJsonObject
    QJsonObject desObject;
    desObject.insert("goods",array);

    // 将Qjson对象百年城QJsonDocment
    QJsonDocument doc(desObject);

    QByteArray data = doc.toJson();

    // 保存文件
    QFile file("./../supermarketData/goodsData.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(data);
    }
}

/* 双击购买商品 */
void staffManagerWin::on_goodsListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    // 获取当前商品的所有信息
    int row = ui->goodsListWidget->currentRow();
    // 修改QList容器里的值
    Goods goods = goodsList.at(row);
    goodsList.removeAt(row);
    int count = goods.getQuentityStcok();
    if(count == 0)
    {
        goods.setQuentityStcok(0);
        goodsList.insert(row,goods);
        QMessageBox::information(this,"购物提示","对不起你购买的商品已售空!");
        return ;

    }
    goods.setQuentityStcok(--count);
    goodsList.insert(row,goods);

    initItemList();
    // 购物车增加购物商品
    buyGoods buy;
    qDebug()<<"buy List"<<buyList.size();
    for(int i = 0;i < buyList.size();i++)
    {
        if(QString::fromStdString(goods.getNameGoods()) == QString::fromStdString(buyList.at(i).getBuyGoodsName()))
        {
            // 购物车有相同的商品
            int oldbuycount = buyList.at(i).getCount();
            buy.setBuyGoodsName(buyList.at(i).getBuyGoodsName());
            buy.setBuyprice(buyList.at(i).getBuyprice());
            buy.setCount(++oldbuycount);
            buyList.removeAt(i);
            buyList.insert(i,buy);
            // 刷新条目
            initBuyItemList();
            return ;
        }
    }

    // 购买的是新商品
    buy.setBuyGoodsName(goods.getNameGoods());
    buy.setBuyprice(goods.getRetailPrice());
    buy.setCount(1);
    buyList.append(buy);
    initBuyItemList();
    // 保存文件信息
}

/* 双击购物测数量减少 */
void staffManagerWin::on_shopListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    // 获取行号
    if(ui->shopListWidget->currentRow() == 0)
    {
        // 点击无效
        return;
    }
    int row = ui->shopListWidget->currentRow()-1;

    // 将商店数量加一购物车数量减一
    buyGoods buy;
    buy = buyList.at(row);
    int oldcount = buy.getCount();
    QString oldname = QString::fromStdString(buy.getBuyGoodsName());
    buy.setCount(--oldcount);
    if(oldcount == 0)
    {
        // 购物车数量为0
        buyList.removeAt(row);
        initBuyItemList();
        //增加商品数量
        addGoodscount(oldname);
        return ;
    }
    buyList.removeAt(row);
    buyList.insert(row,buy);

    initBuyItemList();
    addGoodscount(oldname);

    // 保存文件信息
}

/* 返回登陆界面 */
void staffManagerWin::on_retunLoginButton_clicked()
{
    loginWindow *loginMeun = new loginWindow;
    loginMeun->show();
    this->close();
}

/* 商品结算 */
void staffManagerWin::on_closeButton_clicked()
{
    savegoodsDatafile();
    QString text = QString("您一共消费%1元,请支付").arg(ui->sumlabel->text());
    QMessageBox::information(this,"消费结算",text);
    ui->shopListWidget->clear();

    /* 保存用户消费记录信息 */

}


