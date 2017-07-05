#include<cstdio>
#include<algorithm>
using namespace std;
struct fgfs
{
    long long s;
    long long f;
    long long p;
} ppl[100001];

bool comp1(const fgfs &a,const fgfs &b)
{
    return (a.p < b.p);
}
bool comp2(const fgfs &a,const fgfs &b)
{
    return (a.f < b.f);
}

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        long long n,k,i,x;
        int low,high;
        scanf(" %lld %lld",&n,&k);
        for(i=0; i<n; i++)
        {
            scanf(" %lld %lld %lld",&ppl[i].s,&ppl[i].f,&ppl[i].p);
        }
        sort(ppl,ppl+n,comp1);

        long long tt = 0;
        x = ppl[0].p;
        for(i=1; i<n; ++i)
        {
            if (ppl[i].p != x)
            {
                if (tt!=i-1)
                {
                    sort(ppl+tt,ppl+i,comp2);
                }
                tt=i;
                x=ppl[i].p;
            }
        }

        if (x!=i-1)
        {
            sort(ppl+tt,ppl+i,comp2);
        }

        i = 0;
        long long res = 1;
        if(n==0)
        {
            printf("0\n");
        }
        else
        {
            long long z = ppl[i].p;
            long long f = ppl[i].f;
            i += 1;
            while(i<n)
            {
                while(i<n && ppl[i].p == z)
                {
                    if(ppl[i].s >= f)
                    {
                        res += 1;
                        f = ppl[i].f;
                    }
                    i += 1;
                }
                if(i>=n)
                {
                    break;
                }
                z = ppl[i].p;
                f = ppl[i].f;
                res += 1;
                i += 1;
            }
            printf("%lld\n",res);
        }
    }
    return 0;
}
