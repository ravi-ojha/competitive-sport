#include <bits/stdc++.h>
using namespace std;
int bit_tree[2001];
void update(int idx, int value)
{
	while(idx < 2001)
	{
		bit_tree[idx] += value;
		idx = idx + (idx & -idx);
	}
}
void range_update(int l, int r, int v)
{
	update(l, v);
	update(r+1, -v);
}

int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		scanf(" %d",&n);
		memset(bit_tree,0,sizeof(bit_tree));
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf(" %d %d",&a,&b);
			range_update(a,b,1);
		}
		int res = 0;
		int i = 0;
		for(int i=0;i<30;i++)
		{
			printf(" %d ",bit_tree[i]);
		}
		while(i<2001)
		{
			while(i<2001 && bit_tree[i] == 0)
			{
				i++;
			}
			int flag = 0;
			while(i<2001 && bit_tree[i] != 0)
			{
				flag = 1;
				i++;
			}
			if(flag)
			{
				res++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
