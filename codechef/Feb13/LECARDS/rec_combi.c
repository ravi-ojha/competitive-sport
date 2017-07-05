#include<stdio.h>
int main()
{
    int n;
    scanf(" %d",&n);
    printf(" %d",foo(n,n/2));
}

int foo(int n, int r)
{
    //int r = n/2;
     if(n==r) return 1;
     if(r==1) return n;
     return (foo(n-1,r) + foo(n-1,r-1));
}

