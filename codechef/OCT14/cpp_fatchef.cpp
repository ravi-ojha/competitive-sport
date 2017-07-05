#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define MOD 1000000009
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n,m,i;
		scanf(" %d %d",&n,&m);
		long long res = 1;
		vector < pair<int,char> > a;
		for(i=0;i<m;i++)
		{
			char x;
			int y;
			scanf(" %c %d",&x,&y);
			a.push_back(make_pair(y,x));
		}
		sort(a.begin(),a.end());
		for(i=1;i<m;i++)
		{
			if(a[i].second != a[i-1].second)
			{
				res = res*(a[i].first - a[i-1].first);
				res %= MOD;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}
