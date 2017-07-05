#include<stdio.h>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i,k;
        scanf(" %d %d",&n,&k);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        if(n==2 && k==1)
        {
            printf("1\n");
            continue;
        }
        if(k>(n/2))
        {
            printf("-1\n");
        }
        else
        {
            for(i=1;i<=k;i++)
            {
                printf("%d ",2*i);
            }
            printf("\n");
        }
    }
    return 0;
}
