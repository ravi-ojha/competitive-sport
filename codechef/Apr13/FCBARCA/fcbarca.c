#include<stdio.h>
long long iter_pow(int a,int n)
{
    long long ans = 1;
    long long power = a;
    while(n>0)
    {
        if(n&1)
            {ans = ans*power;
            ans = ans%1000000007;}
        power = power*power;
        power = power%1000000007;
        n /= 2;
    }
    return ans;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k;
        long long ans,last,final;
        scanf(" %d %d",&n,&k);
        if(n==3)
        {
            ans = k*(k-1);
            printf("%lld\n",ans);
            continue;
        }
        if(n==2)
        {
            ans = 1;
            last = 0;
        }
        else
        {
            ans = iter_pow(k,n-3);
            last = (k+1);
            //last = last%1000000007;
        }
        //printf("ans = %lld\t",ans);
        last = last + k;
        //printf("last = %lld\n",last);
        last = last%1000000007;
        final = ans*last;
        final = final%1000000007;
        printf("%lld\n",final);
    }
    return 0;
}
