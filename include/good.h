#ifndef GOOD_H_
#define GOOD_H_

#include "config.h"


using namespace LLL;

class Good
{
private:
    char * m_ID;
    char * m_name;
    double m_price;
    string m_description;
    string m_sellerID;
    string m_availableTime;
    string m_state;
public:

    
    Good();
    Good(const string & id, const string & name, const double price, const string & description, const string & sellerID, const string & availableTime, const string & state = u8"销售中");
    Good(const Good & gd);
    Good & operator=(const Good & gd);
    ~Good();

    const string getName() const;
    const string getID() const;
    double getPrice() const { return m_price;}
    const string getDescription() const { return m_description; }
    const string getSellerID() const;
    const string getAvailableTime() const { return m_availableTime; }
    const string getState() const { return m_state; }
    
    bool setName(const string & name) { strcpy(m_name, name.c_str()); return true; }
    bool setID(const string & id) { strcpy(m_ID, id.c_str()); return true; }
    bool setPrice(double price) { m_price = price; return true; } 
    bool setDescription(const string & description) { m_description = description; return true; }
    bool setSellerID(const string & sellerID) { m_sellerID = sellerID; return true; }
    bool setAvailableTime(const string & availableTime) { m_availableTime = availableTime; return true; }
    bool setState(const string & state) { m_state = state; return true; }

    Good & ReadAGoodFromFile(ifstream & fin);
    void Show() const;
    void Write(ofstream & fout) const;


};




#endif