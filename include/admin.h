#ifndef ADMIN_H_
#define ADMIN_H_

#include "config.h"
#include "baseUser.h"

using namespace LLL;

class Admin : public BaseUser
{
private:
    /* data */

public:
    Admin();
    virtual ~Admin();
    

    virtual bool ModifyInformation() {return true;};
    virtual void ViewInformation() const {};

    //基本功能
    void ViewAllGood() const;
    void SearchGood(const string & goodName) const;
    void ViewAllOrder() const;
    void ViewAllUser() const;
    bool DeleteUser(const string & userID) const;
    void WithdrawGood(const string & goodID);


};




#endif