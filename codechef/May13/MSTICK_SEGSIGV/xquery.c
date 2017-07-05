#include<stdio.h>

void initializeK(int node, int b, int e,int K[], int A[], int N)
  {
      if (b == e)
          K[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          initializeK(2 * node, b, (b + e) / 2, K, A, N);
          initializeK(2 * node + 1, (b + e) / 2 + 1, e, K, A, N);
  //search for the minimum value in the first and
  //second half of the interval
          if (A[K[2 * node]] <= A[K[2 * node + 1]])
              K[node] = K[2 * node + 1];
          else
              K[node] = K[2 * node];
      }
  }

int Xquery(int node, int b, int e, int K[], int A[], int i, int j)
  {
      int p1, p2;
      if (i > e || j < b)
          return -1;
      if (b >= i && e <= j)
          return K[node];
      p1 = Xquery(2 * node, b, (b + e)/2, K, A, i, j);
      p2 = Xquery(2 * node + 1, ((b + e)/2) + 1, e, K, A, i, j);
      if (p1 == -1)
          return p2;
      if (p2 == -1)
          return p1;
      if (A[p1] <= A[p2])
          return p2;
      return p1;
  }


int main()
{
    int n,i,l;
    scanf(" %d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
//    for(i=0;i<n;i++)
//    {
//        printf("%4d",i);
//    }
//    printf("\n");
//    for(i=0;i<n;i++)
//    {
//        printf("%4d",a[i]);
//    }
    int m[1000000];
    for(l=0;l<1000000;l++)
    {
        m[l] = -1;
    }
//    printf("\n");
//    for(l=0;l<50;l++)
//    {
//        printf("%3d",l);
//    }
//    printf("\n");
//    for(l=0;l<50;l++)
//    {
//        printf("%3d",m[l]);
//    }
    initializeK(1,0,n-1,m,a,n);
//    printf("\n");
//    for(l=0;l<50;l++)
//    {
//        printf("%3d",m[l]);
//    }
//    printf("\n");
    int q;
    int res;
    int v,w;
    scanf(" %d",&q);
    while(q--)
    {
        scanf(" %d %d",&v,&w);
        res = Xquery(1,0,n-1,m,a,v,w);
        printf("  %d %d\n",res,a[res]);
    }
    return 0;
}
