

#include <iostream>
#include <fstream>


#include "..\\include\\good.h"
#include "..\\include\\order.h"
#include "..\\include\\user.h"
#include "menu.h"

int SelectOperation(int operationNum)
{
    std::cout << "Please input 1-" << operationNum << ": ";
    int selection;
    std::cin >> selection;
    while (selection < 1 || selection > operationNum)
    {
        std::cout << "Please input 1-" << operationNum << ": ";
        std::cin >> selection;
    }
    return selection;
}

void UserLogIn()
{
    char name[10], passwd[10];
    std::cout << "请输入姓名： ";
    std::cin >> name;
    std::cout << "请输入密码： ";
    std::cin >> passwd;
    User usr;
    int pass = 0;
    ifstream fin(USER_FILE_NAME, std::ios_base::in);
    if (!fin.is_open())
    {
        cout << "open file fault" << USER_FILE_NAME << endl;
        exit(EXIT_FAILURE);
    }
    usr.ReadALineFromFile(fin);
    while (!fin.eof())
    {
        #ifdef DEBUG
            // cout << "test: " << name << ":" << passwd << "|" << usr.getName() << ":" << usr.getPassword() << endl;
        #endif
        if (!(strcmp(usr.getName().c_str(), name) || strcmp(usr.getPassword().c_str(), passwd)))
        {
            pass = 1;
            break;
        }
        usr.ReadALineFromFile(fin);
    }
    if (pass == 1)
    {
        std::cout << "******登陆成功！******" << std::endl;
    }
    else
    {
        std::cout << "账号或密码错误，返回系统主菜单" << endl;
        return;
    }
    fin.close();

    string str;
    int selection = 0;
    while (1)
    {
        switch (selection = SelectOperation(PersonalMainMenu()))
        {
        case 1:
            selection = 1;
            break;
        case 2:
            IAmBuyer(usr);
            break;
        case 3:
            IAmSeller(usr);
            break;
        case 4:
            PersonalInfoManage(usr);
            break;
        default:
            break;
        }
        if (selection == 1)
        {
            break;
        }
    }
}

void UserSignIn()
{

}

void AdminLogIn()
{
    char name[10], passwd[10];
    std::cout << "请输入姓名： ";
    std::cin >> name;
    std::cout << "请输入密码： ";
    std::cin >> passwd;

    if (!std::strcmp("a", name) && !std::strcmp("1", passwd))
    {
        std::cout << "******登陆成功！******" << std::endl;
    }
    else
    {
        std::cout << "账号或密码错误，返回系统主菜单" << endl;
        return;
    }

    Admin ad;
    string str;
    int selection;
    while (1)
    {
        switch (selection = SelectOperation(AdminMainMenu()))
        {
        case 1:
            ad.ViewAllGood();
            break;
        case 2:
            cout << "请输入商品名称: ";
            cin >> str;
            ad.SearchAllGood(str, Good::serialNum::NAME);
            break;
        case 3:
            ad.ViewAllOrder();
            break;
        case 4:
            ad.ViewAllUser();
            break;
        case 5:
            cout << "请输入用户ID: ";
            cin >> str;
            ad.DeleteUser(str);
            break;
        case 6:
            cout << "请输入下架商品ID: ";
            cin >> str;
            ad.WithdrawGood(str);
            break;
        case 7:
            break;
        default:
            break;
        }
        if (selection == 7)
        {
            break;
        }
    }
}

