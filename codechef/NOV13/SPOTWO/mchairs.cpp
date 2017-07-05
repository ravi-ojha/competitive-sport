#include<iostream>
#include<cstdio>
#define MOD 1000000007
using namespace std;
unsigned long long fast_pow(unsigned long long a, unsigned long long n)
{
    unsigned long long result = 1, power = n, value = a;
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
unsigned long long dec_to_bin(unsigned long long n)
{
    int dbz[1000], z = 0,i;
    while(n)
    {
        if(n&1)
        {
            dbz[z] = 1;
        }
        else
        {
            dbz[z] = 0;
        }
        z += 1;
        n>>=1;
    }
    unsigned long long res = 0;
    for(i=z-1; i>=0; i--)
    {
        res += dbz[i]==1?1:0;
        if(i!=0)
        {
            res*=10;
        }
    }
    return res;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        unsigned long long n,i;
        scanf(" %llu",&n);
        //printf("%llu\n",dec_to_bin(n));
        unsigned long long res = fast_pow(2,dec_to_bin(n));
        //printf("%llu\n",fast_pow(2,dec_to_bin(n)));
        res = res*res;
        res %= MOD;
        printf("%llu\n",res);
    }
    return 0;
}
