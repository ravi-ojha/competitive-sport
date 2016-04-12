#include <bits/stdc++.h>
using namespace std;
int main()
{
	int f[333] = {0};
	int m,t,r;
	scanf(" %d %d %d",&m,&t,&r);
	if(t < r)
	{
		printf("-1\n");
	}
	else
	{
		/*int res = r;
		int tmp;
		scanf(" %d",&tmp);
		int j = r;
		while(r >= 0)
		{
			f[tmp] += r;
			r--;
		}
		for(int i=2;i<=m;i++)
		{
			scanf(" %d",&tmp);
			if(f[tmp])
		}*/
		int ptmp = 0;
		int res = 0;
		int tmp;
		scanf(" %d",&tmp);
		res = r;
		ptmp = tmp;
		for(int i=2;i<=m;i++)
		{
			scanf(" %d",&tmp);
			res = res + (r - (tmp-ptmp));
			ptmp = tmp;
		}
		printf("%d\n",res);
	}


	return 0;
}
