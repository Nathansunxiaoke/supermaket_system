#include "staffinfobar.h"
#include "ui_staffinfobar.h"

staffInfoBar::staffInfoBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::staffInfoBar)
{
    ui->setupUi(this);
}

staffInfoBar::~staffInfoBar()
{
    delete ui;
}
