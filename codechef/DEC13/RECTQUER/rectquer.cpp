#include<iostream>
#include<cstdio>
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
int main()
{
    int i,j,k;
    int n;
    //scanf(" %d",&n);
    fastRead_int(n);
    int a[301][301];
    int dp[301][301][12] = {0};
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //scanf(" %d",&a[i][j]);
            fastRead_int(a[i][j]);
        }
    }


    dp[0][0][a[0][0]]++;
    for(j=1;j<n;j++)
    {
        for(k=0;k<11;k++)
        {
            dp[0][j][k] = dp[0][j-1][k];
        }
        dp[0][j][a[0][j]]++;
    }
    for(i=1;i<n;i++)
    {
        for(k=0;k<11;k++)
        {
            dp[i][0][k] = dp[i-1][0][k];
        }
        dp[i][0][a[i][0]]++;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            for(k=0;k<11;k++)
            {
                dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] - dp[i-1][j-1][k];
            }
            dp[i][j][a[i][j]]++;
        }
    }

//    for(i=0;i<11;i++)
//    {
//        printf(" %d",dp[2][2][i]);
//    }
    int q;
    //scanf(" %d",&q);
    fastRead_int(q);
    while(q--)
    {
        int x,y,w,z;
        //scanf(" %d %d %d %d",&x,&y,&w,&z);
        fastRead_int(x);
        fastRead_int(y);
        fastRead_int(w);
        fastRead_int(z);
        x--;
        y--;
        w--;
        z--;
        int res, t = 0;
        int tt[11];


        if(x != 0 && y != 0)
        {
            for(k=0;k<11;k++)
            {
                tt[k] = dp[w][z][k] + dp[x-1][y-1][k];
            }


            for(k=0;k<11;k++)
            {
                tt[k] = tt[k] - dp[x-1][z][k] - dp[w][y-1][k];
            }

            t = 0;
            for(k=0;k<11;k++)
            {
                if(tt[k] != 0)
                {
                    t++;
                }
            }

            printf("%d\n",t);
            //res = res + t;
        }

        else if(x != 0)
        {
            for(k=0;k<11;k++)
            {
                tt[k] = dp[w][z][k] - dp[x-1][z][k];
            }
            t = 0;
            for(k=0;k<11;k++)
            {
                if(tt[k] != 0)
                {
                    t++;
                }
            }
            printf("%d\n",t);
            //t = res - t;
            //printf(" t = %d\n",t);
            //res = res - t;
        }

        else if(y != 0)
        {
            for(k=0;k<11;k++)
            {
                tt[k] = dp[w][z][k] - dp[w][y-1][k];
            }
            t = 0;
            for(k=0;k<11;k++)
            {
                if(tt[k] != 0)
                {
                    t++;
                }
            }
            printf("%d\n",t);
            //t = res - t;
            //printf(" t = %d\n",t);
            //res = res - t;
        }

        else
        {
            for(k=0;k<11;k++)
            {
                if(dp[w][z][k] != 0)
                {
                    t++;
                }
            }
            printf("%d\n",t);
        }

    }
    return 0;
}
