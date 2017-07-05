#include<stdio.h>
#define MOD 3046201
long long int inv(long long int x)
{
    long long int M=MOD;
    long long int a = 1, b = x;
    while (b != 1)
    {
        long long int c = M / b;
        a *= c;
        a %= M;
        b *= c;
        b %= M;
        if (b > M/2)
        {
            a = M - a;
            b = M - b;
        }
    }
    return a;
}
int main()
{
    printf(" %lld",inv(2));
    return 0;
}
