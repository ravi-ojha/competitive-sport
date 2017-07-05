#include<cstdio>
#include<iostream>
#include<math.h>

using namespace std;

int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

int primeFactors(int n)
{
    int count = 0;
    int flag=0;
    while(n%2==0)
    {
        if(flag==0)
        {
            //printf(" 2");
            count++;
            flag=1;
        }

        n=n/2;
    }

    int i;

    for(i=3;i<=sqrt(n);i=i+2)
    {
        flag=0;
        while(n%i==0)
        {
            if(flag==0)
            {
                //printf(" %d",i);
                count++;
                flag=1;
            }

            n=n/i;
        }
    }

    if(n>2)
    {
        //printf(" %d",n);
        count++;
    }
    return count;
}
int main()
{
    int i;
    int data[100001] = {0};
    for(i=2;i<100001;i++)
    {
        data[i] = primeFactors(i);
    }
    int t;
    //scanf(" %d",&t);
    t = read();
    while(t--)
    {

        int a,b,k;
        int result = 0;
        //scanf(" %d %d %d",&a,&b,&k);
        a = read();
        b = read();
        k = read();
        for(i=a;i<=b;i++)
        {
            if(data[i] == k)
            {
                result++;
            }
        }
        printf("%d\n",result);
    }
//    int n;
//    scanf(" %d",&n);
//    printf("%d",primeFactors(n));
    return 0;
}
