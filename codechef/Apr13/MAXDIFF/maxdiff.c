#include<stdio.h>
int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}

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
    int t;
//    scanf(" %d",&t);
    t = read();
    while(t--)
    {
        int n,k,sum=0,minsum=0,i;
        //scanf(" %d %d",&n,&k);
        n = read();
        k = read();
        int a[n];
        if(k>(n/2))
        {
            k = n-k;
        }
        for(i=0;i<n;i++)
        {
            //scanf(" %d",&a[i]);
            a[i] = read();
            sum = sum+a[i];
        }
//        for(i=0;i<n;i++)
//        {
//            printf("%4d",a[i]);
//        }
        //printf("\n");
        quicksort(a,0,n-1);
//        for(i=0;i<n;i++)
//        {
//            printf("%4d",a[i]);
//        }
//        printf("\n");
        for(i=0;i<k;i++)
        {
            minsum = minsum + a[i];
        }
        //printf("sum = %d\tminsum = %d\n",sum,minsum);
        printf("%d\n",sum-2*minsum);
    }
    return 0;
}
