#include<stdio.h>
#define MOD 1000000007
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
int main()
{
    long long i,j;
    int a[1001][11] = {{0},{0}};
    for(i=1;i<11;i++)
    {
        a[2][i] = i;
        a[3][i] = i*(i-1);
        a[4][i] = i*(i+(i-1)*(i-1));
    }
    for(i=5;i<1001;i++)
    {
        if(i&1)
        {
            for(j=1;j<11;j++)
            {
                a[i][j] = (j*(a[i-1][j]-1))%MOD;
            }
        }
        else
        {
            for(j=1;j<11;j++)
            {
                a[i][j] = (j*(a[i-1][j]+1))%MOD;
            }
        }
    }
    for(i=0;i<100;i++)
    {
        for(j=0;j<11;j++)
        {
            printf(" %4d",a[i][j]);
        }
        printf("\n");
    }
    int t;
    t = read();
    while(t--)
    {
        int n,m;
        n = read();
        m = read();
        printf("%d\n",a[n][m]);
    }
    return 0;
}
