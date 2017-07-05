#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> tree[100001];
int vis[100001];

void dfs(int x)
{
	if(vis[x])
	{
		return;
	}
	vis[x] = 1;
	int curr_size = tree[x].size();
	for(int i=0;i<curr_size;i++)
	{
		dfs(tree[x][i]);
	}
}

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n,e;
		scanf(" %d %d",&n,&e);
		for(int i=0;i<100001;i++)
		{
			vis[i] = 0;
			tree[i].clear();
		}
		for(int i=0;i<e;i++)
		{
			int x,y;
			scanf(" %d %d",&x,&y);
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		int res = 0;
		for(int i=0;i<n;i++)
		{
			if(vis[i] == 0)
			{
				res++;
				dfs(i);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
