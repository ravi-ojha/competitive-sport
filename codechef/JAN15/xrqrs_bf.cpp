#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	scanf(" %d",&m);
	int a[500005];
	int idx = 1;
	while(m--)
	{
		int type;
		scanf(" %d",&type);
		if(type == 0)
		{
			int x;
			scanf(" %d",&x);
			a[idx] = x;
			idx++;
		}
		else if(type == 1)
		{
			int l,r,x;
			int y;
			int mx = -1;
			scanf(" %d %d %d",&l,&r,&x);
			for(int i=l;i<=r;i++)
			{
				int tmx = x^a[i];
				if(tmx > mx)
				{
					mx = tmx;
					y = a[i];
				}
			}
			printf("%d\n",y);
		}
		else if(type == 2)
		{
			int k;
			scanf(" %d",&k);
			idx -= k;
		}
		else if(type == 3)
		{
			int cnt = 0;
			int l,r,x;
			scanf(" %d %d %d",&l,&r,&x);
			for(int i=l;i<=r;i++)
			{
				if(a[i] <= x)
				{
					cnt++;
				}
			}
			printf("%d\n",cnt);
		}
		else if(type == 4)
		{
			int l,r,k;
			scanf(" %d %d %d",&l,&r,&k);
			vector <int> b;
			for(int i=l;i<=r;i++)
			{
				b.push_back(a[i]);
			}
			sort(b.begin(),b.end());
			printf("%d\n",b[k-1]);
		}
	}
	return 0;
}
