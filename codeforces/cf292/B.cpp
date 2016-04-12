#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf(" %d %d",&n,&m);
	int b[n];
	for(int i=0;i<n;i++)
	{
		b[i] = 0;
	}
	int g[m];
	for(int i=0;i<m;i++)
	{
		g[i] = 0;
	}
	int happy_boys;
	scanf(" %d",&happy_boys);
	for(int i=0;i<happy_boys;i++)
	{
		int idx;
		scanf(" %d",&idx);
		b[idx] = 1;
	}
	int happy_girls;
	scanf(" %d",&happy_girls);
	for(int i=0;i<happy_girls;i++)
	{
		int idx;
		scanf(" %d",&idx);
		g[idx] = 1;
	}
	int days = 2*n*m;
	int hbc = 0;
	int hgc = 0;
	for(int i=0;i<days;i++)
	{
		if(b[i%n] == 1 || g[i%m] == 1)
		{
			b[i%n] = 1;
			g[i%m] = 1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(b[i] == 1)
		{
			hbc++;
		}
	}
	for(int i=0;i<m;i++)
	{
		if(g[i] == 1)
		{
			hgc++;
		}
	}
	if(hbc == n || hgc == m)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
