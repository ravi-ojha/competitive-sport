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
        int n, k,i,j;
        long long l;
        //int m = n;
        double ans = 0,preans = 0, final = 0;
        //scanf(" %d %d",&n,&k);
        n = read();
        k = read();
        int K = k;
        if(k==0)
        {
            printf("%d\n",n);
        }
        else
        {for(i=(n-1);i>0 && K>0;i--,K--)
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
//            while(l!=0)
//            {
//                preans = preans+l;
//                l--;
//                //printf("check loop 2\n");
//            }
//printf("l = %d\n",l);
            //printf("%llu\n",(l+1)*l);
            preans = (l+1)*l/2;
            final = final + ans*preans;
            if(ans*preans < 0.000001)
            break;
//            printf("check loop\n");
//            printf("%f\n",final);
        }
        printf("%f\n",final);}
    }
    return 0;
}
