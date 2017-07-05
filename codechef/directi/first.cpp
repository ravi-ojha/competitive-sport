#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int vd[10011] = {0};
    int n,v;
    scanf(" %d %d",&n,&v);
    for(i=0;i<v;i++)
    {
        int tmp;
        scanf(" %d",&tmp);
        vd[tmp] = 1;
    }
    return 0;
}
