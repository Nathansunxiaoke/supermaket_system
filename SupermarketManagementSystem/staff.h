#ifndef STAFF_H
#define STAFF_H
#include <iostream>
using namespace  std;

class Staff
{
public:
    Staff();
    Staff(const string& number,const string& account,const string& passwd);

    string getAccount() const;
    void setAccount(const string &value);

    string getPasswd() const;
    void setPasswd(const string &value);

    string getNumber() const;
    void setNumber(const string &value);

private:
    string number;    // 编号
    string account;   // 账号
    string passwd;    // 密码
};

#endif // STAFF_H
