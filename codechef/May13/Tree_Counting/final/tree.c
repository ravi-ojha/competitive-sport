#include<stdio.h>
long long iter_pow(int a,int n)
{
    long long ans = 1;
    long long power = a;
    if(n == 0)
    {
        return 1;
    }
    while(n>0)
    {
        if(n&1)
            {ans = ans*power;
            ans = ans%1000000007;}
        power = power*power;
        power = power%1000000007;
        n /= 2;
        //n<<2;
    }
    return ans;
}

int main()
{
    int n,k;
    long long ans;
    scanf(" %d %d",&n,&k);
    if(k == 1)
    {
        if(n==1)
        {
            printf("1\n");
        }
        else
        {
            ans = iter_pow(n,n-2);
            printf("%lld\n",ans%1000000007);
        }
    }
    else if(k==2)
    {
        if(n==1)
        {
            printf("0\n");
        }
        else
        {
            ans = iter_pow(n,n-2);
            ans = ans*iter_pow(n-1,n);
            ans = ans%1000000007;
            ans = ans*iter_pow(4,n-1);
            ans = ans%1000000007;
            printf("%lld",ans);
        }
    }
    else
    {
        if(n==1)
        {
            printf("0\n");
        }
        else
        {
            ans = iter_pow(3*n-3,2*n);
            ans = ans*iter_pow(3*n,n-2);
            ans = ans%1000000007;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
