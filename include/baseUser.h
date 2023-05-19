#ifndef BASE_USER_H_
#define BASE_USER_H_

#include "config.h"

using namespace LLL;

class BaseUser
{
private:
    char * m_ID;
    char * m_name;
    string m_password;
    string m_telephone;
    string m_address;
public:
    BaseUser();
    BaseUser(const BaseUser & bsu);
    const BaseUser & operator=(const BaseUser & bsu);
    virtual ~BaseUser();

    // char * getID();
    // char * getName();
    // string & getPassword();
    // string & getTelephone();
    // string & getAddress();

    const string getID() const {return m_ID;}
    const string getName() const {return m_name;}
    const string getPassword() const {return m_password;}
    const string getTelephone() const {return m_telephone;}
    const string getAdress() const {return m_address;}

    bool setID(const string & id) {strcpy(m_ID, id.c_str()); return true;}
    bool setName(const string & name) {strcpy(m_name, name.c_str()); return true;}
    bool setPassword(const string & password) {m_password = password; return true;}
    bool setTelephone(const string & telephone) {m_telephone = telephone; return true;}
    bool setAdress(const string & address) {m_address = address; return true;}


    virtual bool ModifyInformation() {return true;}
    virtual void ViewInformation() const { }



};



#endif







