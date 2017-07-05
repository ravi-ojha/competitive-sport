#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
#define FILL(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector<int>
#define PII pair<int,int>
#define M 100005
#define INF 1000000
#define MOD 1000000007
VI v[10];
int l,dis[M];
bool vis[M],vis1[10];
char s[M];
int bfs()
{
    queue<int> Q;
    int i,now,te;
    Q.push(0);
    dis[0]=0;
    vis[0]=true;
    while(!Q.empty())
    {
        now=Q.front();
        Q.pop();
        if(now==l-1)
        return dis[now];
        te=s[now]-'0';
        for(i=0;i<v[te].size() && !vis1[te];i++)
        {
            if(vis[v[te][i]]) continue;
            vis[v[te][i]]=true;
            dis[v[te][i]]=dis[now]+1;
            Q.push(v[te][i]);
        }
        if(now>0 && !vis[now-1] && !vis1[s[now-1]-'0'] && s[now]!=s[now-1])
        {
            vis[now-1]=true;
            dis[now-1]=dis[now]+1;
            Q.push(now-1);
        }
        if(now<l-1 && !vis[now+1] && !vis1[s[now+1]-'0'] && s[now]!=s[now+1])
        {
            vis[now+1]=true;
            dis[now+1]=dis[now]+1;
            Q.push(now+1);
        }
        vis1[te]=true;
    }
}
main()
{
    int i;
    //freopen(".txt","r",stdin);
    cin>>s;
    l=strlen(s);
    REP(i,l)
    v[s[i]-'0'].pb(i);
    //FILL(dis,INF);
    cout<<bfs();
}
