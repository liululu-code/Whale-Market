
#include "menu.h"
// #include "user.h"
#include "userManager.h"
#include "goodManager.h"
#include "orderManager.h"
// #include "config.h"

int SelectOperation(int operationNum)
{
    std::cout << "Please input 1-" << operationNum << ": ";
    int selection;
    (std::cin >> selection).get();
    while (selection < 1 || selection > operationNum)
    {
        std::cout << "Please input 1-" << operationNum << ": ";
        (std::cin >> selection).get();
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

    User usr = usrm.VerifyUser(name, passwd);
    
    if (usr.getPassword() != "NULL")
    {
        std::cout << "******登陆成功！******" << std::endl;
    }
    else
    {
        std::cout << "账号或密码错误，返回系统主菜单" << endl;
        return;
    }

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
    string name, passwd;
    cout << "请输入用户名: ";
    getline(cin, name);
    cout << "请输入密码: ";
    getline(cin, passwd);
    User u;
    u.setName(name);
    u.setPassword(passwd);
    usrm.AddUser(u);
    usrm.WriteToFile();
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

    int selection;
    string tmp;
    while (1)
    {
        switch (selection = SelectOperation(AdminMainMenu()))
        {
        case 1:
            gdm.ViewAllGood();
            break;
        case 2:
            cout << "请输入商品名称: ";
            cin >> tmp;
            gdm.SearchGood(tmp);
            break;
        case 3:
            odm.ViewAllOrder();
            break;
        case 4:
            usrm.ViewAllUser();
            break;
        case 5:
            cout << "请输入用户ID: ";
            cin >> tmp;
            usrm.DeleteUser(tmp);
            break;
        case 6:
            cout << "请输入下架商品ID: ";
            cin >> tmp;
            gdm.WithdrawPublishedGood(tmp);
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

bool SellerPublishGood(const User usr)
{
    string name, description, id;
    double price;
    cout << "请输入商品名称: ";
    getline(cin, name);
    cout << "请输入商品金额: ";
    (cin >> price).get();
    cout << "请输入商品描述: ";
    std::getline(cin, description);

    Good gd("NULL", name, price, description, usr.getID(), "NULL");
    usr.seller.PublishGood(gd);
    return true;
}

bool SellerModifyGood(const User usr)
{
    int t;
    string id, description;
    double price;
    cout << "请输入修改商品ID: ";
    cin >> id;
    Good oldGood = gdm.SearchGoodByID(id);
    Good newGood = oldGood;
    cout << "请输入修改商品属性(1.价格 2.描述): ";
    cin >> t;
    switch (t)
    {
    case 1:
        cout << "请输入修改商品价格: ";
        (cin >> price).get();
        newGood.setPrice(price);
        break;
    case 2:
        cout << "请输入修改商品描述: ";
        cin >> description;
        newGood.setDescription(description);
        break;
    default:
        break;
    }

    if (gdm.ModifyPublishedGoodInfo(usr.getID(), oldGood, newGood))
    {
        cout << "修改成功！！！" << endl;
    }
    return true;
}



void IAmSeller(User & usr)
{
    int selection = 0; 
    string tmp;
    while (1)
    {
        switch (selection = SelectOperation(SellerMainMenu()))
        {
        case 1:
            SellerPublishGood(usr);
            break;
        case 2:
            usr.seller.ViewAllPublishedGood(usr.getID());
            break;
        case 3:
            SellerModifyGood(usr);
            break;
        case 4:
            cout << "请输入要下架的商品ID: ";
            cin >> tmp;
            usr.seller.WithdrawPublishedGood(tmp);
            break;
        case 5:
            usr.seller.ViewOrderHistory(usr.getID());
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
    string id, name;
    // double price;
    // Good::serialNum n;
    while (1)
    {
        switch (selection = SelectOperation(BuyerMainMenu()))
        {
        case 1:
            usr.buyer.ViewAllGood();
            break;
        case 2:
            cout << "请输入商品ID: ";
            (cin >> id).get();
            usr.buyer.BuyGood(usr.getID(), id);
            break;
        case 3:
            cout << "请输入商品名称: ";
            cin >> name;
            usr.buyer.SearchGood(name);
            break;
        case 4:
            usr.buyer.ViewOrderHistory(usr.getID());
            break;
        case 5:
            cout << "请输入您想查看的商品ID: ";
            getline(cin, id);
            usr.buyer.ViewGoodInformation(id);
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

bool PersonalInformationModify(User & usr)
{
    string newValue;
    cout << "请选择修改的属性(1.用户名 2.联系方式 3.地址): ";
    int sel;
    (cin >> sel).get();
    cout << "请输入修改值： ";
    (cin >> newValue).get();
    User newUser = usr;
    switch (sel)
    {
    case 1:
        newUser.setName(newValue);
        break;
    case 2:
        newUser.setTelephone(newValue);
        break;
    case 3:
        newUser.setAdress(newValue);
        break;
    default:
        break;
    }
    usrm.ModifyUser(usr, newUser);
    return true;
}

void PersonalInfoManage(User & usr)
{
    int selection = 0;
    Good gd;
    string str;
    while (1)
    {
        switch (selection = SelectOperation(PersonalInfoManageMenu()))
        {
        case 1:
            break;
        case 2:
            PersonalInformationModify(usr);
            break;
        case 3:
            usrm.ViewUser(usr);
            break;
        case 4:
            cout << "请输入充值数目: ";
            double money;
            (cin >> money).get();
            if (usrm.SetBalance(usr.getID(), usr.buyer.getBalance() + money))
            {
                cout << "充值成功！！！" << endl;
            }
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




