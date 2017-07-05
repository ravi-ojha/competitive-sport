#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
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
    int t,i,j;
    //scanf(" %d",&t);
    fastRead_int(t);
    while(t--)
    {
        int n,m,k;
        int res = 0;
        //scanf(" %d %d %d",&n,&m,&k);
        fastRead_int(n);
        fastRead_int(m);
        fastRead_int(k);
        int a[1011];
        for(i=1;i<=n;i++)
        {
            //scanf(" %d",&a[i]);
            fastRead_int(a[i]);
        }
        int gain[1011][1011];
        int loss[1011][1011];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                //scanf(" %d",&gain[i][j]);
                fastRead_int(gain[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                //scanf(" %d",&loss[i][j]);
                fastRead_int(loss[i][j]);
            }
        }
        int gross[1011];
        for(i=1;i<=n;i++)
        {
            int tmp = gain[i][1] - loss[i][1] - gain[i][a[i]];
            for(j=1;j<=m;j++)
            {
                int tt = gain[i][j] - loss[i][j] - gain[i][a[i]];
                if(tmp < tt)
                {
                    tmp = tt;
                }
            }
            gross[i] = tmp;
            res += gain[i][a[i]];
        }
        sort(gross+1,gross + n + 1);
        i = n;
        while(k>0)
        {
            int mx = gross[i];
            if(mx < 0)
            {
                break;
            }
            res += mx;
            i--;
            k--;
        }
        printf("%d\n",res);
    }
    return 0;
}
