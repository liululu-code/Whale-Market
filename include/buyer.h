#ifndef BUYER_H_
#define BUYER_H_

#include "config.h"
#include "good.h"



using namespace LLL;

class Buyer
{
private:
    double m_balance;
public:
    Buyer();
    // Buyer(const Buyer & byr);
    // const Buyer & operator=(const Buyer & byr);
    ~Buyer();

    double getBalance() const {return m_balance;}
    bool setBalance(double balance) {m_balance = balance; return true;}

    //基本功能
    void ViewAllGood() const;
    bool BuyGood(const string & buyerID, const string & goodID) const;
    bool SearchGood(string & goodName) const;
    void ViewOrderHistory(const string & buyerID) const;
    void ViewGoodInformation(const string & goodID);
};




#endif