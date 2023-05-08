#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "order.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::strcpy;
using std::setw;
using std::ostringstream;
using std::setprecision;



Order::Order()
{
    m_ID = new char [int(size::ID_ORDER) + 1];
    m_goodID = new char [int(size::ID_GOOD) + 1];
    strcpy(m_ID, "NULL");
    strcpy(m_goodID, "NULL");
    m_price = 0.0;
    m_time = "NULL";
    m_sellerID = "NULL";
    m_buyerID = "NULL";
}
Order::Order(char * ID, char * goodID, double price, const string & time, const string & sellerID, const string & buyerID)
{
    m_ID = new char [int(size::ID_ORDER) + 1];
    m_goodID = new char [int(size::ID_GOOD) + 1];
    strcpy(m_ID, ID);
    strcpy(m_goodID, goodID);
    m_price = price;
    m_time = time;
    m_sellerID = sellerID;
    m_buyerID = buyerID;
}

Order::Order(const Order & odr)
{
    m_ID = new char [int(size::ID_ORDER) + 1];
    m_goodID = new char [int(size::ID_GOOD) + 1];
    strcpy(m_ID, odr.m_ID);
    strcpy(m_goodID, odr.m_goodID);
    m_price = odr.m_price;
    m_time = odr.m_time;
    m_sellerID = odr.m_sellerID;
    m_buyerID = odr.m_buyerID;
}
Order & Order::operator=(const Order & odr)
{
    if (this == &odr)
    {
        return *this;
    }
    delete [] m_ID;
    delete [] m_goodID;
    m_ID = new char [int(size::ID_ORDER) + 1];
    m_goodID = new char [int(size::ID_GOOD) + 1];
    strcpy(m_ID, odr.m_ID);
    strcpy(m_goodID, odr.m_goodID);
    m_price = odr.m_price;
    m_time = odr.m_time;
    m_sellerID = odr.m_sellerID;
    m_buyerID = odr.m_buyerID;
    return *this;
}
Order::~Order()
{
    delete [] m_ID;
    delete [] m_goodID;
}

bool Order::setID()
{
    ifstream fin(ORDER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << ORDER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    char id[int(size::ID_ORDER) + 1] = {0};
    Order odr;
    odr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        if (strcmp(odr.m_ID, id) > 0)
        {
            strcpy(id, odr.m_ID);
        }
        odr.ReadALineFromFile(fin);
    }
    fin.close();

    unsigned long idNum = strtoul(&id[1], NULL, 10);
    idNum++;
    strcpy(m_ID, ("T" + std::to_string(idNum)).c_str());
    
    return true;
}



const Order & Order::ReadALineFromFile(ifstream & fin)
{
    fin.getline(m_ID, int(size::ID_ORDER) + 1, ',');
    fin.getline(m_goodID, int(size::ID_GOOD) + 1, ',');
    (fin >> m_price).get();
    getline(fin, m_time, ',');
    getline(fin, m_sellerID, ',');
    getline(fin, m_buyerID, '\n');
    return *this;
}

bool Order::SearchAllOrderByString(const string & subString, const serialNum n)
{
    ifstream fin(ORDER_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << ORDER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Order odr;
    odr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        switch (n)
        {
        case serialNum::ID_ORDER:
            if (!strcmp(odr.m_ID, subString.c_str()))
            {
                cout << odr;
            }
            break;
        case serialNum::ID_GOOD:
            if (!strcmp(odr.m_goodID, subString.c_str()))
            {
                cout << odr;
            }
            break;
        case serialNum::TRADE_PRICE:
            if (odr.m_price == strtod(subString.c_str(), NULL))
            {
                cout << odr;
            }
            break;
        case serialNum::TRADE_TIME:
            if (odr.m_time == subString)
            {
                cout << odr;
            }
            break;
        case serialNum::ID_SELLER:
            if (odr.m_sellerID == subString)
            {
                cout << odr;
            }
            break;
        case serialNum::ID_BUYER:
            if (odr.m_buyerID == subString)
            {
                cout << odr;
            }
            break;
        case serialNum::ALL:
                cout << odr;
            break;
        default:
            break;
        }
        odr.ReadALineFromFile(fin);
    }
    fin.close();
    return true;
}

void Order::ViewAllOrder() const
{
    Order odr;
    odr.SearchAllOrderByString("M00001", serialNum::ALL);
}


ostream & Order::inter(ostream & os, const char * cstr, const int fillLength) const
{
    int fill = 2 * 3;           //边缘空格个数
    
    int i = 0, chinese = 0;                      //中文个数，用于补充命令行中中英文占位不同带来的对齐问题
    while (cstr[i] != '\0')
    {
        if (cstr[i++] < 0)
        {
            chinese++;
        }
    }
    chinese /= 3;
    int spaceLength = (fillLength + fill + chinese - strlen(cstr)) / 2;
    if ((fillLength + fill + chinese - strlen(cstr) + 1) / 2 == spaceLength)
    {
        os << setw(spaceLength) << "" << cstr << setw(spaceLength) << "" << "|";
    }
    else
    {
        os << setw(spaceLength) << "" << cstr << setw(spaceLength) << "" << " " << "|";
    }
    return os;
}

const string Order::doubleToString(const double num, const int precision) const
{
    ostringstream osstr;
    if (precision > 0)
    {
        osstr << std::fixed << setprecision(precision);
    }
    osstr << num;
    return osstr.str();
}

const Order & Order::operator<<(ostream & os) const
{
    inter(os, m_ID, int(size::ID_ORDER));
    inter(os, m_goodID, int(size::ID_GOOD));
    inter(os, doubleToString(m_price, 1).c_str(), int(size::TRADE_MONEY));
    inter(os, m_time.c_str(), int(size::TRADE_TIME));
    inter(os, m_sellerID.c_str(), int(size::ID_SELLER));
    inter(os, m_buyerID.c_str(), int(size::ID_BUYER));
    os << endl;
    return *this;
}
ostream & operator<<(ostream & os, const Order & odr)
{
    odr.operator<<(os);
    return os;
}


ofstream & operator<<(ofstream & ofs, const Order & usr)
{
    ofs << usr.m_ID << ',' << usr.m_goodID << ',' << usr.m_price << ',' << usr.m_time << ',' << usr.m_sellerID << ',' << usr.m_buyerID << endl;
    return ofs;
}

