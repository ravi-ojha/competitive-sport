#include <bits/stdc++.h>
#define LSOne(S) (S & (-S))
#define MOD 1000000007
using namespace std;
// Fenwick tree
int ft[1001];
int c[1001];
// Point query: Returns the value at position b in the array
int query(int b)
{
	int sum = 0;
	for (; b; b -= LSOne(b))
		sum += ft[b];
	return sum;
}

// Point update: Adds v to the value at position k in the array
void update(int k, int v)
{
	for (; k <= 1001; k += LSOne(k))
		ft[k] += v;
}

// Range update: Adds v to each element in [i...j] in the array
void range_update(int i, int j, int v)	{
	update(i, v);
	update(j + 1, -v);
}
int main()
{
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		int n;
		int x;
		scanf(" %d",&n);
		int j = n;
		for(int i=1;i<=n;i++)
		{
			ft[i] = 0;
			c[i] = j;
			j--;
			//cout << ft[i] << " ";
		}
		//cout << endl;
		for(int i=1;i<=n;i++)
		{
			scanf(" %d",&x);
			int idx = i-x;
			if(idx >= 1)
			{
				range_update(1,idx,1);
			}
		}
		long long res = 1;
		for(int i=1;i<=n;i++)
		{
			//cout << query(i) << endl;
			res = res*(c[i] - query(i));
			res %= MOD;
		}
		printf("%lld\n",res);
	}
	return 0;
}
