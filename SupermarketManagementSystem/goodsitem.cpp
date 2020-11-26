#include "goodsitem.h"
#include "ui_goodsitem.h"
#include <QtDebug>

goodsitem::goodsitem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goodsitem)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

goodsitem::~goodsitem()
{
    delete ui;
}

void goodsitem::setGoodsInfo(const QString &nameGoods, const QString &kindGoods,
                             int purchasingPrice, int retailPrce,
                             int quentityStock)
{
    ui->nameGoodeLabel->setText(nameGoods);
    ui->kindGoodsLabel->setText(kindGoods);
    ui->purchasingPriceLabel->setText(QString::number(purchasingPrice));
    ui->retailPriceLabel->setText(QString::number(retailPrce));
    ui->quantityStockLabel->setText(QString::number(quentityStock));
}
