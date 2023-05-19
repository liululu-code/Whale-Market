#ifndef GOODMANAGER_H_
#define GOODMANAGER_H_


#include "good.h"
#include "config.h"
#include "order.h"


using namespace LLL;


class GoodManager
{
private:
    //声明为静态，保证所有实例共享一个商品列表
    static vector<Good> goodList;       //静态成员变量需要在cpp文件中初始化
public:

    GoodManager();
    ~GoodManager();

    bool ReadFromFile(const string & fileName = GOOD_FILE_NAME);
    bool WriteToFile(const string & fileName = GOOD_FILE_NAME) const;

    void ViewAllGood() const;
    void ViewAllOnsellGood() const;
    bool SearchGood(const string & name) const;
    bool PublishGood(const Good & gd);
    void ViewAllPublishedGood(const string & id) const;
    bool WithdrawPublishedGood(const string & id);
    bool BuyGood(const string & buyerID, const string & goodID);
    void ViewGoodInformation(const string & id) const;
    bool ModifyPublishedGoodInfo(const string & sellerID, const Good & oldGood, const Good & newGood);
    const Good SearchGoodByID(const string & id) const;
};
extern GoodManager gdm;





#endif