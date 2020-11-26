#ifndef GOODSITEMSINFO_H
#define GOODSITEMSINFO_H

#include <QWidget>

namespace Ui {
class goodsItemsInfo;
}

class goodsItemsInfo : public QWidget
{
    Q_OBJECT

public:
    explicit goodsItemsInfo(QWidget *parent = nullptr);
    ~goodsItemsInfo();

private:
    Ui::goodsItemsInfo *ui;
};

#endif // GOODSITEMSINFO_H
