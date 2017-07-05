#include<stdio.h>

void initialize(int node, int b, int e, int M[], int A[], int N)
  {
      if (b == e)
          M[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          initialize(2 * node, b, (b + e) / 2, M, A, N);
          initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  //search for the minimum value in the first and
  //second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1];
      }
  }

  int query(int node, int b, int e, int M[], int A[], int i, int j)
  {
      int p1, p2;



  //if the current interval doesn't intersect
  //the query interval return -1
      if (i > e || j < b)
          return -1;

  //if the current interval is included in
  //the query interval return M[node]
      if (b >= i && e <= j)
          return M[node];

  //compute the minimum position in the
  //left and right part of the interval
      p1 = query(2 * node, b, (b + e)/2, M, A, i, j);
      p2 = query(2 * node + 1, ((b + e)/2) + 1, e, M, A, i, j);

  //return the position where the overall
  //minimum is
      if (p1 == -1)
          return p2;
      if (p2 == -1)
          return p1;
      if (A[p1] <= A[p2])
          return p1;
      return p2;
  }
//int minimum(int i, int j)
//{
//    if(i<j)
//    {
//        return i;
//    }
//    return j;
//}
//int min(int node, int b, int e, int M[], int A[], int i, int j)
//{
//    if(b>=i && e<=j)
//    {
//        return M[node];
//    }
//    else
//    {
//        return minimum(min(2*node,b,(b+e)/2,M,A,i,j),min(2*node + 1,(b+e)/2 + 1,e,M,A,i,j));
//    }
//}
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
    initialize(1,0,n-1,m,a,n);
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
        res = query(1,0,n-1,m,a,v,w);
        printf("  %d %d\n",res,a[res]);
    }
    return 0;
}
