#include<cstdio>
#include<iostream>

using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k,i,z;
        scanf(" %d %d",&n,&k);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        z = n - k + 1;
        if(z<=0 || n==1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",z);
            for(i=1;i<=z;i++)
            {
                printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}
