#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

#include "good.h"
#include "config.h"
#include "order.h"
#include "user.h"


using std::strcpy;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::setw;
using std::setfill;
using std::left;
using std::setprecision;
using std::ostringstream;
using std::tmpnam;

Good::Good()
{
    m_ID = new char [int(size::ID) + 1];
    m_name = new char [int(size::NAME) + 1];
    strcpy(m_ID, "NULL");
    strcpy(m_name, "NULL");
    m_price = 0.0;
    m_description = "NULL";
    m_sellerID = "NULL";
    m_availableTime = "NULL";
    m_state = "NULL";
}

// Good::Good(char * name, double price, string description)
// {
//     m_ID = new char [int(size::ID) + 1];
//     m_name = new char [int(size::NAME) + 1];
//     strcpy(m_ID, "NULL");
//     strcpy(m_name, name);
//     m_price = price;
//     m_description = description;
//     m_sellerID = "NULL";
//     m_availableTime = "NULL";
//     m_state = "NULL";
// }

Good::Good(const Good & gd)
{
    m_ID = new char [int(size::ID) + 1];
    m_name = new char [int(size::NAME) + 1];
    strcpy(m_ID, gd.m_ID);
    strcpy(m_name, gd.m_name);
    m_price = gd.m_price;
    m_description = gd.m_description;
    m_sellerID = gd.m_sellerID;
    m_availableTime = gd.m_availableTime;
    m_state = gd.m_state;
    #ifdef DEBUG
        cout << "Call Good copy structor.";
    #endif
}

Good & Good::operator=(const Good & gd)
{
    if (this == &gd)
    {
        return *this;
    }
    delete [] m_ID;
    delete [] m_name;
    m_ID = new char [int(size::ID) + 1];
    m_name = new char [int(size::NAME) + 1];
    strcpy(m_ID, gd.m_ID);
    strcpy(m_name, gd.m_name);
    m_price = gd.m_price;
    m_description = gd.m_description;
    m_sellerID = gd.m_sellerID;
    m_availableTime = gd.m_availableTime;
    m_state = gd.m_state;
    #ifdef DEBUG
        cout << "Call Good copy structor.";
    #endif
    return *this;
}

Good::~Good()
{
    delete [] m_ID;
    delete [] m_name;
}

void Good::Test()
{
    // ViewAllGood();
    // SearchAllGoodByString(u8"设计");
    // ViewAllGood();
    // WithdrawGood("M00004");
    // ViewGoodInfo("M00003");
    // ModifyGood("M00004", serialNum::PRICE, "55.5");
    // Good gd;
    // gd.PublichGood();
}

bool Good::setName(const string & name)
{
    strcpy(m_name, name.c_str());
    return true;
}
bool Good::setPrice(const double price)
{
    m_price = price;
    return true;
}
bool Good::setDescription(const string & description)
{
    m_description = description;
    return true;
}

bool Good::setPublisher(const string & sellerID)
{
    m_sellerID = sellerID;
    return true;
}
bool Good::setState(const string & state)
{
    m_state = state;
    return true;
}



bool Good::setID()
{
    ifstream fin(GOOD_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    char id[int(size::ID) + 1] = {0}, *pch = id;
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        if (strcmp(gd.m_ID, id) > 0)
        {
            strcpy(id, gd.m_ID);
        }
        gd.ReadALineFromFile(fin);
    }
    fin.close();

    unsigned long idNum = strtoul(&id[1], NULL, 10);
    idNum++;
    strcpy(m_ID, ("M" + std::to_string(idNum)).c_str());
    
    return true;
}


void Good::ViewAllGood() const
{
    // ifstream fin(GOOD_FILE_NAME);
    // if (!fin.is_open())
    // {
    //     cout << "Can't open file " << GOOD_FILE_NAME << endl;
    //     exit(EXIT_FAILURE);
    // }
    // Good gd;
    // while (!fin.eof())
    // {
    //     gd.ReadALineFromFile(fin);
    //     cout << gd;
    // }
    // fin.close();
    SearchAllGoodByString();
}
// void Good::ViewAllGoodByString(const string & subString, const serialNum n) const
// {

// }





const Good & Good::ReadALineFromFile(ifstream & fin)
{
    fin.getline(this->m_ID, int(size::ID) + 1, ',');
    fin.getline(this->m_name, int(size::NAME) + 1, ',');
    (fin >> this->m_price).get();
    getline(fin, this->m_availableTime, ',');
    getline(fin, this->m_sellerID, ',');
    getline(fin, this->m_state, '\n');
    return *this;
}

bool Good::SearchAllGoodByString(const string & subString, const serialNum n) const
{
    ifstream fin(GOOD_FILE_NAME);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        switch (n)
        {
        case serialNum::ID:
            if (!strcmp(gd.m_ID, subString.c_str()))
            {
                cout << gd;
            }
            break;
        case serialNum::NAME:
            if (string(gd.m_name).find(subString) != string::npos)
            {
                cout << gd;
            }
            break;
        case serialNum::PRICE:
            if (gd.m_price == strtod(subString.c_str(), NULL))
            {
                cout << gd;
            }
            break;
        case serialNum::AVAILABLE_TIME:
            if (gd.m_availableTime == subString)
            {
                cout << gd;
            }
            break;
        case serialNum::STATE:
            if (gd.m_state == subString)
            {
                cout << gd;
            }
            break;
        case serialNum::SELLER_ID:
            if (gd.m_sellerID == subString)
            {
                cout << gd;
            }
            break;
        case serialNum::ALL:
                cout << gd;
            break;
        default:
            break;
        }
        gd.ReadALineFromFile(fin);
    }
    fin.close();
    return true;
}

