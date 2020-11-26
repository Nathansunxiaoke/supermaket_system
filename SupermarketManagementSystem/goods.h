#ifndef GOODS_H
#define GOODS_H
#include<iostream>

using namespace std;

class Goods
{
public:
    Goods();

    string getNameGoods() const;
    void setNameGoods(const string &value);

    string getKingGoods() const;
    void setKingGoods(const string &value);

    int getQuentityStcok() const;
    void setQuentityStcok(int value);

    int getPurchasingPrice() const;
    void setPurchasingPrice(int value);

    int getRetailPrice() const;
    void setRetailPrice(int value);

private:
    string nameGoods;        // 货物名称
    string kingGoods;        // 货物的种类
    int purchasingPrice;  // 货物进价
    int retailPrice;      // 货物的零售价
    int quentityStcok;       // 货物数量
};

#endif // GOODS_H
