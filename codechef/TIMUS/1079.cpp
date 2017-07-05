#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i;
    long long a[100000];
    a[0] = 0;
    a[1] = 1;
    for(i=2;i<100000;i++)
    {
        if(i&1)
        {
            int x = (i-1)/2;
            a[i] = a[x] + a[x+1];
        }
        else
        {
            a[i] = a[i/2];
        }
    }
    int mx[100000];
    mx[0] = a[0];
    int m = mx[0];
    for(i=1;i<100000;i++)
    {
        if(a[i] > m)
        {
            m = a[i];
        }
        mx[i] = m;
    }
    int n;
    scanf(" %d",&n);
    while(n)
    {
        printf("%lld\n",mx[n]);
        scanf(" %d",&n);
    }
    return 0;
}
