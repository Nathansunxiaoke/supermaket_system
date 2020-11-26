#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QDebug>

int adminWindow::number = 1000;

adminWindow::adminWindow(QWidget *parent,QList<Staff> *staffList) :
    QMainWindow(parent),
    ui(new Ui::adminWindow)
{
    this->staffList = staffList;

    // 固定窗口的大小
   // this->setFixedSize(this->width(),this->height());
    ui->setupUi(this);
    // 关闭货物管理功能
    ui->goodsListButton->setEnabled(false);
    ui->buyGoodsButton->setEnabled(false);

    initStaffItem();
    goodsReadFile();
}

adminWindow::~adminWindow()
{
    delete ui;
}

/* 初始化员工条目 */
void adminWindow::initStaffItem()
{
    ui->staffListWidget->clear();
    QListWidgetItem *item = new QListWidgetItem;
    ui->staffListWidget->addItem(item);

    QSize size(500,40);
    item->setSizeHint(size);
    staffInfoBar *staffBar = new staffInfoBar;
    ui->staffListWidget->setItemWidget(item,staffBar);



    // 遍历Qlist
    for(int i = 0 ;i < staffList->size();i++)
    {
        // 创建条目对象
        QListWidgetItem *item = new QListWidgetItem;
        ui->staffListWidget->addItem(item);

        // 使用自定义控件

        staffitem *staffInfo = new staffitem;
        staffInfo->setstaffinfo(QString::fromStdString(staffList->at(i).getNumber()),
                                QString::fromStdString(staffList->at(i).getAccount()),
                                QString::fromStdString(staffList->at(i).getPasswd()));
        QSize size(500,40);
        item->setSizeHint(size);

        // 关联自定义空间
        ui->staffListWidget->setItemWidget(item,staffInfo);
    }
}

/* 初始化货物信息 */
void adminWindow::initGoodsData()
{
    // 遍历goodsList
    for(int i = 0;i < goodsList.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        ui->staffListWidget->addItem(item);

        goodsitem *goodsItem = new goodsitem;
        goodsItem->setGoodsInfo(QString::fromStdString(goodsList.at(i).getNameGoods()),
                                QString::fromStdString(goodsList.at(i).getKingGoods()),
                                goodsList.at(i).getPurchasingPrice(),
                                goodsList.at(i).getRetailPrice(),
                                goodsList.at(i).getQuentityStcok());

        QSize size(500,40);
        item->setSizeHint(size);

        // 关联自定义空间
        ui->staffListWidget->setItemWidget(item,goodsItem);
    }
}

/* 保存新员工的数据到文件 */
void adminWindow::saveStaffInfo(const QString& number,const QString &account, const QString &passwd,bool mode)
{
    // 创建需要打包的QJsonObject对象
    QJsonObject object;
    object.insert("number",number);
    object.insert("name",account);
    object.insert("password",passwd);

    // 找到需要插入的位置
    QFile file("./../supermarketData/staffData.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(array);
        QJsonObject desObject = doc.object();
        QJsonArray arrayObject = desObject.value("user").toArray();
        if(mode == true)   // 增加员工
        {
            arrayObject.append(object);

        }
        else {
            for(int i = 0;i < arrayObject.size();i++)
            {
                QJsonObject delObject = arrayObject.at(i).toObject();
                if(delObject.value("name") == account && delObject.value("password") == passwd)
                {
                    arrayObject.removeAt(i);
                    break;
                }
            }
        }
        file.close();
        file.open(QIODevice::WriteOnly);
        desObject.insert("user",arrayObject);
        doc.setObject(desObject);
        array = doc.toJson();
        file.write(array);
        file.close();
    }
}

// 保存数据
void adminWindow::saveGoodsData(Goods goods)
{
    // 创建需要打包的QJsonObject对象
    QJsonObject object;
    object.insert("name",QString::fromStdString(goods.getNameGoods()));
    object.insert("kind",QString::fromStdString(goods.getKingGoods()));

    object.insert("purchasingPrice",QString::number(goods.getPurchasingPrice()));
    object.insert("retailPrice",QString::number(goods.getRetailPrice()));
    object.insert("quentityStock",QString::number(goods.getQuentityStcok()));

    // 找到需要插入的位置
    QFile file("./../supermarketData/goodsData.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray array = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(array);
        QJsonObject desObject = doc.object();
        QJsonArray arrayObject = desObject.value("goods").toArray();
        arrayObject.append(object);

        file.close();
        file.open(QIODevice::WriteOnly);
        desObject.insert("goods",arrayObject);
        doc.setObject(desObject);
        array = doc.toJson();
        file.write(array);
        file.close();
    }
}

/* 添加新收银员 */
void adminWindow::on_addStaffButton_clicked()
{
    // 提示输入需要添加的员工信息
    addAcountWindow *addInfoMeun = new addAcountWindow(this);
    connect(addInfoMeun,&addAcountWindow::addStaffInfo,this,&adminWindow::getStaffInfo);
    addInfoMeun->show();
}

