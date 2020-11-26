#include "shopbar.h"
#include "ui_shopbar.h"

shopBar::shopBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shopBar)
{
    ui->setupUi(this);
}

shopBar::~shopBar()
{
    delete ui;
}
