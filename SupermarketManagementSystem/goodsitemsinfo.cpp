#include "goodsitemsinfo.h"
#include "ui_goodsitemsinfo.h"

goodsItemsInfo::goodsItemsInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::goodsItemsInfo)
{
    ui->setupUi(this);
    // 固定条目大小
    this->setFixedSize(this->width(),this->height());
}

goodsItemsInfo::~goodsItemsInfo()
{
    delete ui;
}
