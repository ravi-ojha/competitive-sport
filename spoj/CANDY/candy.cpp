#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(true)
	{
		int n;
		scanf(" %d",&n);
		if(n == -1)
		{
			return 0;
		}
		else
		{
			int a[n];
			int s = 0;
			for(int i=0;i<n;i++)
			{
				scanf(" %d",&a[i]);
				s += a[i];
			}
			if(s%n == 0)
			{
				int res = 0;
				int common = s/n;
				for(int i=0;i<n;i++)
				{
					if(a[i] < common)
					{
						res += (common - a[i]);
					}
				}
				printf("%d\n",res);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}
