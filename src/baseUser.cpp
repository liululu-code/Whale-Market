#include "baseUser.h"
#include <iostream>
#include <ostream>
#include <cstring>
#include <fstream>



using std::strcpy;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::strcmp;

BaseUser::BaseUser()
{
    m_ID = new char [int(size::ID) + 1];
    m_name = new char [int(size::NAME) + 1];
    strcpy(m_ID, "NULL");
    strcpy(m_name, "NULL");
    m_password = "NULL";
    m_telephone = "NULL";
    m_address = "NULL";
}

BaseUser::BaseUser(const BaseUser & bsUsr)
{
    m_ID = new char [int(BaseUser::size::ID) + 1];
    m_name = new char [int(BaseUser::size::NAME) + 1];
    strcpy(m_ID, bsUsr.m_ID);
    strcpy(m_name, bsUsr.m_name);
    m_password = bsUsr.m_password;
    m_telephone = bsUsr.m_telephone;
    m_address = bsUsr.m_address;
    #ifdef DEBUG
        cout << "Call BaseUser copy constructor function." << endl;
    #endif
}

BaseUser::~BaseUser()
{
    delete [] m_ID;
    delete [] m_name;
}

BaseUser & BaseUser::operator=(const BaseUser & bsUsr)
{
    if (this == &bsUsr)
    {
        return *this;
    }
    delete [] m_ID;
    delete [] m_name;
    m_ID = new char [int(BaseUser::size::ID) + 1];
    m_name = new char [int(BaseUser::size::NAME) + 1];
    strcpy(m_ID, bsUsr.m_ID);
    strcpy(m_name, bsUsr.m_name);
    m_password = bsUsr.m_password;
    m_telephone = bsUsr.m_telephone;
    m_address = bsUsr.m_address;
    #ifdef DEBUG
        cout << "Call BaseUser copy constructor function." << endl;
    #endif
    return *this;
}

const BaseUser & BaseUser::ReadALineFromFile(ifstream & fin)
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

bool BaseUser::SearchAllOrderByString(const string & subString, const serialNum n)
{
    ifstream fin(USER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        switch (n)
        {
        case serialNum::ID:
            if (!strcmp(m_ID, subString.c_str()))
            {
                cout << *this;
            }
            break;
        case serialNum::NAME:
            if (!strcmp(m_name, subString.c_str()))
            {
                cout << *this;
            }
            break;
        case serialNum::TELEPHONE:
            if (m_telephone == subString)
            {
                cout << *this;
            }
            break;
        case serialNum::ADDRESS:
            if (m_address == subString)
            {
                cout << *this;
            }
            break;
        case serialNum::PASSWORD:
            if (m_password == subString)
            {
                cout << *this;
            }
            break;
        case serialNum::ALL:
                cout << *this;
            break;
        default:
            break;
        }
        ReadALineFromFile(fin);
    }
    fin.close();
    return true;
}

bool BaseUser::ModifyInformation(const string & subString, const serialNum n, const string & modifyString)
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
    ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        switch (n)
        {
        case serialNum::ID:
            strcpy(m_ID, modifyString.c_str());
            break;
        case serialNum::NAME:
            strcpy(m_name, modifyString.c_str());
            break;
        case serialNum::TELEPHONE:
            m_telephone = modifyString;
            break;
        case serialNum::ADDRESS:
            m_address = modifyString;
            break;
        case serialNum::PASSWORD:
            m_password = modifyString;
            break;
        default:
            break;
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

void BaseUser::ViewInformation()
{
    SearchAllOrderByString(this->m_ID, serialNum::ID);
}

void BaseUser::ViewGood(const string & subString, const Good::serialNum n) const
{
    Good gd;
    gd.SearchAllGoodByString(subString, n);
}

void BaseUser::ViewOrder(const string & subString, const Order::serialNum n) const
{
    Order odr;
    odr.SearchAllOrderByString(subString, n);
}


std::ostream & operator<<(std::ostream & os, const BaseUser & u)
{
    using std::endl;
    os << "用户名：" << u.m_name << endl;
    os << "联系方式：" << u.m_telephone << endl;
    os << "地址：" << u.m_address << endl;
    return os;
}

std::ofstream & operator<<(std::ofstream & os, const BaseUser & bsUsr)
{
    os << bsUsr.m_ID << ',' << bsUsr.m_name << ',' << bsUsr.m_telephone << ',' << bsUsr.m_address << ',' << bsUsr.m_password << endl;
    return os;
}





