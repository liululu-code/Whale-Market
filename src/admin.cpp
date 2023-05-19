

#include "..\\include\\admin.h"
#include "..\\include\\namespace.h"

Admin::Admin()
{

}

Admin::~Admin()
{
    
}

    //基本功能
void Admin::ViewAllGood() const
{
    gdm.ViewAllGood();
}
void Admin::SearchGood(const string & goodName) const
{
    gdm.SearchGood(goodName);
}
void Admin::ViewAllOrder() const
{
    odm.ViewAllOrder();
}
void Admin::ViewAllUser() const
{
    usrm.ViewAllUser();
}
bool Admin::DeleteUser(const string & userID) const
{
    usrm.DeleteUser(userID);
    return true;
}
void Admin::WithdrawGood(const string & goodID)
{
    gdm.WithdrawPublishedGood(goodID);
}
