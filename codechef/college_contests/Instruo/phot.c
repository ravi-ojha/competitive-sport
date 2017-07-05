#include<stdio.h>
int partition(int a[],int low, int high)
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

void quicksort(int a[],int low,int high)
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
    int i,j,k = 0,low,high,l,p,sum = 0;
    int n;
    long long m;
    scanf(" %d %lld",&n,&m);
    //printf("\n %d %lld",n,m);
    int a[n],b[n*n];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
//            if(j == i)
//            continue;
            b[k] = a[i]^a[j];
            //printf("%d..",b[k]);
            k++;
        }
        //printf("\n");
    }
    low = 0;
    high = k-1;
    quicksort(b,low,high);
    for(l=k-1,p=0;p<m;p++,l--)
    {
        sum = sum+b[l];
        sum = sum%1000000007;
    }
    printf("%d\n",sum);
    return 0;
}
