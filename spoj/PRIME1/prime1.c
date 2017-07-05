#include<stdio.h>
#define N 8
int main()
{
    int i,j;
    int isPrime[N+1] = {0};
    for(i=0;i<=N;i++)
    {
        printf(" %d",i);
    }
    printf("\n");
    for(i=0;i<=N;i++)
    {
        printf(" %d",isPrime[i]);
    }
    printf("\n");
    isPrime[0] = 1;
    isPrime[1] = 1;
    for(i=2;i*i<=N;i++)
    {
        if(isPrime[i] != 1)
        {
            j = 2*i;
            while(j<=N)
            {
                isPrime[j] = 1;
                j += i;
            }
        }
    }
    for(i=0;i<=N;i++)
    {
        printf(" %d",isPrime[i]);
    }
    printf("\n");
    for(i=0;i<=N;i++)
    {
        if(isPrime[i]!=1)
        printf(" %d",i);
    }
    return 0;
}
