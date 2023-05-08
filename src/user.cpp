#include <iostream>
#include <fstream>

#include "user.h"


using std::ifstream;
using std::endl;
using std::cout;
using std::ofstream;
using std::ifstream;

Admin::Admin() : BaseUser()
{

}

Admin::~Admin()
{

}

void Admin::ViewAllUser()
{
    // BaseUser::ViewInformation();
    User usr;
    ifstream fin(USER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    usr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        cout << usr;

        usr.ReadALineFromFile(fin);
    }
    fin.close();

}





Admin & Admin::ReadALineFromFile(ifstream & fin)
{
    string balance;
    fin.getline(m_ID, int(size::ID) + 1, ',');
    fin.getline(m_name, int(size::NAME) + 1, ',');
    getline(fin, m_telephone, ',');
    getline(fin, m_address, ',');
    getline(fin, m_password, ',');
    getline(fin, balance, '\n');
    return *this;
}

bool Admin::DeleteUser(const string & subString)
{
    ifstream fin(USER_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }

    char outputFileName[L_tmpnam];
    tmpnam(outputFileName);
    // cout << outputFileName << endl;
    ofstream fout(string(outputFileName), std::ios_base::out);
    if (!fout.is_open())
    {
        cout << "Can't open file " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }
    ReadALineFromFile(fin);
    while (!fin.eof())
    {
        

        if (!strcmp(m_ID, subString.c_str()))
        {
            cout << "已删除" << endl;
            ReadALineFromFile(fin);
            continue;
        }
        
        fout << *this;

        ReadALineFromFile(fin);
    }

    fin.close();
    fout.close();

    remove("..\\user.txt");
    if (!rename(outputFileName, "..\\user.txt"))
    {
        #ifdef DEBUG
            cout << "rename success" << endl; 
        #endif
    }
    else
    {
        #ifdef DEBUG
            cout << "rename fault" << endl;
        #endif
    }
    return true;
}
void Admin::ViewAllGood() const
{
    Good gd;
    gd.ViewAllGood();
}
bool Admin::SearchAllGood(const string & subString, const Good::serialNum n) const
{
    Good gd;
    gd.SearchAllGoodByString(subString, n);
    return true;
}
void Admin::WithdrawGood(const string & subString) const
{
    Good gd;
    gd.WithdrawGood(subString);
}
void Admin::ViewAllOrder() const
{
    Order odr;
    odr.ViewAllOrder();
}





User::User() : BaseUser(), m_balance(0)
{

}

User::~User()
{
    
}

string User::getName() const
{
    return m_name;
}
string User::getPassword() const
{
    return m_password;
}
string User::getID() const
{
    return m_ID;
}



User & User::ReadALineFromFile(ifstream & fin)
{
    string balance;
    fin.getline(m_ID, int(size::ID) + 1, ',');
    fin.getline(m_name, int(size::NAME) + 1, ',');
    getline(fin, m_telephone, ',');
    getline(fin, m_address, ',');
    getline(fin, m_password, ',');
    getline(fin, balance, '\n');
    m_balance = strtod(balance.c_str(), nullptr);
    return *this;
}

bool User::ModifyInformation(const serialNum n, const string & modifyString)
{
    ifstream fin(USER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    char outputFileName[L_tmpnam];
    tmpnam(outputFileName);
    cout << outputFileName << endl;
    ofstream fout(string(outputFileName), std::ios_base::out);
    if (!fout.is_open())
    {
        cout << "Can't open file " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }
    User usr;
    usr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        if (!strcmp(usr.m_ID, m_ID))
        {
            switch (n)
            {
            case serialNum::ID:
                strcpy(usr.m_ID, modifyString.c_str());
                break;
            case serialNum::NAME:
                strcpy(usr.m_name, modifyString.c_str());
                break;
            case serialNum::TELEPHONE:
                usr.m_telephone = modifyString;
                break;
            case serialNum::ADDRESS:
                usr.m_address = modifyString;
                break;
            case serialNum::PASSWORD:
                usr.m_password = modifyString;
                break;
            default:
                break;
            }
        }
        
        fout << usr;
        usr.ReadALineFromFile(fin);
    }

    fin.close();
    fout.close();

    remove("..\\user.txt");
    if (!rename(outputFileName, "..\\user.txt"))
    {
        #ifdef DEBUG
            cout << "newUser rename success" << endl; 
        #endif
    }
    else
    {
        #ifdef DEBUG
            cout << "newUser rename fault" << endl;
        #endif
    }
    
    return true;
}

void User::ViewInformation() const
{
    ifstream fin(USER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    User usr;
    usr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        if (!strcmp(usr.m_ID, this->m_ID))
        {
            cout << usr;
            break;
        }
        usr.ReadALineFromFile(fin);
    }
    fin.close();
}



bool User::Recharge(const double money)
{
    ifstream fin(USER_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    User usr;
    char outputFileName[L_tmpnam];
    tmpnam(outputFileName);
    // cout << outputFileName << endl;
    ofstream fout(string(outputFileName), std::ios_base::out);
    if (!fout.is_open())
    {
        cout << "Can't open file " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }
    usr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        if (!strcmp(m_ID, usr.m_ID))
        {
            usr.m_balance += money;
        }
        fout << usr;
        usr.ReadALineFromFile(fin);

    }

    fin.close();
    fout.close();

    remove("..\\user.txt");
    if (!rename(outputFileName, "..\\user.txt"))
    {
        #ifdef DEBUG
            cout << "rename success" << endl; 
        #endif
    }
    else
    {
        #ifdef DEBUG
            cout << "rename fault" << endl;
        #endif
    }
    return true;
}
void User::ViewAllGoodForBuyer() const
{
    Good gd;
    gd.SearchAllGoodByString("销售中", Good::serialNum::STATE);
}
bool User::SearchAllGoodForBuyer(const string & subString) const
{
    Good gd;
    gd.SearchAllGoodByString(subString, Good::serialNum::NAME);
    return true;
}
bool User::BuyGood(const string & subString) const
{
    return true;
}
void User::ViewGoodInfo(const string & subString) const
{
    Good gd;
    gd.ViewGoodInfo(subString);
}
void User::ViewOrderHistoryForBuyer(const string & subString) const
{
    Order odr;
    odr.SearchAllOrderByString(subString, Order::serialNum::ID_BUYER);
}
bool User::PublichGood(Good & gd) const
{
    gd.PublichGood();
    return true;
}
bool User::ModifyGoodInfo(const string & subString, const Good::serialNum n, const string & modifyString) const
{
    Good gd;
    gd.ModifyGood(subString, n, modifyString);
    return true;
}
void User::ViewAllGoodForSeller(const string & subString) const
{
    Good gd;
    gd.SearchAllGoodByString(subString, Good::serialNum::SELLER_ID);
}
bool User::WithdrawGoodForSeller(const string & subString) const
{
    Good gd;
    gd.WithdrawGood(subString);
    return true;
}
void User::ViewOrderHistoryForSeller(const string & subString) const
{
    Order odr;
    odr.SearchAllOrderByString(subString, Order::serialNum::ID_SELLER);
}

ostream & operator<<(ostream & os, const User & usr)
{
    os << usr.m_ID << "     " << usr.m_name << "     " << usr.m_telephone << "     " << usr.m_address << "     " << usr.m_balance << endl; 
    return os;
}

ofstream & operator<<(ofstream & ofs, const User & usr)
{
    ofs << usr.m_ID << ',' << usr.m_name << ',' << usr.m_telephone << ',' << usr.m_address << ',' << usr.m_password << ',' << usr.m_balance << endl;
    return ofs;
}
