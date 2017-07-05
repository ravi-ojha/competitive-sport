#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,p;
        scanf(" %d %d",&n,&p);
        char s1[n*n*n],s2[n*n*n];
        char dp1[40][40][40], dp2[40][40][40];
        scanf(" %[^\n]",s1);
        scanf(" %[^\n]",s2);
        int i,j,k,l;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    for(l=0;l<n;l++)
                    {

                    }
                    dp1[i][j][k] = s1[i*n*n + j*n + k];
                    dp2[i][j][k] = s2[i*n*n + j*n + k];
                }
            }
        }
        printf("-1\n");
    }
    return 0;
}
