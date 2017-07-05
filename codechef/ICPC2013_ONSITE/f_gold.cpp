#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int c,i,n;
    scanf(" %d",&c);
    int a[c];
    for(i=0;i<c;i++)
    {
        scanf(" %d",&a[i]);
    }
    scanf(" %d",&n);
    int b[n];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&b[i]);
    }
    int mx = -1;
    for(i=0;i<n;i++)
    {
        if(mx<b[i])
        {
            mx = b[i];
        }
    }
    int mn = 1000000000;
    for(i=0;i<mx;i++)
    {
        if(mn>a[i])
        {
            mn = a[i];
        }
    }
    printf("%d\n",mn);
    return 0;
}
