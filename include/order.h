#ifndef ORDER_H_
#define ORDER_H_

#include "config.h"


using namespace LLL;

class Order
{
private:
    char * m_ID;
    char * m_goodID;
    double m_price;
    string m_creatTime;
    string m_sellerID;
    string m_buyerID;
public:
    Order();
    Order(string & ID, string & goodID, const double price, const string & createTime, const string & sellerID, const string & buyerID);
    Order(const Order & odr);
    Order & operator=(const Order & odr);
    ~Order();

    const string & getSellerID() const {return m_sellerID;}
    const string & getBuyerID() const { return m_buyerID; }

    Order & ReadAOrderFromFile(ifstream & fin);
    void Show() const;
    bool Write(ofstream & fout) const;

};







#endif