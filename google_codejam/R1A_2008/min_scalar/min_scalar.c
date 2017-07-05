#include<stdio.h>
int partition(long long a[],int low, int high)
{
    int temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while (a[left] <= a[pivot] && left < high)
        {
            left++;
        }
        while (a[right] >= a[pivot] && right > low)
        {
            right--;
        }
        if (left < right)
        {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
    temp = a[pivot];
    a[pivot] = a[right];
    a[right] = temp;
    return right;
}

void quicksort(long long a[],int low,int high)
{
    if(low<high)
    {
        int pivot;

        pivot = partition(a,low,high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}

int main()
{
    int T,p;
    scanf(" %d",&T);
    for(p=1;p<=T;p++)
    {
        int n,low,high,i;
        long long sum=0;
        scanf(" %d",&n);
        long long a[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf(" %lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf(" %lld",&b[i]);
        }
        low = 0;
        high = n-1;
        quicksort(a,low,high);
        quicksort(b,low,high);
        for(i=0;i<n;i++)
        {
            sum = sum + a[i]*b[n-1-i];
        }
        printf("Case #%d: %lld\n",p,sum);
    }
    return 0;
}
