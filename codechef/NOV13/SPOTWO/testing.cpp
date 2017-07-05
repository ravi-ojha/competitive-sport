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
    printf(" %lld\n",fast_pow(2,20020020022222000000));

    return 0;
}
