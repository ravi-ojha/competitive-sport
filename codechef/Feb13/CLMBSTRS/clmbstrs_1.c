#include<stdio.h>

int a[1000001] = {0};
//long int fib(int n)
//{
//    long int y;
//    if(n==1 || n==0)
//        return n;
//    if (a[n] != 0)
//        return a[n];
//    else
//        {
//            y=fib(n-1)+fib(n-2);
//            y = y%1000000007;
//            a[n] = y;
//        }
//    return y;
//}

int fib(int n)
{
   int next, c,first = 0,second = 1;
   //scanf("%d",&n);
   for (c=0;c<=n;c++)
   {
      if (c<=1)
         next = c;
      else if(a[c] != 0 && a[c-1] != 0)
      {
          //printf("\ngaya");
         next = a[c] + a[c-1];
         next = next%1000000007;
         a[c+1] = next;
      }
      else
      {
         next = first + second;
         next = next%1000000007;
         a[c+1] = next;
         first = second;
         second = next;
     }
      //printf("%d\n",next);
   }
   return next;
}

int findOnes(int i)
{
      int count = 0;
      int j=1,m=1,k=0;
      while (i >= j)       // value of j is extended upto the 8,16,32,64 etc acc. to requirement
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
            int ans;
            int final;
            scanf(" %d %d",&N,&G);
            //printf("%ul",fib(n+1));
            a[0] = 1;
            ans = fib(N+1);
            //printf("\nans = %d",ans);
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
