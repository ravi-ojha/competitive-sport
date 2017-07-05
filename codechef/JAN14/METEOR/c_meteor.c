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
int a[1001][1001];
int b[1001][1001];
int dp[1001][1001];
int main()
{
    int n,m,k,x,y,i,j,l,t;
    //scanf(" %d %d %d",&n,&m,&k);
    n = read();
    m = read();
    k = read();
    //scanf(" %d %d",&n,&m);


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j] = 0;
            b[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for(i=0;i<k;i++)
    {
        //scanf(" %d %d",&x,&y);
        x = read();
        y = read();
        x--;
        y--;
        a[x][y] = 1;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j] == 1)
            {
                b[i][j] = 0;
            }
            else
            {
                if(j==0)
                {
                    b[i][j] = 1;
                }
                else
                {
                    b[i][j] = b[i][j-1] + 1;
                }
            }
        }
    }
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<m;j++)
//        {
//            printf(" %d",b[i][j]);
//        }
//        printf("\n");
//    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(b[i][j])
            {
                t = b[i][j];
                for(l=i;l>=0;l--)
                {
                    if(b[l][j] < t)
                    {
                        t = b[l][j];
                    }
                    if(t==0)
                    {
                        break;
                    }
                    if(dp[l][i] < (t*(i-l+1)))
                    {
                        dp[l][i] = t*(i-l+1);
                    }
                }
            }
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            if(dp[j][i+j] < dp[j][i+j-1])
            {
                dp[j][i+j] = dp[j][i+j-1];
            }
            if(dp[j][i+j] < dp[j+1][i+j])
            {
                dp[j][i+j] = dp[j+1][i+j];
            }
        }
    }
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<m;j++)
//        {
//            printf(" %d",dp[i][j]);
//        }
//        printf("\n");
//    }
    int q;
    //scanf(" %d",&q);
    q = read();
    while(q--)
    {
        int u,v;
        //scanf(" %d %d",&u,&v);
        u = read();
        v = read();
        printf("%d\n",dp[u-1][v-1]);
    }
    return 0;
}
