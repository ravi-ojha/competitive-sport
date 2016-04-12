#include<stdio.h>
int main()
{
    int n,k,i,j;
    scanf(" %d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        if(i==k && k!=0)
        {
            j = i+1;
            printf("%d ",j);
        }
        else if(i == (k+1) && k!=0)
        {
            j = i-1;
            printf("%d ",j);
        }
        else
        {
            printf("%d ",i);
        }
    }
    return 0;
}
