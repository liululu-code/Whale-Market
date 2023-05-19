#ifndef SELLER_H_
#define SELLER_H_

// #include "baseUser.h"
#include "config.h"
#include "good.h"

using namespace LLL;

class Seller
{
private:
    /* data */
public:
    Seller();
    ~Seller();

    //基本功能
    bool PublishGood(Good & gd) const;
    void ViewAllPublishedGood(const string & sellerID) const;
    bool ModifyPublishedGoodInfo(const string & sellerID, const Good & oldGood, const Good & newGood) const;
    bool WithdrawPublishedGood(const string & id) const;
    void ViewOrderHistory(const string & sellerID) const;

};






#endif