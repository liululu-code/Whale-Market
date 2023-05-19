#include "..\\include\\baseUser.h"



BaseUser::BaseUser()
{
    m_ID = new char[int(size::ID) + 1];
    m_name = new char[int(size::NAME) + 1];
    strcpy(m_ID, "NULL");
    strcpy(m_name, "NULL");
    m_password = "NULL";
    m_telephone = "NULL";
    m_address = "NULL";
}
BaseUser::BaseUser(const BaseUser & bsu)
{
    m_ID = new char[int(size::ID) + 1];
    m_name = new char[int(size::NAME) + 1];
    strcpy(m_ID, bsu.m_ID);
    strcpy(m_name, bsu.m_name);
    m_password = bsu.m_password;
    m_telephone = bsu.m_telephone;
    m_address = bsu.m_address;
}
const BaseUser & BaseUser::operator=(const BaseUser & bsu)
{
    if (this == &bsu)
    {
        return *this;
    }
    delete [] m_ID;
    delete [] m_name;
    m_ID = new char[int(size::ID) + 1];
    m_name = new char[int(size::NAME) + 1];
    strcpy(m_ID, bsu.m_ID);
    strcpy(m_name, bsu.m_name);
    m_password = bsu.m_password;
    m_telephone = bsu.m_telephone;
    m_address = bsu.m_address;
    return *this;
}
BaseUser::~BaseUser()
{
    delete [] m_ID;
    delete [] m_name;
}