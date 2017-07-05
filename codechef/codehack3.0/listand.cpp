#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int k;
		scanf(" %d",&k);
		int a[k];
		for(int i=0;i<k;i++)
		{
			scanf(" %d",&a[i]);
		}
		int res = -1;
		int base;
		int tmp;
		for(int i=0;i<k;i++)
		{
			base = a[i];
			int flag = 1;
			for(int j=0;j<k;j++)
			{
				if(i!=j)
				{
					if(flag)
					{
						tmp = a[j];
						flag = 0;
					}
					else
					{
						tmp = tmp&a[j];
					}
				}
			}
			if(tmp == base)
			{
				res = base;
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
