#include<stdio.h>
#define LIMIT 1300000
int main()
{
    int i,j;
    int isPrime[LIMIT];
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(i=2;i<LIMIT;i++)
    {
        isPrime[i] = 1;
    }
    for(i=2;i*i<LIMIT;i++)
    {
        if (isPrime[i])
        {
            for(j=i*i;j<LIMIT;j=j+i)
            {
                isPrime[j] = 0;
            }
        }
    }
    int n,z=0;
    scanf(" %d",&n);
    for(i=0;z<n;i++)
    {
        if(isPrime[i])
        {
            printf("%d ",i);
            z++;
        }
    }
    return 0;
}
