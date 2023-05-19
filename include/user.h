#ifndef USER_H_
#define USER_H_

#include "config.h"
#include "baseUser.h"
#include "seller.h"
#include "buyer.h"

using namespace LLL;

class User : public BaseUser
{
private:
    
public:
    Seller seller;
    Buyer buyer;


    User & ReadAUserFromFile(ifstream & fin);
    void Show() const;
    void Write(ofstream & fout) const;

};





#endif