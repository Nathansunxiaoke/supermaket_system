#include "commodity.h"
#include "ui_commodity.h"

commodity::commodity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::commodity)
{
    ui->setupUi(this);
}

commodity::~commodity()
{
    delete ui;
}

/* 设置商品属性 */
void commodity::setCommodityInfo(const QString &name, const QString &kind, const int &price, const int &count)
{
    ui->nameLabel->setText(name);
    ui->kindLabel->setText(kind);
    ui->priceLabel->setText(QString::number(price));
    ui->countLabel->setText(QString::number(count));
}
