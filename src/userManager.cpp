
#include "..\\include\\userManager.h"

vector<User> UserManager::userList;
UserManager usrm;

bool UserManager::ReadFromFile(const string & fileName)
{
    ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << "Can't open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    User user;
    if (!fin.eof())
    {
        user.ReadAUserFromFile(fin);
    }
    while (!fin.eof())
    {
        userList.push_back(user);
        user.ReadAUserFromFile(fin);
    }
    fin.close();
    return true;
}
bool UserManager::WriteToFile(const string & fileName) const
{
    char outFileName[L_tmpnam];
    tmpnam(outFileName);
    ofstream fout(outFileName);
    for (vector<User>::const_iterator iter =  userList.begin(); iter != userList.end(); iter++)
    {
        iter->Write(fout);
    }
    fout.close();
    remove(fileName.c_str());
    rename(outFileName, fileName.c_str());

    return true;
}

bool UserManager::AddUser(User & user)
{
    userList.push_back(user);
    return true;
}

bool UserManager::DeleteUser(const string & id)
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getID() == id)
        {
            userList.erase(iter);
        }
    }
    return true;
}

bool UserManager:: ModifyUser(User & oldUser, User & newUser)
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getID() == oldUser.getID())
        {
            userList.erase(iter);
            break;
        }
    }
    userList.push_back(newUser);
    return true;
}
void UserManager::ViewUser(const User & user) const
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getID() == user.getID())
        {
            iter->Show();
        }
    }
}

void UserManager::ViewAllUser() const
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        iter->Show();
    }
}

User UserManager::VerifyUser(const string & name, const string & password) const
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getName() == name && iter->getPassword() == password)
        {
            return *iter;
        }
    }
    User u;
    return u;
}

bool UserManager::SetBalance(const string & userID, double balance)
{
    for (vector<User>::iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getID() == userID)
        {
            iter->buyer.setBalance(balance);
            return true;
        }
    }
    return false;
}

const User UserManager::SearchUserByID(const string & userID) const
{
    for (vector<User>::const_iterator iter = userList.begin(); iter!=userList.end(); iter++)
    {
        if (iter->getID() == userID)
        {
            return *iter;
        }
    }
    User u;
    return u;
}