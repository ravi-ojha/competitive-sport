/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

VI v[200010];
bool vis[200010];
LL size=0;

class FastInput {
public:
FastInput() {
m_dataOffset = 0;
m_dataSize = 0;
m_v = 0x80000000;
}
inline uint32_t ReadNext() {
if (m_dataOffset == m_dataSize) {
int r = read(0, m_buffer, sizeof(m_buffer));
if (r <= 0) return m_v;
m_dataOffset = 0;
m_dataSize = 0;
int i = 0;
if (m_buffer[0] < '0') {
if (m_v != 0x80000000) {
m_data[m_dataSize++] = m_v;
m_v = 0x80000000;
}
for (; (i < r) && (m_buffer[i] < '0'); ++i);
}
for (; i < r;) {
if (m_buffer[i] >= '0') {
m_v = m_v * 10 + m_buffer[i] - 48;
++i;
} else {
m_data[m_dataSize++] = m_v;
m_v = 0x80000000;
for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
}
}
}
return m_data[m_dataOffset++];
}
public:
uint8_t m_buffer[32768];
uint32_t m_data[16384];
size_t m_dataOffset, m_dataSize;
uint32_t m_v;
};

void dfs(int n)	//a simple depth-first search
{
	vis[n]=true;
	size++;
	REP(i,v[n].size())
		if(!vis[v[n][i]])
			dfs(v[n][i]);
    vis[n]=false;
	return;
}
FastInput fi;
int main(){

	int t;
	//scanf("%d",&t);
	t = fi.ReadNext();
	while(t--)
	{
		int a,b,n,m,ans=0,amo;
		LL num=1;
		//scanf(" %d %d %d",&n,&m,&amo);
		n = fi.ReadNext();
		m = fi.ReadNext();
		amo = fi.ReadNext();

		memset(vis,0,sizeof(vis));
		REP(i,n)
			v[i].clear();

		REP(i,m)
		{
			//scanf(" %d %d",&a,&b);
            a = fi.ReadNext();
            b = fi.ReadNext();
			a--;
			b--;
			v[a].PB(b);
			v[b].PB(a);
		}

		REP(i,n)
		{
			if(!vis[i])	//if a vertex is not visited, do a dfs on it
			{
			    vis[n-i-1] = true;
				size=0;
				//ans++;	//number of connected components so far
				dfs(i);
				if(size == (n-1))
				ans++;
				//num*=size;	//number of ways to choose a captain for each connected component = C(size,1) = size => total ways = product of no. of ways of each component
				//if(num>=mod)
					//num%=mod;
                vis[n-i] = false;
			}
		}
		printf("%d\n",ans*amo);
	}

	return 0;
}
