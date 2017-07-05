#include<stdio.h>
#define MOD 1000000007
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n;
        int i;
        scanf(" %d",&n);
        int a[n],b[n];

        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf(" %d",&b[i]);
        }
        long long result = 1;
        int multi = n;
        for(i=0;i<n;i++)
        {
            int dp[1111] = {0};
            if(dp[a[i]] != 1)
            {
                dp[a[i]] = 1;
                multi--;
            }
            if(dp[b[i]] != 1)
            {
                dp[b[i]] = 1;
                multi--;
            }
            if(multi <= 0)
            {
                break;
            }
            result *= multi;
            multi = n - (i+1);
            result %= MOD;
        }
        printf("%llu\n",result);
    }
    return 0;
}
