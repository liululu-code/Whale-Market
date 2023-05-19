#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include "user.h"

using std::cout;
using std::endl;
using std::cin;

int SelectOperation(int operationNum);

void UserLogIn();
void UserSignIn();
void AdminLogIn();

void IAmBuyer(User & usr);
void IAmSeller(User & usr);
void PersonalInfoManage(User & usr);

int SystemMainMenu();
int AdminMainMenu();
int BuyerMainMenu();
int PersonalMainMenu();
int PersonalInfoManageMenu();
int SellerMainMenu();


bool SellerPublishGood(const User usr);
bool SellerModifyGood(const User usr);

bool PersonalInformationModify(User & usr);
void PersonalInfoManage(User & usr);

#endif