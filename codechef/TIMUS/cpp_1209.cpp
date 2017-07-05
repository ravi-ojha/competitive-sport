#include<cstdio>
#include<cmath>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        long long k;
        scanf(" %lld",&k);
        k--;
//        long long n = sqrt(k*2);
//        if (n*(n+1) == k*2)
//        {
//            printf("1 ");
//        }
//        else
//        {
//            printf("0 ");
//        }
        double tmp = 1 + 8*k;
        double f = sqrt(tmp);
        long long i = (long long)f;
        if(f == i)
        {
            printf("1 ");
        }
        else
        {
            printf("0 ");
        }
    }
    printf("\n");
    return 0;
}
