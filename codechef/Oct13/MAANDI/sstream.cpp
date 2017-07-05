#include<sstream>
#include<iostream>
using namespace std;
int main()
{
    int i = 43;
    stringstream ss;
    ss << i;
    string sss = ss.str();
    cout << sss << "\n" << ss << "\n";
    ss << i;
    sss = ss.str();
    cout << sss << "\n" << ss << "\n";
    return 0;
}