/* 删除收银员 */
void adminWindow::on_delStaffButton_clicked()
{
    int i = 0;
    // 提示需要删除的员工的编号
    QString account = QInputDialog::getText(this,"删除员工","请输入需要删除的员工的账号");
    QString passwd;
    // 删除员工条目信息和Qlist
    for(i = 0;i < staffList->size();i++)
    {
        if(staffList->at(i).getAccount() == account.toStdString())
        {
            // 找到该用户，移除
            passwd = QString::fromStdString(staffList->at(i).getPasswd());
            staffList->removeAt(i);
            break;
        }
    }
    ui->staffListWidget->clear();
    initStaffItem();
    // 删除员工的文件信息
    saveStaffInfo(QString::number(i),account,passwd,false);
}

/* 功能选择 */
void adminWindow::on_funComboBox_activated(const QString &arg1)
{
    if(arg1 == "员工管理")
        {
        // 关闭货物管理功能
        ui->goodsListButton->setEnabled(false);
        ui->buyGoodsButton->setEnabled(false);

        // 开启员工管理功能,加载员工条目
        ui->staffListWidget->clear();
        QListWidgetItem *item = new QListWidgetItem;
        ui->staffListWidget->addItem(item);

        QSize size(500,40);
        item->setSizeHint(size);
        staffInfoBar *staffBar = new staffInfoBar;
        ui->staffListWidget->setItemWidget(item,staffBar);

        initStaffItem();

        ui->addStaffButton->setEnabled(true);
        ui->delStaffButton->setEnabled(true);
    }
    if(arg1 == "货物管理")
        {
        // 关闭员工管理功能
        ui->addStaffButton->setEnabled(false);
        ui->delStaffButton->setEnabled(false);

        // 开启货物管理功能，清空员工条目,加载货物
        ui->staffListWidget->clear();

        // 增加一个商品信息栏
        QListWidgetItem *item = new QListWidgetItem;
        ui->staffListWidget->addItem(item);
        QSize size(500,40);
        item->setSizeHint(size);
        goodsItemsInfo *goodsBar = new goodsItemsInfo;
        ui->staffListWidget->setItemWidget(item,goodsBar);


        ui->goodsListButton->setEnabled(true);
        ui->buyGoodsButton->setEnabled(true);
        initGoodsData();
    }
}

/* 连接添加用户槽函数*/
void adminWindow::getStaffInfo(const QString &account, const QString &passwd)
{

    // 创建条目对象
    QListWidgetItem *item = new QListWidgetItem;
    ui->staffListWidget->addItem(item);

    // 使用自定义控件
    staffitem *staffInfo = new staffitem;

    // 将新用户名和密码加入链表和条目
    Staff staff(QString::number(number).toStdString(),account.toStdString(),passwd.toStdString());
    staffList->append(staff);

    staffInfo->setstaffinfo(QString::number(number),account,passwd);
    QSize size(500,40);
    item->setSizeHint(size);

    // 关联自定义空间
    ui->staffListWidget->setItemWidget(item,staffInfo);

    // 保存新员工的数据到文件
    saveStaffInfo(QString::number(number++),account,passwd,true);
}

/* 添加货物槽函数 */
void adminWindow::getGoodsInfo(const QString &name, const QString &kind,
                               int purchasingPrice, int retailPrice,
                               int quentityStock)
{
    // 将信息存入货物链表
    Goods goods;
    goods.setNameGoods(name.toStdString());
    goods.setKingGoods(kind.toStdString());
    goods.setPurchasingPrice(purchasingPrice);
    goods.setRetailPrice(retailPrice);
    goods.setQuentityStcok(quentityStock);

    goodsList.append(goods);
    // 创建条目对象
    QListWidgetItem *item = new QListWidgetItem;

    ui->staffListWidget->addItem(item);

    goodsitem *goodsInfo = new goodsitem;
    goodsInfo->setGoodsInfo(name,kind,purchasingPrice,retailPrice,quentityStock);

    // 关联条目
    QSize size(500,40);
    item->setSizeHint(size);
    ui->staffListWidget->setItemWidget(item,goodsInfo);

    // 保存数据
    saveGoodsData(goods);
}

/* 货物列表数据 */
void adminWindow::on_goodsListButton_clicked()
{

}

/* 购买货物 */ /*1.实物图 2. 商品名称 3.商品的种类 4.商品的进价 5.商品的零售价 6商品的库存 */
void adminWindow::on_buyGoodsButton_clicked()
{
    // 打开采购货物窗口
    addGoodsWindow *goodswin = new addGoodsWindow(this);
    connect(goodswin,&addGoodsWindow::addGoodsInfo,this,&adminWindow::getGoodsInfo);
    goodswin->show();
}

/*读取Goods的文本数据 */
void adminWindow::goodsReadFile()
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


void adminWindow::on_retuenLoginButton_clicked()
{
    loginWindow *loginMeun = new loginWindow;
    loginMeun->show();
    this->close();
}

/* 修改后的信息 */
void adminWindow::rcvStaffMeg(const QString &number, const QString &account, const QString &passwd)
{
    qDebug()<<account;
}


