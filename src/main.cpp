#include <iostream>
#include <ctime>

#include <valarray>


#include "..\\include\\config.h"
#include "..\\include\\baseUser.h"
#include "..\\include\\good.h"
#include "..\\include\\order.h"
#include "..\\include\\user.h"
#include "..\\include\\menu.h"

#include <string>
#include <array>

using std::cout;
using std::cin;
using std::endl;
//对文件操作做一个类？

bool delay(int second)
{
    clock_t begin = clock();
    while ((clock() - begin) / CLOCKS_PER_SEC < second);
    // cout << clock() - begin;
    return true;
}


int main()
{


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


// #ifdef DEBUG
//     delay(3);
// #endif
    return EXIT_SUCCESS;
}