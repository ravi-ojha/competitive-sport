#include<stdio.h>
struct{
float z[100000] = 0.000000;
}
int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int n, k, l,i,j;
        //int m = n;
        float ans = 0,preans = 0, final = 0;
        scanf(" %d %d",&n,&k);
        int K = k;
        for(i=(n-1);i>0 && K>0;i--,K--)
        {
            ans = 1/(float)n;
            preans = 0;
            l = i;
            for(j=1;j<k&&l>0;j++)
            {
                ans = ans*1/(float)l;
                //m = l;
                l--;
                //printf("check loop 1\n");
                //printf("ans = %f\n",ans);
            }
            while(l!=0)
            {
                preans = preans+l;
                l--;
                //printf("check loop 2\n");
            }
            final = final + ans*preans;
            if(ans*preans < 0.000001)
            break;
            //printf("check loop\n");
            printf("%f\n",final);
        }
        printf("final = %f\n",final);
    }
}
