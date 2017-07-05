#include<cstdio>
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
inline void fastRead(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
     x = -x;
}
using namespace std;
int main()
{
    int t;
    //scanf(" %d",&t);
    fastRead(t);
    while(t--)
    {
        int n,i,x;
        //scanf(" %d",&n);
        fastRead(n);
        int j = n/2;
        long long count = 0;
        for(i=1;i*i<n;i++)
        {
            x = n/i;
            count += x;
            x = n/x;
            count += x;
        }
        long long c = (long long)n*(long long)n;
        count = count + (n-j);
        long long d = gcd(count,c);
        printf("%lld/%lld\n",count/d,c/d);
    }
    return 0;
}
