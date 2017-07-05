#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        string str1 = "010";
        string str2 = "101";
        string given;
        cin >> given;
        if((given.find(str1) != string::npos) || (given.find(str2) != string::npos))
        {
            printf("Good\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
    return 0;
}
