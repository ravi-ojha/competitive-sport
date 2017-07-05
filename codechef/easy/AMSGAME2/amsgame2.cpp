#include<iostream>
#include<cstdio>
using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int main()
{
    int t;
    //scanf(" %d",&t);
    cin>>t;
    while(t--)
    {
        int n,i,j;
        //scanf(" %d",&n);
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
        {
            //scanf(" %d",&a[i]);
            cin>>a[i];
        }
        long long dp[10001] = {0};
        for(i=0;i<n;i++)
        {
            for(j=1;j<10001;j++)
            {
                if(dp[j] > 0)
                {
                    dp[gcd(a[i],j)] += dp[j];
                }
            }
            dp[a[i]] += 1;
        }
        //printf("%lld\n",dp[1]);
        cout<<dp[1]<<endl;
    }
    return 0;
}
