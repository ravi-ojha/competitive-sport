#include<cstdio>
#include<cmath>
int main()
{
    int n,i,j,k;
    scanf(" %d",&n);
    float z = sqrt(n);
    int zz = sqrt(n);
    int c = 4;
    if (z == zz)
    {
        c = 1;
        goto japan;
    }
    for(i=1;i<=z;i++)
    {
        for(j=1;j<=z;j++)
        {
            if(i*i + j*j == n)
            {
                c = 2;
                goto japan;
            }
        }
    }
    for(i=1;i<=z;i++)
    {
        for(j=1;j<=z;j++)
        {
            for(k=1;k<=z;k++)
            {
                if(i*i + j*j + k*k == n)
                {
                    //printf(" %d %d %d",i,j,k);
                    c = 3;
                    goto japan;
                }
            }
        }
    }
    japan:
    printf("%d\n",c);
    return 0;
}
