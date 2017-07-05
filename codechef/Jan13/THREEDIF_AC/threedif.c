
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
    int i,count,temp,low,high,stepCount=0;
    int T, N;
    int W[100];
    scanf(" %d",&T);
    while(T--)
    {
        for(i=0; i<3; i++)
        {
            scanf(" %d",&W[i]);
        }
        low = 0;
        high = N-1;
        quicksort(W,low,high);

        printf("%d\n",stepCount);
    }
    return 0;
}

