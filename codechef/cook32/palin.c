#include<stdio.h>
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

long long iter_pow(int a,int n)
{
    long long ans = 1;
    long long power = a;
    while(n>0)
    {
        if(n&1)
            {ans = ans*power;
            ans = ans%1000000007;}
        power = power*power;
        power = power%1000000007;
        n /= 2;
    }
    return ans;
}
//long long modInverse(long long a, long long p) {
////calculates the modular multiplicative of a mod m.
////(assuming p is prime).
//return iter_pow(a, p-2);
//}
int main()
{
    int t,j;
    //scanf(" %d",&t);
    t = read();
    int a[1000001];
    a[1] = 26;
//    for(j=2;j<1000001;j++)
//        {
//            a[j] = a[j-1] + iter_pow(26,j);
//        }
    while(t--)
    {
        int n;
        long long l,i;
        long long sum = 1;
        long long temp,ans = 0;
        n = read();
        //scanf(" %d",&n);
        l = (n)/2;
        ans = iter_pow(26,l)-1;
        ans = ans*(iter_pow(25,1000000005));
        ans = ans%1000000007;
        ans = ans*52;
        ans = ans%1000000007;
        if(n&1)
        ans = ans + iter_pow(26,l+1);
        ans = ans%1000000007;
//        for(i=1;i<=l;i++)
//        {
//            if (i<1000001)
//            temp = a[i];
//            else
//            temp = iter_pow(26,i);
//            ans = ans + 2*temp;
//            //ans = ans%1000000007;
//            if (n%2 == 1 && i==l)
//            {
//                if (i<1000001)
//                temp = a[i];
//                else
//                temp = iter_pow(26,i);
//                ans = ans - temp;
//            }
//            ans = ans%1000000007;
//        }
        printf("%lld\n",ans);
    }
    return 0;
}
