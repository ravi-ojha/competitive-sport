#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,j,i,count=0;
        scanf(" %d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                if((i*j)%(i+j) == 0)
                {count++;
                //printf(" i = %d j = %d\n",i,j);
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
