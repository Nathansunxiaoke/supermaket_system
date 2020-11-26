#include "goods.h"

Goods::Goods()
{

}

string Goods::getNameGoods() const
{
    return nameGoods;
}

void Goods::setNameGoods(const string &value)
{
    nameGoods = value;
}

string Goods::getKingGoods() const
{
    return kingGoods;
}

void Goods::setKingGoods(const string &value)
{
    kingGoods = value;
}


int Goods::getQuentityStcok() const
{
    return quentityStcok;
}

void Goods::setQuentityStcok(int value)
{
    quentityStcok = value;
}

int Goods::getPurchasingPrice() const
{
    return purchasingPrice;
}

void Goods::setPurchasingPrice(int value)
{
    purchasingPrice = value;
}

int Goods::getRetailPrice() const
{
    return retailPrice;
}

void Goods::setRetailPrice(int value)
{
    retailPrice = value;
}
