#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int abs(int i)
{
    if(i<0)
    {
        return i*(-1);
    }
    return i;
}
int main()
{
    int n,m,i,j;
    scanf(" %d %d",&n,&m);
    char a[n];
    scanf(" %s",a);
    int b[n];
    int dp[n][10];
    for(i=0;i<n;i++)
    {
        b[i] = a[i] - '0';
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
            dp[i][j] = 0;
        }
    }
    dp[0][b[0]]++;
    for(i=1;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
            dp[i][j] = dp[i-1][j];
        }
        dp[i][b[i]]++;
    }
    while(m--)
    {
        int x;
        scanf(" %d",&x);
        x--;
        int res = 0;
        for(j=0;j<10;j++)
        {
            //printf("dp = %d\n",dp[x][j]);
            res = res + dp[x][j]*(abs(b[x]-j));
        }
        printf("%d\n",res);
    }
    return 0;
}
