/** V2.0
 * @要求
 *  用户信息文件不超过20行，商品信息文件不超过200行，历史订单不超过2000行
 * @设计方案
 *  系统启动时将文件全部读出保存在列表中，对数据的操作在列表中进行。
 * 
*/
#include <cstdlib>

#include "..\\include\\config.h"
#include "..\\include\\goodManager.h"
#include "..\\include\\admin.h"
#include "..\\include\\baseUser.h"
#include "..\\include\\buyer.h"
#include "..\\include\\good.h"
#include "..\\include\\order.h"
#include "..\\include\\orderManager.h"
#include "..\\include\\seller.h"
#include "..\\include\\user.h"
#include "..\\include\\namespace.h"
#include "..\\include\\menu.h"

//三个manager代码部分相识，能否优化？


using namespace LLL;


int main()
{
    gdm.ReadFromFile(); //读出文件
    odm.ReadFromFile();
    usrm.ReadFromFile();

/*     Admin adm;
    // adm.ViewAllGood();
    // adm.SearchGood(u8"程序");
    // adm.ViewAllOrder();
    adm.ViewAllUser();
    adm.DeleteUser("U000001");
    // adm.WithdrawGood("M00004"); */

/*     User usr;
    usr.setID("U00001");
    usr.buyer.BuyGood("U00001", "M00004");
    cout << usr.buyer.getBalance() << endl;
    string name("程序");
    usr.buyer.SearchGood(name);
    usr.buyer.setBalance(400);
    cout << usr.buyer.getBalance() << endl;
    usr.buyer.ViewAllGood();
    usr.buyer.ViewGoodInformation("M00004");
    usr.buyer.ViewOrderHistory("U00001"); */

/*     User usr;
    usr.setID("U00001");
    usr.seller.PublishGood();
    usr.seller.ModifyPublishedGoodInfo("U00001", oldGood, newGood);
    usr.seller.ViewAllPublishedGood("U00001");
    usr.seller.WithdrawPublishedGood("M00001"); */
    
    // 展示主菜单
    int selection;
    while (1)
    {
        switch (selection = SelectOperation(SystemMainMenu()))
        {
        case 1:
            UserLogIn();
            break;
        case 2:
            UserSignIn();
            break;
        case 3:
            AdminLogIn();
            break;
        case 4:
            break;
        default:
            break;
        }
        if (selection == 4)
        {
            break;
        }
    }

    gdm.WriteToFile();  //写入文件
    odm.WriteToFile();
    usrm.WriteToFile();

    return EXIT_SUCCESS;
}