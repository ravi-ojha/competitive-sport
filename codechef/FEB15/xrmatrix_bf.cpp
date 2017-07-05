#include <bits/stdc++.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int a[200][200];
		for(int i=0;i<200;i++)
		{
			for(int j=0;j<200;j++)
			{
				a[i][j] = i^j;
			}
		}
		for(int i=0;i<33;i++)
		{
			for(int j=0;j<33;j++)
			{
				if(i == 0 || j == 0)
				{
					printf(ANSI_COLOR_RED " %2d" ANSI_COLOR_RESET,a[i][j]);
					//printf(" %2d",a[i][j]);
				}
				else
				{
					printf(" %2d",a[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
