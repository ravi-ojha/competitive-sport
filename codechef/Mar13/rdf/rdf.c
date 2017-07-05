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
int main()
{
    int T;
    T = read();
    while(T--)
    {
        int i,j,e,f;
        int N,K;
        N = read();
        K = read();
        int n,k;
        n = N;
        k = K;
        double prepreans = 1,preans=1, ans,final = 0;
        long long sum;
        //preans = 1/(float)n;
        for(e=N,i=0;i<K;i++,e--)
        {
            prepreans = prepreans*1/(double)e;
        }
        for(j=(N-K+1);j<N;j++)
        {
            for(i=n-j+1;i>1;i--)
            {
                printf("j = %d  i = %d\t",j,i);
                preans = (prepreans*j)/i;
                printf("preans = %0.9lf\t",preans);
                sum = i;
                sum = sum*(sum-1)/2;
                printf("sum = %d\t",sum);
                ans = preans*sum;
                final = final+ans;
                printf("ans = %0.9lf\n",ans);
            }
        }
        printf("final final = %0.9lf\n",final);
        //printf("%f\n",preans);
    }
    return 0;
}
