#include<iostream>
#include<cstdio>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k,i,j,x;
        scanf(" %d %d",&n,&k);
        int a[n+1][k+1];
        int z[k+1];
        int s[k+1];
        int r[n+2];
        int q = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            {
                scanf(" %d",&a[i][j]);
            }
        }
        for(j=0;j<k;j++)
        {
            scanf(" %d",&z[j]);
            s[j] = 0;
        }
        bool flag = true;
        for(i=0;i<n;i++)
        {
            flag = true;
            for(j=0;j<k;j++)
            {
                if((s[j]+a[i][j]) > z[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                for(x=0;x<k;x++)
                {
                    s[x] = s[x] + a[i][x];
                }
                q++;
                r[q] = i+1;
            }
        }
        printf("%d\n",q);
        for(i=1;i<=q;i++)
        {
            printf("%d ",r[i]);
        }
        printf("\n");
    }
    return 0;
}
