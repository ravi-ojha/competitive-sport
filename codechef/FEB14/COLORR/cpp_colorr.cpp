#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int max_in_arr(int g[],int n, int h[])
{
    int i,mx = -999999,j=0;
    for(i=1;i<=n;i++)
    {
        if(g[i] > mx && h[i] == 0)
        {
            mx = g[i];
            j = i;
        }
    }
    g[j] = -999999;
    return mx;
}
int main()
{
    int t,i,j;
    scanf(" %d",&t);
    while(t--)
    {
        int n,m,k;
        scanf(" %d %d %d",&n,&m,&k);
        int a[1011];
        for(i=1;i<=n;i++)
        {
            scanf(" %d",&a[i]);
        }
        int gain[1011][1011];
        int loss[1011][1011];
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf(" %d",&gain[i][j]);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf(" %d",&loss[i][j]);
            }
        }
        //int net[1011][1011];
        int gross[1011];
        int help[1011] = {0};
        gross[0] = 0;
        for(i=1;i<=n;i++)
        {
            int mx = -999999;
            for(j=1;j<=m;j++)
            {
                int tmp = gain[i][j] - loss[i][j];
                if(tmp > mx)
                {
                    mx = tmp;
                }
            }

            gross[i] = mx;
            if(gross[i] <= gain[i][a[i]])
            {
                help[i] = 1;
            }
        }
        //sort(gross+1,gross+n+1,greater<int>());
        int res = 0;
        for(i=1;i<=k;i++)
        {
            //printf("gross = %d\n",gross[i]);i
            int tt = max_in_arr(gross,n,help);
            if(tt < 0)
            {
                //printf("yo-------\n");
                break;
            }
            res += tt;
        }
        //printf("%d\n",res);
        for(i=1;i<=n;i++)
        {
            if(gross[i] != -999999)
            res += gain[i][a[i]];
        }
        printf("%d\n",res);
    }
    return 0;
}
