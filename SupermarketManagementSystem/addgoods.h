#ifndef ADDGOODS_H
#define ADDGOODS_H

#include <QWidget>

namespace Ui {
class addGoods;
}

class addGoods : public QWidget
{
    Q_OBJECT

public:
    explicit addGoods(QWidget *parent = nullptr);
    ~addGoods();

private slots:
    void on_addGoodsButton_clicked();

private:
    Ui::addGoods *ui;
};

#endif // ADDGOODS_H
