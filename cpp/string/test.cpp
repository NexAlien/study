#include <string>
#include <iostream>

using namespace std;

int main()
{
    string str;
    string str2 = "fun";
    str = "love " + str2 + "!!!";
    cout << str << endl;

    str = "love fun!!!";
    cout << str.find("love") << endl;

    str = "/MMN-0";
    cout << str.substr(1) << endl;

    str = "MMN-0";
    str = ('\\'== str[0]) ? str : '\\'+str;
    cout << str << endl;

    str = str + "-" + "12";
    cout << str << endl;
    return 0;
}
