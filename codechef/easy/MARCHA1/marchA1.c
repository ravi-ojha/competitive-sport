#include<stdio.h>
#include<math.h>
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
int main()
{
    int T;
    //scanf(" %d",&T);
    T = read();
    while(T--)
    {
        int n,m,i,j,l,sum,flag = 0;
        int a[20];
        //scanf(" %d %d",&n,&m);
        n = read();
        m = read();
        for(i=0;i<n;i++)
        {
            //scanf(" %d",&a[i]);
            a[i] = read();
        }
        //l = pow(2,n);
        l = iter_pow(2,n);
        for(i=1;i<l;i++)
        {
            sum = 0;
            for(j=0;j<=n;j++)
            {
                if((1<<j)&i)
                {
                    sum = sum + a[j];
                }
            }
            if(sum == m)
            {printf("Yes\n");
            flag = 1;
            break;}
        }
        //printf("sum = %d\n",sum);
        if(flag == 0)
        printf("No\n");
    }
    return 0;
}
