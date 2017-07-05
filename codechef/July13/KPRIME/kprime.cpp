#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define LIMIT 100001
using namespace std;
int main()
{
    int i,j;
    int isPrime[LIMIT];
    int myPrimes[LIMIT];
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
    for(i=0;i<LIMIT;i++)
    {
        if(isPrime[i])
        {
            myPrimes[z] = i;
            z++;
        }
    }
    int K;
    int onePrime[LIMIT] = {0};
    int twoPrime[LIMIT] = {0};
    int threePrime[LIMIT] = {0};
    int fourPrime[LIMIT] = {0};
    int fivePrime[LIMIT] = {0};
    int count = 0;

    for(i=2;i<=100000;i++)
    {
        count = 0;
        for(j=0;j<z && myPrimes[j]<=i;j++)
        {
            if(i%myPrimes[j] == 0)
            {
                count++;
            }
            if(count>1)
            {
                break;
            }
        }
        if(count == 1)
        {
            onePrime[i] = 1;
        }
    }
    for(i=2;i<=100000;i++)
    {
        count = 0;
        for(j=0;j<z && myPrimes[j]<=i;j++)
        {
            if(i%myPrimes[j] == 0)
            {
                count++;
            }
            if(count>2)
            {
                break;
            }
        }
        if(count == 2)
        {
            twoPrime[i] = 1;
        }
    }
    for(i=2;i<=100000;i++)
    {
        count = 0;
        for(j=0;j<z && myPrimes[j]<=i;j++)
        {
            if(i%myPrimes[j] == 0)
            {
                count++;
            }
            if(count>3)
            {
                break;
            }
        }
        if(count == 3)
        {
            threePrime[i] = 1;
        }
    }
    for(i=2;i<=100000;i++)
    {
        count = 0;
        for(j=0;j<z && myPrimes[j]<=i;j++)
        {
            if(i%myPrimes[j] == 0)
            {
                count++;
            }
            if(count>4)
            {
                break;
            }
        }
        if(count == 4)
        {
            fourPrime[i] = 1;
        }
    }
    for(i=2;i<=100000;i++)
    {
        count = 0;
        for(j=0;j<z && myPrimes[j]<=i;j++)
        {
            if(i%myPrimes[j] == 0)
            {
                count++;
            }
            if(count>5)
            {
                break;
            }
        }
        if(count == 5)
        {
            fivePrime[i] = 1;
        }
    }
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int a,b,k;

        int result = 0;
        scanf(" %d %d %d",&a,&b,&k);
        switch(k)
        {
            case 1:
                for(i=a;i<=b;i++)
                {
                    if(onePrime[i])
                    {
                        result++;
                    }
                }
            break;

            case 2:
                for(i=a;i<=b;i++)
                {
                    if(twoPrime[i])
                    {
                        result++;
                    }
                }
            break;

            case 3:
                for(i=a;i<=b;i++)
                {
                    if(threePrime[i])
                    {
                        result++;
                    }
                }
            break;

            case 4:
                for(i=a;i<=b;i++)
                {
                    if(fourPrime[i])
                    {
                        result++;
                    }
                }
            break;

            case 5:
                for(i=a;i<=b;i++)
                {
                    if(fivePrime[i])
                    {
                        result++;
                    }
                }
            break;
        }
        printf("%d\n",result);
    }
    return 0;
}
