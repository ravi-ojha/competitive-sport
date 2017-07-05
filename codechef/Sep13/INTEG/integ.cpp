#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
inline void fastRead_int(long long &x) {
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
int main()
{
    int n,i,j=0,x;
    //cin >> n;
    //scanf(" %d",&n);
    fastRead(n);
    long long a[n];
    long long b[n];
    for(i=0;i<n;i++)
    {
        //cin >> a[i];
        //scanf(" %lld",&a[i]);
        fastRead_int(a[i]);
        if(a[i] < 0)
        {
            b[j] = a[i];
            j++;
        }
    }
    //cin >> x;
    //scanf(" %d",&x);
    fastRead(x);
    std::sort(b,b+j);
//    for(i=0;i<j;i++)
//    {
//        cout << b[i] << " ";
//    }
    long long res = 0;
//    if(j==0 || x ==0)
//    {
//        cout <<"0"<<endl;
//        return 0;
//    }
    if (j<x)
    {
        for(i=0;i<j;i++)
        {
            res += (-1)*(b[i]);
        }
    }
    else
    {
        long long t = (-1)*(b[x-1]);
        res = x*t;
        for(i=0;i<(x-1);i++)
        {
            res += (-1)*(b[i]) - t;
        }
    }
    //cout << res << endl;
    printf("%lld\n",res);
    return 0;
}
