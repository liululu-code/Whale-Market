#ifndef USER_H_
#define USER_H_

#include "config.h"
#include "baseUser.h"

class Admin : public BaseUser
{
private:
    ;
protected:
    Admin & ReadALineFromFile(ifstream & fin);

    ;
public:
    Admin();
    ~Admin();

    // bool SearchAllGoodByString(const string & subString = "NULL", const serialNum n = serialNum::ALL) const;


    void ViewAllUser();
    bool DeleteUser(const string & subString);
    void ViewAllGood() const;
    bool SearchAllGood(const string & subString, const Good::serialNum n) const;
    void WithdrawGood(const string & subString) const;
    void ViewAllOrder() const;

    ;
};


class User : public BaseUser
{
public:
    enum class user{
        BALANCE_MAX = 10000,
        BALANCE_MIN = -100
    };
private:
    double m_balance;

protected:

    ;
public:
    User();
    ~User();



    User & ReadALineFromFile(ifstream & fin);
    string getName() const;
    string getPassword() const;
    string getID() const;

    /**
     * 
     * 
    */
    bool Recharge(const double money);
    
    bool ModifyInformation(const serialNum n, const string & modifyString);
    void ViewInformation() const;
    
    void ViewAllGoodForBuyer() const;
    bool SearchAllGoodForBuyer(const string & subString) const;
    bool BuyGood(const string & subString) const;
    void ViewGoodInfo(const string & subString) const;

    void ViewOrderHistoryForBuyer(const string & subString) const;


    bool PublichGood(Good & gd) const;
    bool ModifyGoodInfo(const string & subString, const Good::serialNum n, const string & modifyString) const;
    void ViewAllGoodForSeller(const string & subString) const;
    bool WithdrawGoodForSeller(const string & subString) const;

    void ViewOrderHistoryForSeller(const string & subString) const;


    friend ostream & operator<<(ostream & os, const User & usr);
    friend ofstream & operator<<(ofstream & ofs, const User & usr);

    ;
};

#endif