#include<stdio.h>
struct myNum{
    int x;
    int y;
    int toSort;
}a[11];

int partition(struct myNum a[],int low, int high)
{
    struct myNum temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while ((a[left].toSort <= a[pivot].toSort) && left <= high)
        {
            left++;
        }
        while ((a[right].toSort >= a[pivot].toSort) && right > low)
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

void quicksort(struct myNum a[],int low,int high)
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
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int i,j,high,low;
        for(i=0;i<10;i++)
        {
            a[i].x = i;
            scanf(" %d",&a[i].y);
            a[i].toSort = a[i].y*10 + a[i].x;
        }
//        for(i=0;i<10;i++)
//        {
//            printf("a[%d].x = %d\t",i,a[i].x);
//            printf("a[%d].y = %d\n",i,a[i].y);
//        }
        low = 0;
        high = 10;
        quicksort(a,low,high-1);
//        printf("After Sorting\n\n");
//        for(i=0;i<10;i++)
//        {
//            printf("a[%d].x = %d\t",i,a[i].x);
//            printf("a[%d].y = %d\n",i,a[i].y);
//        }
        if(a[0].x == 0 && a[1].x == 1 && a[1].y != 0)
        {
//            for(j= (a[1].y);j!=0;j--)
//            {
            //if(a[1].y == 0)
                printf("%d",a[1].x);
//            }

            for(j= (a[0].y) + 1;j!=0;j--)
            {
                printf("%d",a[0].x);
            }
            printf("\n");
        }
        else if(a[0].x == 0 && a[1].x == 1 && a[1].y == 0)
        {
            printf("1\n");
        }
        else if(a[0].x == 0 && a[1].y != 0)
        {
            printf("1");
            for(j= (a[0].y) + 1;j!=0;j--)
            {
                printf("%d",a[0].x);
            }
            printf("\n");
        }
        else if(a[0].x == 0 && a[1].y == 0)
        {
            for(j= (a[1].y) + 1;j!=0;j--)
            {
                printf("%d",a[1].x);
            }
            printf("\n");
        }
        else
        {
            for(j= (a[0].y) + 1;j!=0;j--)
            {
                printf("%d",a[0].x);
            }
            printf("\n");
        }

    }
    return 0;
}