void IAmSeller(User & usr)
{
    int selection = 0;
    // User usr;
    Good gd;
    Order odr;
    string name, description, id;
    double price;
    Good::serialNum n;
    while (1)
    {
        switch (selection = SelectOperation(SellerMainMenu()))
        {
        case 1:
            cout << "请输入商品名称: ";
            std::getline(cin, name);
            cout << "请输入商品金额: ";
            cin >> price;
            cout << "请输入商品描述: ";
            std::getline(cin, description);
            gd.setName(name);
            gd.setPrice(price);
            gd.setDescription(description);
            gd.setID();
            gd.setPublisher(usr.getID());
            gd.setState(string("销售中"));
            usr.PublichGood(gd);
            break;
        case 2:
            gd.SearchAllGoodByString(usr.getID(), Good::serialNum::SELLER_ID);
            break;
        case 3:
            int t;
            cout << "请输入修改商品ID: ";
            cin >> id;
            cout << "请输入修改商品属性(1.价格 2.描述): ";
            cin >> t;
            switch (t)
            {
            case 1:
                n = Good::serialNum::PRICE;
                break;
            case 2:
                n = Good::serialNum::DECRIPTION;
                break;
            default:
                break;
            }
            cout << "请输入修改商品价格: ";
            cin >> price;
            gd.ModifyGood(id, n, std::to_string(price));
            break;
        case 4:
            cout << "请输入要下架的商品ID: ";
            cin >> id;
            gd.WithdrawGood(id);
            break;
        case 5:
            odr.SearchAllOrderByString(usr.getID(), Order::serialNum::ID_SELLER);
            break;
        case 6:
            break;
        default:
            break;
        }
        if (selection == 6)
        {
            break;
        }
    }
}

void IAmBuyer(User & usr)
{
    int selection = 0;
    // User usr;           //必须是保存登陆用户的数据
    Good gd;
    Order odr;
    string id, name;
    // double price;
    // Good::serialNum n;
    while (1)
    {
        switch (selection = SelectOperation(BuyerMainMenu()))
        {
        case 1:
            gd.SearchAllGoodByString("销售中", Good::serialNum::STATE);
            break;
        case 2:
            cout << "请输入商品ID: ";
            cin >> id;
            gd.BuyerGood(id, usr.getID());
            break;
        case 3:
            cout << "请输入商品名称: ";
            cin >> name;
            gd.SearchAllGoodByString(name, Good::serialNum::NAME);
            break;
        case 4:
            odr.SearchAllOrderByString(usr.getID(), Order::serialNum::ID_BUYER);
            break;
        case 5:
            cout << "请输入您想查看的商品ID: ";
            cin >> id;
            gd.ViewGoodInfo(id);
            // gd.SearchAllGoodByString(id, Good::serialNum::ID);
            break;
        case 6:
            break;
        default:
            break;
        }
        if (selection == 6)
        {
            break;
        }
    }
}

void PersonalInfoManage(User & usr)
{
    int selection = 0;
    // User usr;
    Good gd;
    // Order odr;
    string str;
    while (1)
    {
        switch (selection = SelectOperation(PersonalInfoManageMenu()))
        {
        case 1:
            break;
        case 2:
            cout << "请选择修改的属性（1.用户名 2.联系方式 3.地址）: ";
            int sel;
            cin >> sel;
            cout << "请输入修改值： ";
            cin >> str;
            switch (sel)
            {
            case 1:
                usr.ModifyInformation(User::serialNum::NAME, str);
                break;
            case 2:
                usr.ModifyInformation(User::serialNum::TELEPHONE, str);
                break;
            case 3:
                usr.ModifyInformation(User::serialNum::ADDRESS, str);
                break;
            default:
                break;
            }
            break;
        case 3:
            usr.ViewInformation();
            break;
        case 4:
            cout << "请输入充值数目: ";
            double money;
            cin >> money;
            usr.Recharge(money);
            break;
        default:
            break;
        }
        if (selection == 1)
        {
            break;
        }
    }
}

int SystemMainMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.用户登录 2.用户注册 3.管理员登录 4.退出程序" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 4;
}



int AdminMainMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.查看所有商品 2.搜索商品 3.查看所有订单 4.查看所有用户 5.删除用户 6.下架商品 7.注销" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 7;
}


int BuyerMainMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 6;
}

int PersonalMainMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.注销登录 2.我是买家 3.我是卖家 4.个人信息管理" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 7;
}




int PersonalInfoManageMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.返回用户主界面 2.修改信息 3.查看信息 4.充值" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 4;
}



int SellerMainMenu()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面" << std::endl;
    std::cout << "==================================================================================" << std::endl;
    return 6;
}