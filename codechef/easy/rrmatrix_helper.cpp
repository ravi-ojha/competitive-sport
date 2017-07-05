#include<cstdio>
int main()
{
    int i,j,n,m;
    n = 101;
    m = 605;
    int a[n][m], b[n][m];
    int z = 1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            a[i][j] = z;
            z++;
        }
    }
    z = 1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i] = z;
            z++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %5d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %5d",b[i][j]);
        }
        printf("\n");
    }
    int c = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j] == b[i][j])
            {
                printf(" i = %d  j = %d\n",i,j);
                c++;
            }
        }
    }
    printf("c = %d\n",c);
    return 0;
}
