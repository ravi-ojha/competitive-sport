#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int findmax(int g[], int n, int h[], int gain[1011][1011], int a[])
{
    int i;
    int mx = -999999;
    int j = 0;
    for(i=1;i<=n;i++)
    {
        //printf(" %d\n",g[i]);
        if(g[i] > mx && h[i] == 0)
        {
            mx = g[i];
            j = i;
        }
    }
    if(mx == -999999)
    {
        g[j] = -999999;
        return mx;
    }
    int yet = 999999;
    for(i=1;i<=n;i++)
    {
        if(g[i] == mx && yet >= gain[i][a[i]] && h[i] == 0)
        {
            yet = gain[i][a[i]];
            j = i;
        }
    }
    //printf("mx = %d, row = %d\n",mx,j);
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
            //printf("%2d:",i);
            int mx = -999999;
            for(j=1;j<=m;j++)
            {
                int tmp = gain[i][j] - loss[i][j];
                //printf(" %3d|%2d|%2d",tmp,gain[i][j],loss[i][j]);
                if(tmp > mx)
                {
                    mx = tmp;
                }
            }
            //printf("\n");
            if(mx <= gain[i][a[i]])
            {
                gross[i] = gain[i][a[i]];
                help[i] = 1;
            }
            else
            {
                gross[i] = mx;
            }
        }
//        int zzz = 0;
//        for(i=1;i<=n;i++)
//        {
//            if(help[i] == 0)
//            zzz++;
//            //printf(" %d",gross[i]);
//        }
//        printf(" %d\n",zzz);
        int res = 0;
        for(i=1;i<=k;i++)
        {
            int tmp = findmax(gross,n,help,gain,a);
            if(tmp == -999999)
            {
                break;
            }
            res = res + tmp;
        }
        //printf("%d\n",res);
        for(i=1;i<=n;i++)
        {
            if(gross[i] != -999999)
            {
                //printf("mx = %d, row = %d\n",gain[i][a[i]],i);
                res = res + gain[i][a[i]];
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
