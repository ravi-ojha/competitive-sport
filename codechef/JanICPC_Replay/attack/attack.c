#include<stdio.h>

struct attack{
int x;
int y;
}anoms[300000];
int partition(struct attack a[],int low, int high)
{
    struct attack temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while ((a[left].y <= a[pivot].y) && left <= high)
        {
            left++;
        }
        while ((a[right].y >= a[pivot].y) && right > low)
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

void quicksort(struct attack a[],int low,int high)
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
        int flag = 0;
        int N,M,i,j,low,high;
        scanf(" %d %d",&N,&M);
        if(M==0)
        {
            printf("2 %d\n",N);
            continue;
        }
        for(i=0;i<M;i++)
        {
                scanf(" %d %d",&anoms[i].x,&anoms[i].y);
        }
//        printf("\n\nBefore Sorting\n");
//        for(i=0;i<M;i++)
//        {
//                printf(" %d %d\t",anoms[i].x,anoms[i].y);
//        }
        low = 0;
        high = M-1;
        quicksort(anoms,low,high);
//        printf("\n\nAfter Sorting\n");
//        for(i=0;i<M;i++)
//        {
//                printf(" %d %d\t",anoms[i].x,anoms[i].y);
//        }
        int m = M-1;
        int n = N;
        //printf("\nanoms[%d].y = %d\n",m,anoms[m].y);
        if(M==1)
        {
            if(anoms[m].y == N && anoms[m].x == (N-1))
            {printf("2 %d\n",N-1);
            continue;}

        }
        if(n != anoms[m].y)
        {
            printf("2 %d\n",n);
        }
        else
        {
            n--;
            m--;
            while(n>0 && m>=0)
            {
                if(n != anoms[m].y)
                {
                    printf("1\n");
                    flag = 1;
                    //printf("1 %d\n",n);
                    break;
                }
                n--;
                m--;
            }
            if(flag == 0)
            {
                printf("1\n");
                //printf("1 %d\n",n);
            }
        }
//        while(m>=0)
//        {
//            while(n>0)
//            {
//                if(n == anoms[m].y)
//                {
//                    n--;
//                }
//                else
//                break;
//            }
//
//
//            gattack = n;
//            if(n == anoms[m].y)
//        }
    }
    return 0;
}