// bool Good::WriteToFile() const
// {
    
// }

bool Good::WithdrawGood(const string & subString) const
{
    ifstream fin(GOOD_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    char outputFileName[L_tmpnam];
    tmpnam(outputFileName);
    cout << outputFileName << endl;
    ofstream fout(string(outputFileName), std::ios_base::out);
    if (!fout.is_open())
    {
        cout << "Can't open file " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        if (!strcmp(gd.m_ID, subString.c_str()))
        {
            gd.m_state = u8"已下架";
        }
        fout << gd;
        gd.ReadALineFromFile(fin);
    }

    fin.close();
    fout.close();

    remove("..\\good.txt");
    if (!rename(outputFileName, "..\\good.txt"))
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
void Good::ViewGoodInfo(const string & subString) const
{
    ifstream fin(GOOD_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        if (!strcmp(gd.m_ID, subString.c_str()))
        {
            cout << setw(20) << std::left << "名称: " << gd.m_name << endl;
            cout << setw(20) << std::left << "描述: " << gd.m_description << endl;
            cout << setw(20) << std::left << "上架时间: " << gd.m_availableTime << endl;
            cout << setw(20) << std::left << "商家ID: " << gd.m_sellerID << endl;
            cout << setw(20) << std::left << "商品状态: " << gd.m_state << endl;
        }
        gd.ReadALineFromFile(fin);
    }

    fin.close();
}
bool Good::ModifyGood(const string & subString, const serialNum n, const string & modifyString) const
{
    ifstream fin(GOOD_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    char outputFileName[L_tmpnam];
    tmpnam(outputFileName);
    cout << outputFileName << endl;
    ofstream fout(string(outputFileName), std::ios_base::out);
    if (!fout.is_open())
    {
        cout << "Can't open file " << outputFileName << endl;
        exit(EXIT_FAILURE);
    }
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        if (!strcmp(gd.m_ID, subString.c_str()))
        {
            switch (n)
            {
            case serialNum::ID:
                    strcpy(gd.m_ID, modifyString.c_str());
                break;
            case serialNum::NAME:
                    strcpy(gd.m_name, modifyString.c_str());
                break;
            case serialNum::PRICE:
                    gd.m_price = strtod(modifyString.c_str(), NULL);
                break;
            case serialNum::AVAILABLE_TIME:
                    gd.m_availableTime = modifyString;
                break;
                case serialNum::SELLER_ID:
                    gd.m_sellerID = modifyString;
                break;
            case serialNum::STATE:
                    gd.m_state = modifyString;
                break;
            default:
                break;
            }
        }
        fout << gd;
        gd.ReadALineFromFile(fin);
    }

    fin.close();
    fout.close();

    remove("..\\good.txt");
    if (!rename(outputFileName, "..\\good.txt"))
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
bool Good::PublichGood() const
{
    ofstream fout(GOOD_FILE_NAME, std::ios_base::app);
    if (!fout.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    fout << *this;
    return true;

}
bool Good::BuyerGood(const string & subString, const string & userID) const
{
    // cout << "buy success" << endl;
    Good gd;

    ifstream fin(GOOD_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << GOOD_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    gd.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        
        if (!strcmp(gd.m_ID, subString.c_str()))
        {
            break;
        }
        gd.ReadALineFromFile(fin);
    }
    fin.close();
    Order odr("id", gd.m_ID, gd.m_price, string("time"), gd.m_sellerID, userID);
    odr.setID();

    fin.open(ORDER_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "Can't open file " << ORDER_FILE_NAME << endl;
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
    Order tmpOdr;
    tmpOdr.ReadALineFromFile(fin);

    while (!fin.eof())
    {
        fout << tmpOdr;
        gd.ReadALineFromFile(fin);
    }
    fout << odr;

    fin.close();
    fout.close();

    remove("..\\order.txt");
    if (!rename(outputFileName, "..\\order.txt"))
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






ostream & Good::inter(ostream & os, const char * cstr, const int fillLength) const
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

const string Good::doubleToString(const double num, const int precision) const
{
    ostringstream osstr;
    if (precision > 0)
    {
        osstr << std::fixed << setprecision(precision);
    }
    osstr << num;
    return osstr.str();
}

const Good & Good::operator<<(ostream & os) const
{
    inter(os, this->m_ID, int(size::ID));
    inter(os, this->m_name, int(size::NAME));
    inter(os, doubleToString(this->m_price, 1).c_str(), int(size::PRICE));
    inter(os, this->m_availableTime.c_str(), int(size::AVAILABLE_TIME));
    inter(os, this->m_sellerID.c_str(), int(size::SELLER));
    inter(os, this->m_state.c_str(), int(size::STATE));
    os << endl;
    return *this;
}
ostream & operator<<(ostream & os, const Good & gd)
{
    gd.operator<<(os);
    return os;
}

bool Good::operator<<(ofstream & fout) const
{
    fout << this->m_ID << ',' << this->m_name << ',' << this->m_price << ',' << this->m_availableTime << ',' << this->m_sellerID << ',' << this->m_state << endl;
    return true;
}
ofstream & operator<<(ofstream & fout, const Good &gd)
{
    gd.operator<<(fout);
    return fout;
}









