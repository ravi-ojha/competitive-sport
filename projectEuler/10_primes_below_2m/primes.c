#include<stdio.h>
#define UPTO 2000001
int main()
{
    int a[UPTO],i,j;
    long long sum = 0;
    for(i=1;i<UPTO;i++)
    {
        a[i] = i;
    }
    for(i=2;i*i<UPTO;i++)
    {
        if(a[i] == -1)
        continue;
        for(j=i;j<UPTO;j=j+i)
        {
            a[j] = -1;
        }
        a[i] = i;
    }
    for(i=2;i<UPTO;i++)
    {
        if(a[i] != -1)
        {
            sum = sum+a[i];
        }
    }
    printf("sum = %lld\n",sum);
    return 0;
}
