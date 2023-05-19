#ifndef CONFIG_H_
#define CONFIG_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <cstdio>

namespace LLL
{
    using std::cout;
    using std::cin;
    using std::endl;

    using std::ostream;
    using std::istream;
    using std::ifstream;
    using std::ofstream;
    using std::getline;
    using std::tmpnam;


    using std::string;

    using std::strcpy;

    using std::vector;


} // namespace LLL

using namespace LLL;
const string GOOD_FILE_NAME = "..\\good.txt";
const string USER_FILE_NAME = "..\\user.txt";
const string ORDER_FILE_NAME = "..\\order.txt";


enum class size {
        ID = 6, 
        NAME = 30, 
    };


#endif



