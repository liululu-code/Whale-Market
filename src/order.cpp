#include "..\\include\\order.h"

Order::Order()
    : m_price(0.0), m_creatTime("NULL"), m_sellerID("NULL"), m_buyerID("NULL")
{
    m_ID = new char [int(size::ID) + 1];
    m_goodID = new char [int(size::ID) + 1];
    strcpy(m_ID, "NULL");
    strcpy(m_goodID, "NULL");
}

Order::Order(string & ID, string & goodID, const double price, const string & createTime, const string & sellerID, const string & buyerID)
    : m_price(price), m_creatTime(createTime), m_sellerID(sellerID), m_buyerID(buyerID)
{
    m_ID = new char [int(size::ID) + 1];
    m_goodID = new char [int(size::ID) + 1];
    strcpy(m_ID, ID.c_str());
    strcpy(m_goodID, goodID.c_str());
};

Order::Order(const Order & odr)
    : m_price(odr.m_price), m_creatTime(odr.m_creatTime), m_sellerID(odr.m_sellerID), m_buyerID(odr.m_buyerID)
{
    m_ID = new char [int(size::ID) + 1];
    m_goodID = new char [int(size::ID) + 1];
    strcpy(m_ID, odr.m_ID);
    strcpy(m_goodID, odr.m_goodID);
}
Order & Order::operator=(const Order & odr)
{
    if (this == &odr)
    {
        return *this;
    }
    delete[] m_ID;
    delete[] m_goodID;
    m_ID = new char [int(size::ID) + 1];
    m_goodID = new char [int(size::ID) + 1];
    strcpy(m_ID, odr.m_ID);
    strcpy(m_goodID, odr.m_goodID);
    m_price = odr.m_price;
    m_creatTime = odr.m_creatTime;
    m_sellerID = odr.m_sellerID;
    m_buyerID = odr.m_buyerID;
    return *this;
}

Order::~Order()
{
    delete[] m_ID;
    delete[] m_goodID;
}





Order & Order::ReadAOrderFromFile(ifstream & fin)
{
    fin.getline(m_ID, int(size::ID) + 1, ',');
    fin.getline(m_goodID, int(size::NAME) + 1, ',');
    (fin >> m_price).get();
    getline(fin, m_creatTime, ',');
    getline(fin, m_sellerID, ',');
    getline(fin, m_buyerID, '\n');
    return *this;
}



void Order::Show() const
{
    cout << m_ID << ',' << m_goodID << ',' << m_price << ',' << m_creatTime << "," << m_sellerID << ',' << m_buyerID << endl;
}

bool Order::Write(ofstream & fout) const
{
    fout <<  m_ID << ',' << m_goodID << ',' << m_price << ',' << m_creatTime << "," << m_sellerID << ',' << m_buyerID << endl;
    return true;
}