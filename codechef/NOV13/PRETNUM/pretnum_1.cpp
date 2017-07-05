#include<iostream>
#include<cstdio>
#define UPTO 999999
using namespace std;
int prime[1000000] = {0};
void sieve()
{
    prime[0] = 1;
    prime[1] = 1;
    int i = 2;
    int j;
    while (i*i <= UPTO)
    {
        j = 2*i;
        if (prime[i] != 1)
        {
            while(j<UPTO)
            {
                prime[j] = 1;
                j += i;
            }
        }
        i += 1;
    }
}
int main()
{
    sieve();
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        long long i,j,m,n,from,k;
        long long ourRange[1000001];

        scanf(" %lld %lld",&m,&n);
        long long z;
        for(i=m,z=0;i<=n;i++,z++)
        {
            ourRange[z] = i;
        }
        for(i=2;i*i<n;i++)
        {
            from = m/i;
            from*=i;
            for(j=from;j<=n;j=j+i)
            {
                if(j!=i && j>=m)
                ourRange[j-m] = 0;
            }
        }
        if(m==1)
        {
            ourRange[0] = 0;
        }
        i = 2;
        long long res = 0;
        while(i<UPTO)
        {
            if (prime[i] == 0)
            {
                j = i;
                k = 1;
                while (j < m)
                {
                    j = j*i;
                    k += 1;
                }
                while(j<=n)
                {
                    if(prime[k+1] == 0)
                    {
                        ourRange[j-m] = j;
                    }
                    else
                    {
                        ourRange[j-m] = 0;
                    }
                    j = j*i;
                    k += 1;
                }
            }
            i += 1;
        }
        for(i=m;i<=n;i++)
        {
            if(ourRange[i-m])
            {
                res++;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
