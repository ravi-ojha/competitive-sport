#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long pow2[61];

//Following module deals with complete box
// x is 2**n and y is 2**(n+1)
pair <long long, long long> complete_box(long long x, long long y)
{
	if(x==1 && y == 2)
	{
		return make_pair(0,2);
	}
	if ( x==y )
	{
		return make_pair(0,1);
	}
	// walk stores longest walk and r stores count of such walks
	long long walk = y-x-1; // -1 because questions asks for 0-based index
	long long r = y-x;
	r %= MOD;
	r *= r;
	r %= MOD;
	return make_pair(walk,r);
}

//Following module deals with bottom-right box of the range
// 2**(n-1) < x < 2**n and y is 2**n
pair <long long, long long> bottom_right_corner(long long x, long long y)
{
	if(x==y)
	{
		return make_pair(0,1);
	}
	long long diff = y-x;
	int i=0;
	while(pow2[i] < diff)
	{
		i++;
	}
	long long walk = pow2[i]-1; //longest possible walk

	long long r = diff - pow2[i-1];
	r %= MOD;
	r *= 2;
	r %= MOD;
	if(diff == pow2[i])
	{
		i++;
	}
	r *= pow2[i-1];
	r %= MOD;
	return make_pair(walk,r);
}

//Following module deals with top-left box of the range
//x is 2**n and 2**n < y < 2**(n+1)
pair <long long, long long> top_left_corner(long long x, long long y)
{
	if(x==y)
	{
		return make_pair(0,1);
	}
	long long diff = y-x+1;
	int i=0;
	while(pow2[i] < diff)
	{
		i++;
	}
	long long walk = pow2[i]-1; //longest possible walk

	long long r = diff - pow2[i-1];
	r %= MOD;
	r *= 2;
	r %= MOD;
	if(diff == pow2[i])
	{
		i++;
	}
	r *= pow2[i-1];
	r %= MOD;
	return make_pair(walk,r);
}

int main()
{
	pow2[0] = 1;
	for(int i=1;i<60;i++) //because 2**59 is 576460752303423488L (<10**18) and 2**60 is 1152921504606846976L (>10**18)
	{
		pow2[i] = 2*pow2[i-1];
		//printf(" %lld\n",pow2[i]);
	}
	int t;
	scanf(" %d",&t);
	while(t--)
	{
		long long l,r;
		scanf(" %lld %lld",&l,&r);
		long long k = 0; //Maximum Walk Length
		long long c = 0; //Count of such maximum walks
		int flag = 0;
		for(int i=0;i<60;i++)
		{
			if(l <= pow2[i] && r >= pow2[i])
			{
				flag++;
			}
		}
		if(flag = 0) //means l and r need to be shifted
		{
			int j = 0;
			while(pow2[j] < l)
			{
				j++;
			}
			j--;
			l = l - pow2[j];
			r = r - pow2[j];
		}
		printf(" %lld %lld",l,r);
		/*if(l==1)
		{
			if(r==1)
			{
				printf("0 1\n");
			}
			if(r==2)
			{
				printf("0 2\n");
			}
			if(r >= 3)
			{

			}
			continue;
		}*/

		int i = 0;
		while(pow2[i] < l)
		{
			i++;
		}
		long long lf = pow2[i];
		long long rf=1,rff=1;
		i = 0;
		while(pow2[i] <= r)
		{
			i++;
		}
		if((i-1) >= 0)
			rf = pow2[i-1];

		if((i-2) >= 0)
			rff = pow2[i-2];

		pair <long long, long long> tmp1,tmp2,tmp3;
		if(lf == rf) //no complete box in between
		{
			tmp1 = bottom_right_corner(l,lf);
			tmp2 = top_left_corner(rf,r);
			if(tmp1.first == tmp2.first)
			{
				k = tmp1.first;
				c = tmp1.second;
				c *= c;
				c %= MOD;
			}
			else
			{
				if(tmp1.first > tmp2.first)
				{
					k = tmp1.first;
					c = tmp1.second;
				}
				else
				{
					k = tmp2.first;
					c = tmp2.second;
				}
			}
		}
		else
		{
			tmp1 = bottom_right_corner(l,lf);
			tmp2 = top_left_corner(rf,r);
			tmp3 = complete_box(rff,rf);
			long long zz = max(tmp1.first, tmp2.first);
			zz = max(zz,tmp3.first);
			k = zz;
			if(tmp1.first == k)
			{
				c = tmp1.second;
			}
			if(tmp2.first == k)
			{
				c += tmp2.second;
				c %= MOD;
			}
			if(tmp3.first == k)
			{
				c += tmp3.second;
				c %= MOD;
			}
		}
		printf("%lld %lld\n",k,c);
	}
	return 0;
}
