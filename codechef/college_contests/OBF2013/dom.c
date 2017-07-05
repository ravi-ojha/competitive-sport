#include<stdio.h>
long long int read()
{
    long long int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

int main()
{
    int T;
    T = read();
    while(T--)
    {
        long long int n;
        long long int ans;
        n = read();
        //printf("%llu\n",n);
        if(n==1)
        {
            printf("1\n");
        }
        else
        {ans = n/2;
        ans = ans%1000000007;
        printf("%llu\n",ans+1);}
    }
    return 0;
}
