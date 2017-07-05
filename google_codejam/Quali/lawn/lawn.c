#include<stdio.h>
int main()
{
    int t,p,i,j,k,l;
    scanf(" %d",&t);
    for(p=1;p<=t;p++)
    {
        int n,m,min = 9999,flag = 0;
        scanf(" %d %d",&n,&m);
        int a[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf(" %d",&a[i][j]);
                if(min>a[i][j])
                {
                    min = a[i][j];
                }
            }

        }
        printf("min = %d\n",min);
        int count = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i][j] == min)
                {
                    count = 0;
                    k = i;
                    for(l=0;l<m;l++)
                    {
                        if(a[k][j] == min)
                        {
                            count++;
                        }
                    }
                    printf(" %d\n",count);
                    if(count == m)
                    {
                        flag = 1;
                        goto here;
                    }
                    count = 0;
                    k = j;
                    for(l=0;l<n;l++)
                    {
                        if(a[l][k] == min)
                        {
                            count++;
                        }
                    }
                    printf(" %d\n",count);
                    if(count == n)
                    {
                        flag = 1;
                        goto here;
                    }
                }
            }
        }
        here:
        if(flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
