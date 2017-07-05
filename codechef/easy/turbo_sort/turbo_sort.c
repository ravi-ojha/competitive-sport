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
//int partition(int a[],int low, int high)
//{
//    int temp;
//    int left = low;
//    int right = high;
//    int pivot = low;
//    while (left < right)
//    {
//        while (a[left] <= a[pivot] && left < high)
//        {
//            left++;
//        }
//        while (a[right] >= a[pivot] && right > low)
//        {
//            right--;
//        }
//        if (left < right)
//        {
//            temp = a[right];
//            a[right] = a[left];
//            a[left] = temp;
//        }
//    }
//    temp = a[pivot];
//    a[pivot] = a[right];
//    a[right] = temp;
//    return right;
//}
//
//void quicksort(int a[],int low,int high)
//{
//    if(low<high)
//    {
//        int pivot;
//
//        pivot = partition(a,low,high);
//
//        quicksort(a,low,pivot-1);
//        quicksort(a,pivot+1,high);
//    }
//}

int main()
{
    int T,i,a[1000001]={0},n;

    T = read();
    for(i=0;i<T;i++)
    {
        n = read();
        a[n]++;
    }
//    low = 0;
//    high = T-1;
//    quicksort(a,low,high);
    for(i=0;i<1000001;i++)
    {
        while(a[i]--)
        printf("%d\n",i);
        //putchar(a[i]);
    }
    return 0;
}
