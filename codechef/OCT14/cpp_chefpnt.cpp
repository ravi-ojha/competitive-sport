#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,k,i,j,x,y;
	scanf(" %d %d %d",&n,&m,&k);
	int a[111][111] = {0};
	for(i=0;i<k;i++)
	{
		scanf(" %d %d",&x,&y);
		a[x-1][y-1]=1;
	}
	int lr = 0, ud = 0;
	int mark = 0;
	for(i=0;i<n;i++)
	{
		mark = 0;
		for(j=0;j<m;j++)
		{
			if(a[i][j]==0 && mark==0)
			{
				mark = 1;
				lr++;
			}
			else if(a[i][j]==1)
			{
				mark=0;
			}
		}
	}
	mark=0;
	for(i=0;i<m;i++)
	{
		mark=0;
		for(j=0;j<n;j++)
		{
			if(a[j][i]==0 && mark==0)
			{
				mark=1;
				ud++;
			}
			else if(a[j][i]==1)
			{
				mark=0;
			}
		}
	}
	mark=0;
	if(lr<ud)
	{
		printf("%d\n",lr);
		for(i=0;i<n;i++)
		{
			mark=0;
			for(j=0;j<m;j++)
			{
				if(a[i][j]==0 && mark==0)
				{
					mark=1;
					printf("%d %d 0\n",i+1,j+1);
				}
				else if(a[i][j]==1)
				{
					mark=0;
				}
			}
		}
	}
	else
	{
		printf("%d\n",ud);
		for(i=0;i<m;i++)
		{
			mark=0;
			for(j=0;j<n;j++)
			{
				if(a[j][i]==0 && mark==0)
				{
					mark=1;
					printf("%d %d 1\n",j+1,i+1);
				}
				else if(a[j][i]==1)
				{
					mark=0;
				}
			}
		}
	}

	return 0;
}
