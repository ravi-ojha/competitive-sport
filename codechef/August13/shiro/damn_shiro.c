#include<stdio.h>
int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}
float a[101][10001];
int flags[101];
float p[101];
int main()
{
    int t;
    //scanf(" %d",&t);
    t = read();
    while(t--)
    {
        int n,i,j;
        //scanf(" %d",&n);
        n = read();
        int sum = 0;
        for(i = 1; i <= n; i++)
        {
                //scanf(" %d",&flags[i]);
                flags[i] = read();
                sum += flags[i];
        }
        for(i = 0; i <= n; i++)
        {
            for(j = sum; j >= 0; j--)
            {
                a[i][j] = 0;
            }
        }
        float ans = 0;
        for(i = 1; i <= n; i++)
        {
                //scanf(" %f",&p[i]);
                p[i] = read();
                p[i] /= 100.0;
        }
        a[0][0] = 1;
        for(i = 1; i <= n; i++)
        {
            for(j = sum; j >= 0; j--)
            {
                    a[i][j+flags[i]] += a[i-1][j]*p[i];
                    a[i][j] += a[i-1][j]*(1.0-p[i]);
            }
        }
        for(i = (sum+1)/2; i <= sum; i++)
        {
            ans += a[n][i];
        }
        printf("%f\n", ans);
    }
    return 0;
}
