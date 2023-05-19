#include "..\\include\\user.h"




User & User::ReadAUserFromFile(ifstream & fin)
{
    string tmp;
    double balance;
    getline(fin, tmp, ',');
    setID(tmp);
    getline(fin, tmp, ',');
    setName(tmp);
    getline(fin, tmp, ',');
    setTelephone(tmp);
    getline(fin, tmp, ',');
    setAdress(tmp);
    getline(fin, tmp, ',');
    setPassword(tmp);
    (fin >> balance).get();
    buyer.setBalance(balance);
    return *this;
}




void User::Show() const
{
    cout << getID() << ',' << getName() << ',' << getTelephone() << ',' << getAdress() <<  ',' << getPassword() << ',' << buyer.getBalance() << endl;
}

void User::Write(ofstream & fout) const
{
    fout << getID() << ',' << getName() << ',' << getTelephone() << ',' << getAdress() <<  ',' << getPassword() << ',' << buyer.getBalance() << endl;
}


