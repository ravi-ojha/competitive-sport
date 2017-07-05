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
using namespace std;
int a[1001][1001] = {0};
int b[1001][1001] = {0};
int dp[1001][1001] = {0};
int main()
{
    int n,m,k,x,y,i,j,l,t;
    //scanf(" %d %d %d",&n,&m,&k);
    fastRead_int(n);
    fastRead_int(m);
    fastRead_int(k);
    //scanf(" %d %d",&n,&m);


//    for(i=0;i<1001;i++)
//    {
//        for(j=0;j<1001;j++)
//        {
//            a[i][j] = 0;
//            b[i][j] = 0;
//            dp[i][j] = 0;
//        }
//    }
    for(i=0;i<k;i++)
    {
        //scanf(" %d %d",&x,&y);
        fastRead_int(x);
        fastRead_int(y);
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
    fastRead_int(q);
    //scanf(" %d",&q);
    while(q--)
    {
        int u,v;
        //scanf(" %d %d",&u,&v);
        fastRead_int(u);
        fastRead_int(v);
        printf("%d\n",dp[u-1][v-1]);
    }
    return 0;
}
