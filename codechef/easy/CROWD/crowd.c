#include<stdio.h>
int b[1000000];

long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%1000000007;}
        value = value*value;
        value = value%1000000007;
        power /= 2;
        //power >>= 1;
    }
    return result;
}
long long ohYeah(long long m)
{
    if(m<1000000)
    {
        return b[m];
    }
    else
    {
        return (ohYeah(m-1) + ohYeah(m-2) + fast_pow(2,m-2))%1000000007;
    }
}
int main()
{
    int t,i;
    scanf(" %d",&t);
    b[0] = 0;
    b[1] = 0;
    for(i=2;i<1000000;i++)
    {
        b[i] = (b[i-1]%1000000007 + b[i-2]%1000000007 + fast_pow(2,i-2))%1000000007;
    }
    while(t--)
    {
        long long n,res;
        scanf(" %lld",&n);
        if(n<1000000)
        {
            res = b[n-1];
        }
        else
        {
            res = (ohYeah(n-1) + ohYeah(n-2) + fast_pow(2,n-2))%1000000007;
        }
        printf(" %lld\n",res);
    }
    return 0;
}
