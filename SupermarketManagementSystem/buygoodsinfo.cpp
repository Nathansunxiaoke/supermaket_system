#include "buygoodsinfo.h"
#include "ui_buygoodsinfo.h"

BuyGoodsInfo::BuyGoodsInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyGoodsInfo)
{
    ui->setupUi(this);
}

BuyGoodsInfo::~BuyGoodsInfo()
{
    delete ui;
}

/* 设置商品信息 */
void BuyGoodsInfo::setGoodsInfo(const QString &name, const int &count)
{
    ui->buyNameLabel->setText(name);
    ui->buyCountLabel->setText(QString::number(count));
}
