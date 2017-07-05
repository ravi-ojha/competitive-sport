#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long f[1000011];
void fact()
{
    f[0] = 1;
    int i = 1;
    while(i<1000011)
    {
        f[i] = f[i-1]*i;
        f[i] = f[i]%MOD;
        i++;
    }
}
long long fast_pow(long long a,long long n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
        {
            result = result*value;
            result = result%MOD;
        }
        value = value*value;
        value = value%MOD;
        power /= 2;
    }
    return result;
}
long long inv(long long x)
{
    return fast_pow(x,MOD-2);
}
int main()
{
	fact();
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long n;
		scanf(" %lld",&n);
		long long res = 0;
		int k = 1;
		int nn = n-k+1;
		while(nn>=k)
		{
			long long tmp = f[nn];
			long long tmp2 = f[k];
			long long tmp3 = f[nn-k];
			tmp2 = (tmp2*tmp3)%MOD;
			tmp2 = inv(tmp2);
			tmp = tmp*tmp2;
			tmp %= MOD;
			res += tmp;
			res %= MOD;
			nn--;
			k++;
		}
		printf("%lld\n",res);
	}
	return 0;
}
