

#include "..\\include\\goodManager.h"
#include "..\\include\\namespace.h"
#include "..\\include\\userManager.h"

using namespace LLL;
GoodManager gdm;

vector<Good> GoodManager::goodList;

GoodManager::GoodManager()
{

}
GoodManager::~GoodManager()
{

}

bool GoodManager::ReadFromFile(const string & fileName)
{
    ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << "Can't open file " << fileName << endl;
        exit(EXIT_FAILURE);
    }
    Good gd;
    if (!fin.eof())
    {
        gd.ReadAGoodFromFile(fin);
    }
    while (!fin.eof())
    {
        goodList.push_back(gd);
        gd.ReadAGoodFromFile(fin);
    }
    fin.close();
    return true;
}
bool GoodManager::WriteToFile(const string & fileName) const
{
    char outFileName[L_tmpnam];
    tmpnam(outFileName);
    ofstream fout(outFileName);
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        iter->Write(fout);
    }
    fout.close();
    remove(fileName.c_str());
    rename(outFileName, fileName.c_str());

    return true;
}
void GoodManager::ViewAllGood() const
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        iter->Show();
    }
}

void GoodManager::ViewAllOnsellGood() const
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getState() == u8"销售中")
        {
            iter->Show();
        }
    }
}


bool GoodManager::SearchGood(const string & name) const
{
    bool findFlag = false;
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getName().find(name) != string::npos)
        {
            iter->Show();
            findFlag = true;
        }
    }
    return findFlag;
}
bool GoodManager::PublishGood(const Good & gd)
{
    goodList.push_back(gd);
    return true;
}
void GoodManager::ViewAllPublishedGood(const string & id) const
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getSellerID().find(id) != string::npos)
        {
            iter->Show();
        }
    }
}
bool GoodManager::WithdrawPublishedGood(const string & id)
{
    for (vector<Good>::iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getID().find(id) != string::npos)
        {
            iter->setState("已下架");
        }
    }

    return true;
}
bool GoodManager::BuyGood(const string & buyerID, const string & goodID)
{
    User usr = usrm.SearchUserByID(buyerID);
    for (vector<Good>::iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getID() == goodID)
        {
            if (usr.buyer.getBalance() - iter->getPrice() >= 0)
            {
                string odrID, odrGooddID, createTime, sellerID;
                double price;
                odrID = "NULL";
                odrGooddID = goodID;
                price = iter->getPrice();
                createTime = "NULL";
                sellerID = iter->getSellerID();
                Order odr(odrID, odrGooddID, price, createTime, sellerID, buyerID);
                odm.AddOrder(odr);
                usrm.SetBalance(usr.getID(), usr.buyer.getBalance() - iter->getPrice());
            }
            break;
        }
    }
    return true;
}
void GoodManager::ViewGoodInformation(const string & id) const
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getID().find(id) != string::npos)
        {
            iter->Show();
        }
    }
}

bool GoodManager::ModifyPublishedGoodInfo(const string & sellerID, const Good & oldGood, const Good & newGood)
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getSellerID() == sellerID && iter->getID() == oldGood.getID())
        {
            goodList.erase(iter);
            break;
        }
    }
    goodList.push_back(newGood);
    return true;
}

//返回的不是指针，没找到返回什么？？？------所以一般返回指针？
const Good GoodManager::SearchGoodByID(const string & id) const
{
    for (vector<Good>::const_iterator iter =  goodList.begin(); iter != goodList.end(); iter++)
    {
        if (iter->getID() == id)
        {
            return *iter;
        }
    }
    Good gd;
    return gd;
}






