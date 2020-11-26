#include "buygoods.h"

buyGoods::buyGoods()
{

}

string buyGoods::getBuyGoodsName() const
{
    return buyGoodsName;
}

void buyGoods::setBuyGoodsName(const string &value)
{
    buyGoodsName = value;
}

int buyGoods::getCount() const
{
    return count;
}

void buyGoods::setCount(int value)
{
    count = value;
}

int buyGoods::getBuyprice() const
{
    return buyprice;
}

void buyGoods::setBuyprice(int value)
{
    buyprice = value;
}
