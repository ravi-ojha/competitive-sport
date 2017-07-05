#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    int a = 1000000000;
    stringstream ss;
    ss << hex << a;
    string s = ss.str();
    cout << s + "\n" << a << endl << ss;

    /*====================================*/

    //std::string s = std::to_string(42);          // have to use g++ -std=c++0x to_string.cpp during compiling
    //cout << s;
    return 0;
}
