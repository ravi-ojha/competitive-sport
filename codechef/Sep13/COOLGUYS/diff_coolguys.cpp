#include<cstdio>
#include<math.h>
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
inline void fastRead(long long &x) {
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
inline void fastRead_int(int &x) {
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
    fastRead_int(t);
    while(t--)
    {
        int i;
        long long n;
        //scanf(" %d",&n);
        fastRead(n);
        long long c = n*n;
        //int j = n/2;
        long long count = 0;
        long double m = (long double)n;
        long double temp = sqrt(m);
        for(i=1;i<=temp;i++)
        {
            count += n/i;
        }
        long long x = (long long)temp;
        x = x*x;
        count = count + (count - x);
        //printf("%lld\n",count);
        //printf("%llu/%llu\n",count,c);
        long long d = gcd(count,c);
        printf("%llu/%llu\n",count/d,c/d);
    }
    return 0;
}
