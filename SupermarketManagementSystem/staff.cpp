#include "staff.h"

Staff::Staff()
{

}

Staff::Staff(const string& number,const string& account,const string& passwd):
    number(number),
    account(account),
    passwd(passwd)
{

}

string Staff::getAccount() const
{
    return account;
}

void Staff::setAccount(const string &value)
{
    account = value;
}

string Staff::getPasswd() const
{
    return passwd;
}

void Staff::setPasswd(const string &value)
{
    passwd = value;
}

string Staff::getNumber() const
{
    return number;
}

void Staff::setNumber(const string &value)
{
    number = value;
}
