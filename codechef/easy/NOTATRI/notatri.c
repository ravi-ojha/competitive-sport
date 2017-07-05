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
    int n;
    //scanf(" %d",&n);
    n = read();
    while(n)
    {
        int a[n],p,i,j,k;
        int count = 0;
        for(p=0;p<n;p++)
        {
            //scanf(" %d",&a[p]);
            a[p] = read();
        }
        quicksort(a,0,n-1);
        for(i=0;i<(n-2);i++)
        {
            for(j=i+1;j<(n-1);j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if((a[i]+a[j]) < a[k])
                    {
                        //printf(" %d",n-k);
                        count = count + n - k;
                        break;
                    }
                    printf("check\n");
                }
            }
        }
        printf("%d\n",count);
        //scanf(" %d",&n);
        n = read();
    }
    return 0;
}
