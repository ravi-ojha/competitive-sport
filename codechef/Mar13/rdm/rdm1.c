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
    //scanf(" %d",&T);
    T = read();

    while(T--)
    {
        int n, k, l,i,j;
        //int m = n;
        double ans = 0,preans = 0, final = 0;
        //scanf(" %d %d",&n,&k);
        n = read();
        k = read();
        int K = k;
        for(i=(n-1);i>0 && K>0;i--,K--)
        {
            ans = 1/(double)n;
            preans = 0;
            l = i;
            for(j=1;j<k&&l>0;j++)
            {
                ans = ans*1/(double)l;
                //m = l;
                l--;
//                printf("check loop 1\n");
//                printf("ans = %f\n",ans);
            }
            while(l!=0)
            {
                preans = preans+l;
                l--;
//                printf("check loop 2\n");
            }
            final = final + ans*preans;
            if(ans*preans < 0.000001)
            break;
//            printf("check loop\n");
//            printf("%f\n",final);
        }
        printf("%0.7lf\n",final);
    }
    return 0;
}
