#include<stdio.h>
#define LIMIT 50
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
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,m;
        scanf(" %d %d",&n,&m);
        int result = 0;
        for(i=n;i<=m;i++)
        {
            j = i;
            int digitSum = 0;
            while(j!=0)
            {
                digitSum += j%10;
                j = j/10;
            }
            if(isPrime[digitSum])
            {
                result++;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
