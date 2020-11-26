#ifndef BUYGOODS_H
#define BUYGOODS_H
#include <iostream>

using namespace std;

class buyGoods
{
public:
    buyGoods();

    string getBuyGoodsName() const;
    void setBuyGoodsName(const string &value);

    int getCount() const;
    void setCount(int value);

    int getBuyprice() const;
    void setBuyprice(int value);

private:
    string buyGoodsName;  // 购买的名称
    int buyprice;         // 买的价格
    int count;            // 购买数量
};

#endif // BUYGOODS_H
