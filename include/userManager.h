#ifndef USERMANAGER_H_
#define USERMANAGER_H_

#include "config.h"
#include "user.h"

using namespace LLL;



class UserManager
{
private:
    static vector<User> userList;
public:

    UserManager() {};
    ~UserManager() {};

    bool ReadFromFile(const string & fileName = USER_FILE_NAME);
    bool WriteToFile(const string & fileName = USER_FILE_NAME) const;


    bool AddUser(User & user);
    bool DeleteUser(const string & id);
    bool ModifyUser(User & oldUser, User & newUser);
    void ViewUser(const User & user) const;
    void ViewAllUser() const;
    User VerifyUser(const string & name, const string & password) const;
    bool SetBalance(const string & userID, double balance);

    const User SearchUserByID(const string & userID) const;
};
extern UserManager usrm;



#endif