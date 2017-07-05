#include <cstdio>
#include <iostream>
using namespace std;
#define PASS_SIZE 10000001
int prime[PASS_SIZE] = {0};
int cost[PASS_SIZE];
int n;
int a[351][351];
int vis[351][351];
void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    int i = 2,j;
    while(i*i <= PASS_SIZE)
    {
        j = 2*i;
        if (prime[i] != 1)
        {
            while (j<PASS_SIZE)
            {
                prime[j] = 1;
                j += i;
            }
        }
        i += 1;
    }
}
void calculate_prime_cost()
{
	int curr = 0;
	for(int i=0;i<PASS_SIZE;i++)
	{
		cost[i] = curr;
		if(prime[i] == 0)
		{
			curr++;
		}
	}
}
void dfs_even(int i, int j)
{
	if(i<1 || j < 1 || i > n || j > n)
	{
		return;
	}
	if(vis[i][j])
	{
		return;
	}
	if(a[i][j]%2) // if odd then return
	{
		return;
	}
	if(prime[a[i][j]] == 0) // if prime then return
	{
		return;
	}
	vis[i][j] = 1;
	dfs_even(i+1,j);
	dfs_even(i,j+1);
	dfs_even(i-1,j);
	dfs_even(i,j-1);
}
void dfs_odd(int i, int j)
{
	if(i<1 || j < 1 || i > n || j > n)
	{
		return;
	}
	if(vis[i][j])
	{
		return;
	}
	if(a[i][j]%2 == 0) // if even then return
	{
		return;
	}
	if(prime[a[i][j]] == 0) // if prime then return
	{
		return;
	}
	vis[i][j] = 1;
	dfs_odd(i+1,j);
	dfs_odd(i,j+1);
	dfs_odd(i-1,j);
	dfs_odd(i,j-1);
}
int main()
{
	sieve();
	calculate_prime_cost();
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long res = 0;
		scanf(" %d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf(" %d",&a[i][j]);
				vis[i][j] = 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(prime[a[i][j]] == 0)
				{
					res += cost[a[i][j]];
				}
				else
				{
					if(!vis[i][j])
					{
						if(a[i][j]%2 == 0)
						{
							res += a[i][j]/2;
							dfs_even(i,j);
						}
						else
						{
							res += (a[i][j]/2 + 2);
							dfs_odd(i,j);
						}
					}
				}
				//printf("%4lld",res);
			}
			//printf("\n");
		}
		printf("%lld\n",res);
	}
	return 0;
}
