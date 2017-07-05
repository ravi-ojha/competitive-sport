#include<iostream>
#include<cstdio>
#define MOD 1000000007
using namespace std;
long long fast_pow(int a, int n)
{
    long long result = 1, power = n, value = a;
    while(power > 0)
    {
        if(power&1)
        {
            result = result*value;
            result %= MOD;
        }
        value = value*value;
        value %= MOD;
        power /= 2;
    }
    return result;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i;
        scanf(" %d",&n);
        printf("%lld\n",fast_pow(2,n)-1);
    }
    return 0;
}
