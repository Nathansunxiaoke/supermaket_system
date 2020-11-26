#include "addgoodswindow.h"
#include "ui_addgoodswindow.h"
#include <QtDebug>
addGoodsWindow::addGoodsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addGoodsWindow)
{
    ui->setupUi(this);
}

addGoodsWindow::~addGoodsWindow()
{
    delete ui;
}

void addGoodsWindow::on_addGoodsButton_clicked()
{
    // 货物采购的货物信息
    QString nameGoods = ui->namegGoodsLineEdit->text();
    QString kindGoods = ui->kindGoodsLineEdit->text();
    int purchasingPrice = ui->purchasingPriceLineEdit->text().toInt();
    int retailPrice = ui->retailPriceLineEdit->text().toInt();
    int quentityStock = ui->quentityStcokLineEdit->text().toInt();

    if(nameGoods == "" || kindGoods == "" || purchasingPrice < 0 || retailPrice <0 || quentityStock == 0)
    {
        // 提示录入信息不全
        QMessageBox::warning(this,"添加货物信息","录入信息有误");
        return ;
    }
    qDebug()<<nameGoods;

    emit(addGoodsInfo(nameGoods,kindGoods,purchasingPrice,retailPrice,quentityStock));
    this->close();
}


