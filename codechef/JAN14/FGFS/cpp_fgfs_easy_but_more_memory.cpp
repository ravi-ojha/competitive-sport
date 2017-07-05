#include<cstdio>
#include<algorithm>
using namespace std;
struct fgfs{
long long s;
long long f;
long long p;
long long toSort;
}ppl[100001];
bool comp1(const fgfs &a,const fgfs &b)
{
    return (a.toSort < b.toSort);
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        long long n,k,i;
        int low,high;
        scanf(" %lld %lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf(" %lld %lld %lld",&ppl[i].s,&ppl[i].f,&ppl[i].p);
            ppl[i].toSort = ppl[i].p*1000000000 + ppl[i].f;
        }
        sort(ppl,ppl+n,comp1);
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
