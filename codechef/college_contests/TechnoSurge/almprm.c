#include<stdio.h>
long int read()
{
    long int _n = 0;
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
        unsigned long p;
        long int m;
        long int i;
        long int n;
        long int count = 0;
        n = read();
        p = isqrt(n);
        printf("p = %lu\n",p);
        m = (int)p;
        printf("m = %lu\n",m);
        if(n==1)
        {
            printf("NO\n");
            goto hell;
        }
        if(m==p)
        {
            count = 1;
            for(i=2;i<m;i++)
            {
                if(n%i == 0)
                {
                    count++;
                    break;
                }
            }
        }
        if(count == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        hell:
        ;
    }
    return 0;
}
