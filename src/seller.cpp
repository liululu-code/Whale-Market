#include "..\\include\\seller.h"
#include "..\\include\\namespace.h"



Seller::Seller()
{

}

Seller::~Seller()
{
    
}
//基本功能
bool Seller::PublishGood(Good & gd) const
{
    gdm.PublishGood(gd);
    return true;   
}
void Seller::ViewAllPublishedGood(const string & sellerID) const
{
    gdm.ViewAllPublishedGood(sellerID);
}
bool Seller::ModifyPublishedGoodInfo(const string & sellerID, const Good & oldGood, const Good & newGood) const
{
    return true;    
    gdm.ModifyPublishedGoodInfo(sellerID, oldGood, newGood);
}
bool Seller::WithdrawPublishedGood(const string & id) const
{
    gdm.WithdrawPublishedGood(id);
    return true;
}
void Seller::ViewOrderHistory(const string & sellerID) const
{
    odm.ViewSellerOrder(sellerID);   
}