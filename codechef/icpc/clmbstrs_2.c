#include<stdio.h>
#define MOD 1000000007
void matrix_mul(long long a[][2], long long b[][2],long long c[][2])
{
    //int i,j;
    c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    c[0][0]%=MOD;
    c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    c[0][1]%=MOD;
    c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    c[1][0]%=MOD;
    c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    c[1][1]%=MOD;
}
int iter_pow(int n)
{
    int i,j;
    long long ans[2][2] = {1,0,0,1};
    long long b[2][2];
    long long power[2][2] = {2,1,1,0};
    while(n)
    {
        if(n&1)
        {
            matrix_mul(ans,power,b);
            ans[0][0] = b[0][0];
            ans[0][1] = b[0][1];
            ans[1][0] = b[1][0];
            ans[1][1] = b[1][1];
        }
        matrix_mul(power,power,b);
        power[0][0] = b[0][0];
        power[0][1] = b[0][1];
        power[1][0] = b[1][0];
        power[1][1] = b[1][1];
        n = n>>1;
    }
//    printf("\n\nNow\n\n");
//    for(i=0;i<2;i++)
//    {
//        for(j=0;j<2;j++)
//        {
//            printf("%5d",ans[i][j]);
//        }
//        printf("\n");
//    }
return (ans[1][1])%MOD;
}



long findOnes(long long i)
{
      long count = 0;
      int j=1,m=1,k=0;
   /*   while (i >= j)       // value of j is extended upto the 8,16,32,64 etc acc. to requirement
      {
            j = j << 1;
            m++;
      }
      while(k<m)
      {
              if ((j&i)>0)
                       count++;
              j = j >> 1;
              k++;
      }*/
      while(i)
      {
          if(i&1)
            count++;
        i=i>>1;

      }
      return count;
}
main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
        {
            int N,G;
            long long ans;
            long final;
            scanf(" %d %d",&N,&G);
            //printf("%ul",fib(n+1));
            if(N<=2)
                ans=N;
            else
            ans = iter_pow(N-2);
            printf("\nans = %d\n",ans);
            final = findOnes(ans);
            //printf("\nfinal = %d",final);
            if(final == G)
            printf("CORRECT\n");
            else
            printf("INCORRECT\n");
            //printf("%ul",final);
        }
    return 0;
}
