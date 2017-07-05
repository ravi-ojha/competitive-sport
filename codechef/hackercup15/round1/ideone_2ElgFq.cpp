#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define mod 1000000007
#define ll long long
#define pb push_back
#define N 100002
using namespace std;
ll powmod(long long a, long long b, long long c)
{
    ll ret=1LL;

    while(b)
    {
        if(b & 1)
            ret = (ret*a)%c;
        a=(a*a)%c;

        b>>=1;
    }
    return (ret)%c;
}
vector<int>v[2*N];
//ll dp[2002][2002],dp1[2002][2002];
ll dp[2*N][21];
void dfs(int id)
{
int i,j,p;
//cout<<id<<endl;
 if(v[id].size()==0)
 {
  //cout<<id<<endl;
   for(i=1;i<=20;++i)
   dp[id][i]=i;
   return;
 }
 else
 {
  for(j=0;j<v[id].size();++j)
  dfs(v[id][j]);
  for(i=1;i<=20;++i)
  {
   dp[id][i]=i;
   for(j=0;j<v[id].size();++j)
   {
     ll minm=LONG_LONG_MAX;
     for(p=1;p<=20;++p)
     if(p!=i)
     minm=min(minm,dp[v[id][j]][p]);
     dp[id][i]+=minm;
   }
  }
 }
}
int main()
{
 int i,t,j,k,el,n;
 char ch;

 cin>>t;
 for(k=1;k<=t;++k)
 {
  cout<<"Case #"<<k<<": ";
  s(n);
  for(i=0;i<=n;++i)
  v[i].clear();
  for(i=0;i<n;++i)
  {
   s(el);
   v[el].pb(i+1);
  }
  dfs(1);
  ll an=LONG_LONG_MAX;
  /*for(i=1;i<=n;++i)
  {
  for(j=1;j<=20;++j)
  cout<<dp[i][j]<<" ";
  cout<<endl;
  }*/
  for(i=1;i<=20;++i)
  an=min(an,dp[1][i]);
  printf("%lld\n",an);
 }

 return 0;
}
