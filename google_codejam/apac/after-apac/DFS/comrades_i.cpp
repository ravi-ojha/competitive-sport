#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> tree[100001];
int dfs_in[100001], dfs_out[100001], depth[100001];
int dfs_count = 0;

void dfs(int curr, int curr_depth)
{
	dfs_in[curr] = dfs_count;
	dfs_count++;

	depth[curr] = curr_depth;

	int len = tree[curr].size();
	for(int i=0;i<len;i++)
	{
		dfs(tree[curr][i], curr_depth+1);
	}

	dfs_out[curr] = dfs_count;
	dfs_count++;
}

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		int root;
		for(int i=0;i<=n;i++)
		{
			tree[i].clear();
		}
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf(" %d",&x);
			if(x==0)
			{
				root = i;
			}
			tree[x].push_back(i);
		}
		dfs(root,0);
		int q;
		scanf(" %d",&q);
		while(q--)
		{
			int x, y;
			scanf(" %d %d",&x,&y);
			if(dfs_in[x] > dfs_in[y] && dfs_out[x] < dfs_out[y]) //If you once think on it, both are important; think of v-shape tree
			{
				printf("%d\n",depth[x]-depth[y]-1);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
