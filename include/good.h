#ifndef GOOD_H_
#define GOOD_H_
//  ID，时间    SIZE应该始终保持一致，可考虑移动到一个文件

#include <string>
#include <cstring>
#include <iostream>

// #include "user.h"

using std::string;
using std::ostream;
using std::ifstream;
using std::ofstream;

class Good
{
public:
    enum class size{
        ID = 6, 
        NAME = 30, 
        PRICE = 6,
        DESCRIPTION = 300, 
        SELLER = 6, 
        AVAILABLE_TIME = 10,
        STATE = 9,
    };
    enum class serialNum{
        ID, NAME, PRICE, DECRIPTION, SELLER_ID, AVAILABLE_TIME, STATE, ALL
    };
private:
    char * m_ID;
    char * m_name;
    double m_price;
    string m_description;
    string m_sellerID;
    string m_availableTime;
    string m_state;

    ;
protected:

    ostream & inter(ostream & os, const char * cstr, const int fillLength) const;
    const string doubleToString(const double num, const int precision) const;
    const Good & ReadALineFromFile(ifstream & fin);
    // bool Good::WriteToFile(ofstream ) const;
    ;
public:
    Good();
    // Good(char * name, double price, string description);
    Good(const Good & gd);
    Good & operator=(const Good & gd);
    ~Good();


    void Test();
    bool setName(const string & name);
    bool setPrice(const double price);
    bool setDescription(const string & description);
    bool setPublisher(const string & sellerID);
    bool setState(const string & state);



    //成员方法组织方式有大问题,应该针对一个Good,而不是整个商品的操作.将文件操作与单个商品分离开
    //问题:很多方法不知道放到哪个类中,像发布商品,是User类,还是Good类
    //暂时不考虑这些,先把功能实现
    //单个成员方法
    // void SingleViewGoodInfo() const;
    // Good & SingleModifyGood(const serialNum n);
    // Good & SingleWithdrawGood();


    bool setID();
    void ViewAllGood() const;
    // void ViewAllGoodByString(const string & subString, const serialNum n) const;
    bool SearchAllGoodByString(const string & subString = "NULL", const serialNum n = serialNum::ALL) const;
    bool WithdrawGood(const string & subString) const;
    void ViewGoodInfo(const string & subString) const;
    bool ModifyGood(const string & subString, const serialNum n, const string & modifyString) const;
    bool PublichGood() const;
    bool BuyerGood(const string & subString, const string & userID) const;


    // ostream & inter(ostream & os, char * cstr, int fillLength);
    const Good & operator<<(ostream & os) const;
    friend ostream & operator<<(ostream & os, const Good & gd);

    bool operator<<(ofstream & fout) const;
    friend ofstream & operator<<(ofstream & fout, const Good &gd);

    ;
};



#endif