#include "addgoods.h"
#include "ui_addgoods.h"

addGoods::addGoods(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addGoods)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

addGoods::~addGoods()
{
    delete ui;
}

/* 完成货物添加 */
void addGoods::on_addGoodsButton_clicked()
{

}
