#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define mem(a,val) memset(a,val,sizeof(a))
int dp[1805][305][12];

int rec(int r,int b,int w)
{
int ans=0;
if(b==1)
{
if(r==6||r==4)
return dp[r][b][w]=1;
if(r==0)
{
if(w==0)
return dp[r][b][w]=1;
else
if(w>0)
return dp[r][b][w]=2;
}
}
if(dp[r][b][w])
return dp[r][b][w];
if(r-6>=0&&b>0)
ans=(ans%mod+rec(r-6,b-1,w)%mod)%mod;
if(r-4>=0&&b>0)
ans=(ans%mod+rec(r-4,b-1,w)%mod)%mod;
if(w>0&&b>0)
ans=(ans%mod+rec(r,b-1,w-1)%mod)%mod;
if(r>=0&&b>0)
ans=(ans%mod+rec(r,b-1,w)%mod)%mod;
return dp[r][b][w]=ans;
}
int main()
{
int t;
scanf("%d",&t);
mem(dp,0);
while(t--)
{
long long int r,b,w;
scanf(" %lld %lld %lld",&r,&b,&w);
if(r>b*6)
printf("0\n");
else
{
long long int res=rec(r,b, w);
printf("%lld\n",res);
}
}
}
