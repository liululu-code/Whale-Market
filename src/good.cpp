


#include "..\\include\\good.h"


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
Good::Good(const string & id, const string & name, const double price, const string & description, const string & sellerID, const string & availableTime, const string & state)
    : m_price(price), m_description(description), m_sellerID(sellerID), m_availableTime(availableTime), m_state(state)
{
    m_ID = new char [int(size::ID) + 1];
    m_name = new char [int(size::NAME) + 1];
    strcpy(m_ID, id.c_str());
    strcpy(m_name, name.c_str());
}

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
    return *this;
}

Good::~Good()
{
    delete [] m_ID;
    delete [] m_name;
}

const string Good::getName() const
{
    return m_name;
}
const string Good::getID() const
{
    return m_ID;
}

const string Good::getSellerID() const
{
    return m_sellerID;
}





Good & Good::ReadAGoodFromFile(ifstream & fin)
{
    fin.getline(m_ID, int(size::ID) + 1, ',');
    fin.getline(m_name, int(size::NAME) + 1, ',');
    (fin >> m_price).get();
    getline(fin, m_availableTime, ',');
    getline(fin, m_sellerID, ',');
    getline(fin, m_state, '\n');
    return *this;
}




void Good::Show() const
{
    cout << m_ID << ',' << m_name << ',' << m_price << ',' << m_availableTime << ',' << m_sellerID << ',' << m_state << endl;
}

void Good::Write(ofstream & fout) const
{
    fout << m_ID << ',' << m_name << ',' << m_price << ',' << m_availableTime << ',' << m_sellerID << ',' << m_state << endl;
}