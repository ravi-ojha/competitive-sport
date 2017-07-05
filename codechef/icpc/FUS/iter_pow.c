#include<stdio.h>
#include<math.h>
long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%1000000007;}
        value = value*value;
        value = value%1000000007;
        power /= 2;
        //power >>= 1;
    }
    return result;
}

int main()
{
    int a,n;
    scanf(" %d %d",&a,&n);
    printf(" %d",pow(2,0));
    //printf(" %d %d\n",n<<1,n>>1);
    //for(n=1;n<21;n++)
    //printf("%lld\n",iter_pow(2,n));
    printf(" %lld",fast_pow(a,n));
    return 0;
}
