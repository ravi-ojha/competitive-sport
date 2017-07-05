#include<stdio.h>

void initializeM(int node, int b, int e, int M[], int A[], int N)
  {
      if (b == e)
          M[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          initializeM(2 * node, b, (b + e) / 2, M, A, N);
          initializeM(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  //search for the minimum value in the first and
  //second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1];
      }
  }
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

int Nquery(int node, int b, int e, int M[], int A[], int i, int j)
  {
      int p1, p2;
      if (i > e || j < b)
          return -1;
      if (b == i && e == j)
          return M[node];
      p1 = Nquery(2 * node, b, (b + e)/2, M, A, i, j);
      p2 = Nquery(2 * node + 1, ((b + e)/2) + 1, e, M, A, i, j);
      if (p1 == -1)
          return p2;
      if (p2 == -1)
          return p1;
      if (A[p1] <= A[p2])
          return p1;
      return p2;
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
int maxx(int i,int j)
{
    if(i>j)
    {
        return i;
    }
    return j;
}
int main()
{
    int n,i,l;
    scanf(" %d",&n);
    int a[100010];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    int m[100000],r[100000];
    for(l=0;l<100000;l++)
    {
        m[l] = -1;
        r[l] = -1;
    }
    initializeM(1,0,n-1,m,a,n);
    initializeK(1,0,n-1,r,a,n);
    int q;
    float res,preAns,preRes;
    int v,w;
    scanf(" %d",&q);
    if(n==1)
    {
        while(q--)
        {
            scanf(" %d %d",&v,&w);
            printf("%d.0\n",a[0]);
        }
    }
    else
    {
        while(q--)
        {
            scanf(" %d %d",&v,&w);
            if(v==0 && w != (n-1))
            {
                res = a[Nquery(1,0,n-1,m,a,v,w)];
                preRes = a[Xquery(1,0,n-1,r,a,w+1,n-1)];
                preAns = a[Xquery(1,0,n-1,r,a,v,w)] - res;
                preAns = preAns/2;
                res = res + maxx(preRes,preAns);
                printf("%.1f\n",res);
            }
            else if(v!=0 && w == (n-1))
            {
                res = a[Nquery(1,0,n-1,m,a,v,w)];
                preRes = a[Xquery(1,0,n-1,r,a,0,v-1)];
                preAns = a[Xquery(1,0,n-1,r,a,v,w)] - res;
                preAns = preAns/2;
                res = res + maxx(preRes,preAns);
                printf("%.1f\n",res);
            }
            else if(v==0 && w == (n-1))
            {
                res = a[Nquery(1,0,n-1,m,a,v,w)];
                preAns = a[Xquery(1,0,n-1,r,a,v,w)] - res;
                preAns = preAns/2;
                res = res+preAns;
                printf("%.1f\n",res);
            }
            else
            {
                res = a[Nquery(1,0,n-1,m,a,v,w)];
                preRes = maxx(a[Xquery(1,0,n-1,r,a,0,v-1)],a[Xquery(1,0,n-1,r,a,w+1,n-1)]);
                preAns = a[Xquery(1,0,n-1,r,a,v,w)] - res;
                preAns = preAns/2;
                res = res + maxx(preRes,preAns);
                printf("%.1f\n",res);
            }
        }
    }
    return 0;
}
