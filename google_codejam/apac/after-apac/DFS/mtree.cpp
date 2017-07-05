#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

vector < pair<int,int> > tree[100001];

void dfs()
{

}

int main()
{
	int n;
	scanf(" %d",&n);
	for(int i=0;i<n-1;i++)
	{
		int x,y,w;
		scanf(" %d %d %d",&x,&y,&w);
		tree[x].push_back(make_pair(y,w));
		tree[y].push_back(make_pair(x,w));
	}
	return 0;
}
