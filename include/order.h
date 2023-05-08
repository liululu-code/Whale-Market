#ifndef ORDER_H_
#define ORDER_H_

#include <string>

#include "config.h"

using std::string;
using std::ostream;
using std::ifstream;

class Order
{
public:
    enum class size{
        ID_ORDER = 6,
        ID_GOOD = 6,
        TRADE_MONEY = 6,
        TRADE_TIME = 10,
        ID_SELLER = 6,
        ID_BUYER = 6
    };
    enum class serialNum{
        ID_ORDER, ID_GOOD, TRADE_PRICE, TRADE_TIME, ID_SELLER, ID_BUYER, ALL
    };
    ;
private:
    char * m_ID;
    char * m_goodID;
    double m_price;
    string m_time;
    string m_sellerID;
    string m_buyerID;

protected:
    
    ostream & inter(ostream & os, const char * cstr, const int fillLength) const;
    const string doubleToString(const double num, const int precision) const

    ;
public:
    Order();
    Order(char * ID, char * goodID, double price, const string & time, const string & sellerID, const string & buyerID);
    Order(const Order & odr);
    Order & operator=(const Order & odr);
    ~Order();


    const Order & ReadALineFromFile(ifstream & fin);

    bool setID();


    bool SearchAllOrderByString(const string & subString, const serialNum n);
    void ViewAllOrder() const;

    const Order & operator<<(ostream & os) const;
    friend ostream & operator<<(ostream & os, const Order & odr);

    friend std::ofstream & operator<<(std::ofstream & ofs, const Order & usr);

};

#endif