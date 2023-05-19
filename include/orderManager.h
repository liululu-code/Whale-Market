#ifndef ORDERMANAGER_H_
#define ORDERMANAGER_H_

#include "config.h"
#include "order.h"

using namespace LLL;

class OrderManager
{
private:
    /* data */
    static vector<Order> orderList;
public:
    OrderManager() {};
    ~OrderManager() {};


    bool ReadFromFile(const string & fileName = ORDER_FILE_NAME);
    bool WriteToFile(const string & fileName = ORDER_FILE_NAME) const;


    bool AddOrder(Order & odr);
    // bool DeleteOrder(const string & id);
    // bool ModifyOrder(Order & oldOrder, Order & newOrder);
    void ViewAllOrder() const;
    void ViewSellerOrder(const string & sellerID) const;
    void ViewBuyerOrder(const string & buyerID) const;

};
extern OrderManager odm;



#endif