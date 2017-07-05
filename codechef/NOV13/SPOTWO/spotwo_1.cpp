#include <iostream>
#include <cstdio>
#define ull unsigned long long
#define MOD 1000000007
using namespace std;

ull fpow(ull a, ull b, ull c)
{
    ull product = a,final = 1;
    while(b)
    {
        if(b&1==1){
            final *= product;
            final %= c;
        }
        b>>=1;
        product = (product*product)%c;
    }
    return final;
}

ull tobin(ull n)
{
    int dig[1000], top = 0;
    while(n){
        dig[top++] = (n&1)?1:0;
        n>>=1;
    }
    ull ret = 0;
    for(int i=top-1; i>=0; i--){
        ret += dig[i]==1?1:0;
        if(i!=0)ret*=10;
    }
    return ret;
}

int main()
{
    int T;
    ull n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%llu", &n);
        //printf("tobind: %llu\n",tobin(n));
        ull final = fpow(2, tobin(n), MOD);
        printf("final = %llu\n",final);
        final = fpow(final, 2, MOD);
        printf("%llu\n", final);
    }
    return 0;
}
