#ifndef COMMODITY_H
#define COMMODITY_H

#include <QWidget>

namespace Ui {
class commodity;
}

class commodity : public QWidget
{
    Q_OBJECT

public:
    explicit commodity(QWidget *parent = nullptr);
    ~commodity();
public:
    /* 设置商品属性 */
    void setCommodityInfo(const QString& name,const QString& kind,const int& price,const int& count);
private:
    Ui::commodity *ui;
};

#endif // COMMODITY_H
