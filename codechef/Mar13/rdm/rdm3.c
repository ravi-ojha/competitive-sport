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
    double a[100001][10] = {0,0};
    //scanf(" %d",&T);
    T = read();
    int myT = 100001;
    int q,s;
    int n, k,i,j;
    long long l;
    for(q=1;q<100001;q++)
    {

        //int m = n;

        //scanf(" %d %d",&n,&k);
        n = q;
        for(s=0;s<9;s++)
        {
            double ans = 0,preans = 0, final = 0;
            k = s;
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
//                while(l!=0)
//                {
//                    preans = preans+l;
//                    l--;
//    //                printf("check loop 2\n");
//                }
                preans = (l+1)*l/2;
                final = final + ans*preans;
                if(ans*preans < 0.000001)
                break;

            }
            a[q][s] = final;

//            printf("check loop\n");
//            printf("%f\n",final);
        }
        //printf("check\t");

    }
//    for(i=4;i<7;i++)
//    {
//        for(j=0;j<10;j++)
//        printf("a[%d][%d] = %f\n",i,j,a[i][j]);
//    }
    while(T--)
    {
        n = read();
        k = read();
        if(k>8)
        {
            printf("0.000000\n");
        }
        else if(k==0)
        {
//            long long w = n;
//            printf("%llu\n",(w*(w-1))/2);
                printf("0.000000\n");
        }
        else
        {
            printf("%0.7lf\n",a[n][k]);
        }
    }
    return 0;
}
