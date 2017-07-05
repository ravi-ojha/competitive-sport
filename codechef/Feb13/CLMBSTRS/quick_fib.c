#include<stdio.h>
int a[1000001] = {0};
//int fib(int n)
//{
//    int y;
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

//int fib(int n)
//{
//   int first = 0, second = 1, next, c;
//   //scanf("%d",&n);
//   for (c=0;c<=n;c++)
//   {
//      if (c<=1)
//         next = c;
//      else
//      {
//         next = first + second;
//         next = next%1000000007;
//         first = second;
//         second = next;
//      }
//      //printf("%d\n",next);
//   }
//   return next;
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
main()
{
    int N;
    int ans;
//    a[0] = 1;
//    a[1] = 1;
    scanf(" %d",&N);
    ans = fib(N+1);
    printf("%d",ans);
}
