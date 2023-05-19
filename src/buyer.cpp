

#include "..\\include\\buyer.h"
#include "..\\include\\namespace.h"

Buyer::Buyer(/* args */)
{
    
}
// Buyer::Buyer(const Buyer & byr)
// {
    
// }
// const Buyer & Buyer::operator=(const Buyer & byr)
// {
//     return byr;
// }
Buyer::~Buyer()
{
    
}

//基本功能
void Buyer::ViewAllGood() const
{
    gdm.ViewAllOnsellGood();
}
bool Buyer::BuyGood(const string & buyerID, const string & goodID) const
{
    gdm.BuyGood(buyerID, goodID);
    return true;
}
bool Buyer::SearchGood(string & goodName) const
{
    gdm.SearchGood(goodName);
    return true;
}
void Buyer::ViewOrderHistory(const string & buyerID) const
{
    odm.ViewBuyerOrder(buyerID);
}
void Buyer::ViewGoodInformation(const string & goodID)
{
    gdm.ViewGoodInformation(goodID);
}



