#include<iostream>
#include<cstdio>
using namespace std;

long long maxi(long long x, long long y)
{
    return (y > x) ? y : x;
}

void fmax_cont_subarray_sum(long long a[], int size, long long fmax[])
{
    long long max_so_far = a[0], i;
    long long curr_max = a[0];
    fmax[0] = max_so_far;
    for (i = 1; i < size; i++)
    {
        curr_max = maxi(a[i], curr_max+a[i]);
        max_so_far = maxi(max_so_far, curr_max);
        fmax[i] = max_so_far;
        //printf("curr_max: %d    max_so_far: %d\n",curr_max,max_so_far);
    }
}
void rmax_cont_subarray_sum(long long a[], int size, long long rmax[])
{
    long long max_so_far = a[size-1], i;
    long long curr_max = a[size-1];
    rmax[size-1] = max_so_far;
    for (i = size-2; i >= 0; i--)
    {
        curr_max = maxi(a[i], curr_max+a[i]);
        max_so_far = maxi(max_so_far, curr_max);
        rmax[i] = max_so_far;
        //printf("curr_max: %d    max_so_far: %d\n",curr_max,max_so_far);
    }
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k,i;
        scanf(" %d %d",&n,&k);
        long long a[n];
        long long fmax[n];
        long long rmax[n];
        for(i=0;i<n;i++)
        {
            scanf(" %lld",&a[i]);
        }
        fmax_cont_subarray_sum(a, n, fmax);
        rmax_cont_subarray_sum(a, n, rmax);
//        for(i=0;i<n;i++)
//        {
//            printf(" %lld",fmax[i]);
//        }
//        printf("\n");
//        for(i=0;i<n;i++)
//        {
//            printf(" %lld",rmax[i]);
//        }
//        printf("\n");
        long long res;
        i = 0;
        int j = k + 1;
        res = fmax[i] + rmax[j];
        while(j < (n))
        {
            if(res < fmax[i] + rmax[j])
            {
                res = fmax[i] + rmax[j];
            }
            i++;
            j++;
        }
        printf("%lld\n",res);
    }
    return 0;
}
