#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

vector < int > tree[10001];
int depth[10001];
void dfs(int curr, int curr_depth)
{
	depth[curr] = curr_depth;
	int len = tree[curr].size();
	for(int i=0;i<len;i++)
	{
		cout << "calling dfs " << curr_depth << endl;
		dfs(tree[curr][i], curr_depth + 1);
	}
}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y,w;
		scanf(" %d %d",&x,&y);
		tree[x].push_back(y);
		//tree[y].push_back(x);
	}
	cout << "calling dfs\n";
	dfs(1,0);
	cout << "exiting dfs\n";
	int max1 = -1;
	int max1_idx = -1;
	for(int i=1;i<10001;i++)
	{
		if(max1 < depth[i])
		{
			max1 = depth[i];
			max1_idx = i;
		}
	}
	depth[max1_idx] = -1;
	int max2 = -1;
	int max2_idx = -1;
	for(int i=1;i<10001;i++)
	{
		if(max2 < depth[i])
		{
			max2 = depth[i];
			max2_idx = i;
		}
	}
	cout << max1 << " " << max2 << endl;
	if(n==1)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n",max1+max2);
	}
	return 0;
}
