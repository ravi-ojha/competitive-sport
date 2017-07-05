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
int partition(int a[][101],int low, int high,int n)
{
    int temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while (a[n][left] <= a[n][pivot] && left < high)
        {
            left++;
        }
        while (a[n][right] >= a[n][pivot] && right > low)
        {
            right--;
        }
        if (left < right)
        {
            temp = a[n][right];
            a[n][right] = a[n][left];
            a[n][left] = temp;
        }
    }
    temp = a[n][pivot];
    a[n][pivot] = a[n][right];
    a[n][right] = temp;
    return right;
}

void quicksort(int a[][101],int low,int high,int n)
{
    if(low<high)
    {
        int pivot;

        pivot = partition(a,low,high,n);

        quicksort(a,low,pivot-1,n);
        quicksort(a,pivot+1,high,n);
    }
}
int main()
{
    int t;
    t = 1;
    while(t--)
    {
        //int max = 0;
        int n,i,j,low,high;
        int a[101][101];
        n = 100;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                a[i][j] = read();
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=i;j++)
//            {
//                printf(" %d",a[i][j]);
//            }
//            printf("\n");
//        }
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                if(j==1)
                {
                    a[i][j] = a[i-1][j] + a[i][j];
                }
                else if(j==i)
                {
                    a[i][j] = a[i-1][j-1] + a[i][j];
                }
                else
                {
                    if(a[i-1][j] > a[i-1][j-1])
                    {
                        a[i][j] = a[i-1][j] + a[i][j];
                    }
                    else
                    {
                        a[i][j] = a[i-1][j-1] + a[i][j];
                    }
                }
//                if(a[i][j]>max)
//                {
//                    max = a[i][j];
//                }
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=i;j++)
//            {
//                printf(" %d",a[i][j]);
//            }
//            printf("\n");
//        }
        low = 0;
        high = n;
        quicksort(a,low,high,n);
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=i;j++)
//            {
//                printf(" %d",a[i][j]);
//            }
//            printf("\n");
//        }
        //printf("%d\n",max);
        printf("%d\n",a[n][n]);
    }
    return 0;
}
