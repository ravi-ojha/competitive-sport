#include <bits/stdc++.h>
using namespace std;

long long c[1000011] = {0};
long long h[1000011] = {0};
long long e[1000011] = {0};
long long f[1000011] = {0};

long long ch[1000011] = {0};
long long ce[1000011] = {0};
long long cf[1000011] = {0};

long long hc[1000011] = {0};
long long he[1000011] = {0};
long long hf[1000011] = {0};

long long ec[1000011] = {0};
long long eh[1000011] = {0};
long long ef[1000011] = {0};

long long fc[1000011] = {0};
long long fh[1000011] = {0};
long long fe[1000011] = {0};

int main()
{
	char p[1000001];
	scanf(" %s",p);
	int plen = strlen(p);
	for(int i=plen-1;i>=0;i--)
	{
		if(p[i] == 'c')
		{
			c[i+1] = c[i+2]+1;
		}
		else
		{
			c[i+1] = c[i+2];
		}
		if(p[i] == 'h')
		{
			h[i+1] = h[i+2]+1;
		}
		else
		{
			h[i+1] = h[i+2];
		}
		if(p[i] == 'e')
		{
			e[i+1] = e[i+2]+1;
		}
		else
		{
			e[i+1] = e[i+2];
		}
		if(p[i] == 'f')
		{
			f[i+1] = f[i+2]+1;
		}
		else
		{
			f[i+1] = f[i+2];
		}
	}
	/*for(int i=0;i<plen;i++)
	{
		printf(" %c",p[i]);
	}
	printf("\n");
	for(int i=0;i<plen;i++)
	{
		printf(" %d",c[i+1]);
	}
	printf("\n");
	for(int i=0;i<plen;i++)
	{
		printf(" %d",h[i+1]);
	}
	printf("\n");
	for(int i=0;i<plen;i++)
	{
		printf(" %d",e[i+1]);
	}
	printf("\n");
	for(int i=0;i<plen;i++)
	{
		printf(" %d",f[i+1]);
	}
	printf("\n");*/
	for(int i=1;i<1000001;i++)
	{
		if(p[i-1] == 'c')
		{
			ch[i] = ch[i-1] + h[i];
			ce[i] = ce[i-1] + e[i];
			cf[i] = cf[i-1] + f[i];
		}
		else
		{
			ch[i] = ch[i-1];
			ce[i] = ce[i-1];
			cf[i] = cf[i-1];
		}

		if(p[i-1] == 'h')
		{
			hc[i] = hc[i-1] + c[i];
			he[i] = he[i-1] + e[i];
			hf[i] = hf[i-1] + f[i];
		}
		else
		{
			hc[i] = hc[i-1];
			he[i] = he[i-1];
			hf[i] = hf[i-1];
		}

		if(p[i-1] == 'e')
		{
			ec[i] = ec[i-1] + c[i];
			eh[i] = eh[i-1] + h[i];
			ef[i] = ef[i-1] + f[i];
		}
		else
		{
			ec[i] = ec[i-1];
			eh[i] = eh[i-1];
			ef[i] = ef[i-1];
		}

		if(p[i-1] == 'f')
		{
			fc[i] = fc[i-1] + c[i];
			fh[i] = fh[i-1] + h[i];
			fe[i] = fe[i-1] + e[i];
		}
		else
		{
			fc[i] = fc[i-1];
			fh[i] = fh[i-1];
			fe[i] = fe[i-1];
		}
	}
	int q;
	scanf(" %d",&q);
	while(q--)
	{
		char a,b;
		int l,r;
		scanf(" %c %c %d %d",&a,&b,&l,&r);
		//printf(" %c %c %d %d\n",a,b,l,r);
		if(a == 'c' && b == 'h')
		{
			long long nc = c[l] - c[r+1];
			long long res = ch[r] - ch[l-1];
			res = res - nc*h[r+1];
			printf("%lld\n",res);
		}
		if(a == 'c' && b == 'e')
		{
			long long nc = c[l] - c[r+1];
			long long res = ce[r] - ce[l-1];
			res = res - nc*e[r+1];
			printf("%lld\n",res);
		}
		if(a == 'c' && b == 'f')
		{
			long long nc = c[l] - c[r+1];
			long long res = cf[r] - cf[l-1];
			res = res - nc*f[r+1];
			printf("%lld\n",res);
		}
		if(a == 'h' && b == 'c')
		{
			long long nh = h[l] - h[r+1];
			long long res = hc[r] - hc[l-1];
			res = res - nh*c[r+1];
			printf("%lld\n",res);
		}
		if(a == 'h' && b == 'e')
		{
			long long nh = h[l] - h[r+1];
			long long res = he[r] - he[l-1];
			res = res - nh*e[r+1];
			printf("%lld\n",res);
		}
		if(a == 'h' && b == 'f')
		{
			long long nh = h[l] - h[r+1];
			long long res = hf[r] - hf[l-1];
			res = res - nh*f[r+1];
			printf("%lld\n",res);
		}
		if(a == 'e' && b == 'c')
		{
			long long ne = e[l] - e[r+1];
			long long res = ec[r] - ec[l-1];
			res = res - ne*c[r+1];
			printf("%lld\n",res);
		}
		if(a == 'e' && b == 'h')
		{
			long long ne = e[l] - e[r+1];
			long long res = eh[r] - eh[l-1];
			res = res - ne*h[r+1];
			printf("%lld\n",res);
		}
		if(a == 'e' && b == 'f')
		{
			long long ne = e[l] - e[r+1];
			long long res = ef[r] - ef[l-1];
			res = res - ne*f[r+1];
			printf("%lld\n",res);
		}
		if(a == 'f' && b == 'c')
		{
			long long nf = f[l] - f[r+1];
			long long res = fc[r] - fc[l-1];
			res = res - nf*c[r+1];
			printf("%lld\n",res);
		}
		if(a == 'f' && b == 'h')
		{
			long long nf = f[l] - f[r+1];
			long long res = fh[r] - fh[l-1];
			res = res - nf*h[r+1];
			printf("%lld\n",res);
		}
		if(a == 'f' && b == 'e')
		{
			long long nf = f[l] - f[r+1];
			long long res = fe[r] - fe[l-1];
			res = res - nf*e[r+1];
			printf("%lld\n",res);
		}
	}
	return 0;
}
