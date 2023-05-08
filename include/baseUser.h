#ifndef BASEH_
#define BASEH_

#include "config.h"
#include <string>
#include <iostream>

#include "good.h"
#include "order.h"

using std::string;

class BaseUser
{
public:
    enum class size {
        ID = 6, 
        NAME = 30, 
        PASSWORD = 20, 
        TELEPHONE = 20, 
        ADDRESS = 60
    };
    enum class serialNum {
        ID, NAME, TELEPHONE, ADDRESS, PASSWORD, ALL
    };
private:
    
    ;
protected:
    char * m_ID;
    char * m_name;
    string m_password;
    string m_telephone;
    string m_address;
    const BaseUser & ReadALineFromFile(ifstream & fin);
    bool SearchAllOrderByString(const string & subString, const serialNum n);       //这不是order,是user
    

    ;
public:
    /**
     *  @brief  Base constructor.
     * 
     *  Description...
    */
    BaseUser();
    BaseUser(const BaseUser & bsusr);

    /**
     *  @brief  Base destructor.
     * 
     *  Description...
    */
    virtual ~BaseUser();

    BaseUser & operator=(const BaseUser & bsUsr);

    /**
     *  @brief  Modify personal information.
     *  @param  ..
     *  @return ture on success, false on failure.
     * 
     *  Description...
    */
    bool ModifyInformation(const string & subString, const serialNum n, const string & modifyString);

    /**
     *  @brief  View personal information.
     *  @param  ..
     *  @return void
     * 
     * Description...
    */
    virtual void ViewInformation();

    virtual void ViewGood(const string & subString, const Good::serialNum n) const;
    virtual void ViewOrder(const string & subString, const Order::serialNum n) const;



    friend std::ostream & operator<<(std::ostream & os, const BaseUser & bsUsr);
    friend std::ofstream & operator<<(std::ofstream & os, const BaseUser & bsUsr);
    
    ;
};





#endif
