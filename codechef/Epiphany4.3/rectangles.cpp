#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int m,n;
		scanf(" %d %d",&m,&n);
		m--;
		n--;
		long long a;
		scanf(" %lld",&a);
		vector < pair <long long, long long> > factors;
		long long f1, f2;
		for(long long i=1;i*i <= a;i++)
		{
			if(a%i == 0)
			{
				f1 = a/i;
				if(i==f1)
				{
					factors.push_back(make_pair(i,f1));
				}
				else
				{
					factors.push_back(make_pair(i,f1));
					factors.push_back(make_pair(f1,i));
				}
			}
		}
		long long res = 0;
		for(int i=0;i<factors.size();i++)
		{
			if(factors[i].first > n || factors[i].second > m)
			{
				continue;
			}
			else
			{
				res = res + (n-factors[i].first+1)*(m-factors[i].second+1);
			}
		}
		printf("%lld\n",res);
		factors.clear();
	}
	return 0;
}
