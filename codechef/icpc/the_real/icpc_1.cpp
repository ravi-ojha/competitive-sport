#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,m,t;
        int goku, naruto;
        scanf(" %d %d %d",&n,&m,&t);
        goku = n/m;
        naruto = n%m;
        if(naruto != 0)
        {
            goku++;
        }
        goku = goku*2*t;
        printf("%d\n",goku);
    }
    return 0;
}
