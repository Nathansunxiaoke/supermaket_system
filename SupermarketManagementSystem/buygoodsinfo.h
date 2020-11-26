#ifndef BUYGOODSINFO_H
#define BUYGOODSINFO_H

#include <QWidget>

namespace Ui {
class BuyGoodsInfo;
}

class BuyGoodsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit BuyGoodsInfo(QWidget *parent = nullptr);
    ~BuyGoodsInfo();
public:
    /* 设置商品信息 */
    void setGoodsInfo(const QString& name,const int& count);
private:
    Ui::BuyGoodsInfo *ui;
};

#endif // BUYGOODSINFO_H
