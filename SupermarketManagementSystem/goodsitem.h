#ifndef GOODSITEM_H
#define GOODSITEM_H

#include <QWidget>

namespace Ui {
class goodsitem;
}

class goodsitem : public QWidget
{
    Q_OBJECT

public:
    explicit goodsitem(QWidget *parent = nullptr);
    ~goodsitem();

    void setGoodsInfo(const QString& nameGoods,const QString& kindGoods,
                      int purchasingPrice,int retailPrce,
                      int quentityStock);
private:
    Ui::goodsitem *ui;
};

#endif // GOODSITEM_H
