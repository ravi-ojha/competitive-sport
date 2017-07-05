#include<stdio.h>
int main()
{
    int i,T,N,H,score,n;
    char z[15];
    for(i=0;i<10;i++)
    {
        z[i] = 'z';
    }
    z[i] = '\0';
    scanf(" %d %d %d",&T,&N,&H);
    while(T--)
    {
        n = N;
        while(n--)
        {
            printf("%s\n",z);
            fflush(stdout);
        }
        scanf(" %d",&score);
        fflush(stdout);
    }
    return 0;
}
