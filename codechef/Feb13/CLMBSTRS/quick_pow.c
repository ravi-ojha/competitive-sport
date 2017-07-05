#include<stdio.h>
//int power(int a,int n)
//{
//    int ans;
//    if(n==1)
//    return a;
//    ans = pow(a,n/2);
//    ans *= ans;
//    if(n%2==1)
//    ans *= a;
//    return ans;
//}
long long iter_pow(int a,int n)
{
    long long ans = 1;
    long long power = a;
    while(n>0)
    {
        if(n%2 == 1)
            {ans = ans*power;
            ans = ans%1000000007;}
        power = power*power;
        power = power%1000000007;
        n /= 2;
    }
    return ans;
}
int main()
{
    int a,n;
    int b[500000];
    scanf(" %d %d",&a,&n);
    printf(" %llu",iter_pow(a,n));
}
