#include<stdio.h>

struct kilowhat{
int x;
int y;
int byte;
int toSort;
}cit[200];

int partition(struct kilowhat a[],int low, int high)
{
    struct kilowhat temp;
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

void quicksort(struct kilowhat a[],int low,int high)
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
    int i,j,k,iX=0,iY=0;
    int N;
    int maxX=0,minY=999,tempX,tempY,tempByte,low,high;
    scanf(" %d",&N);
    for(i=0;i<N;i++)
    {

//        scanf(" %d %d %d",&tempX,&tempY,&tempByte);
//        cit[tempX].x = tempX;
//        cit[tempY].y = tempY;
//        cit[tempByte].By = tempByte;
        scanf(" %d %d %d",&cit[i].x,&cit[i].y,&cit[i].byte);
        //sortIndex = cit[i].x*10 + cit[i].y;

        cit[i].toSort = cit[i].x*1000 + cit[i].y;
//        if(cit[i].x > maxX)
//        {
//            maxX = cit[i].x;
//        }
        if(cit[i].y < minY)
        {
            minY = cit[i].y;
        }
    }
    low = 0;
    high = N;
    quicksort(cit,low,high-1);

    /*printf("\nAfter Final Sorting\n");
    for(i=0;i<N;i++)
    {
        printf(" %d %d %d %d\n",cit[i].x,cit[i].y,cit[i].byte,cit[i].toSort);
    }*/
    //printf("\nHow's Output gonna be\n\n");
    //printf("maxX = %d maxY = %d\n\n",maxX,maxY);
    printf("%d\n",N+2);
    printf("%d %d\n",cit[0].x-1,minY-1);
    for(i=0;i<N;i++)
    {
        printf("%d %d\n",cit[i].x,cit[i].y);
    }
    printf("%d %d",cit[i-1].x+1,minY-1);
//    for(i=0;i<iX;i++)
//    {
//        printf("%d %d %d\n",cit[i].x,cit[i].y,cit[i].byte);
//    }
//    j = 0;
//    while(j<maxY)
//    {
//        i = 0;
//        while(cit[i].x%2 == 1)
//        {
//            printf("%d %d %d\n",cit[i].x,cit[i].y,cit[i].byte);
//            i++;
//        }
//        k = 0;
//        while(cit[i].x%2 == 0)
//        {
//            k++;
//            printf("Incre k ");
//            i++;
//        }
//        m = k;
//        while(m>)
//        {
//            i--;
//            printf("%d %d %d\n",cit[i].x,cit[i].y,cit[i].byte);
//        }
        /*while(cit[i].x == 0)
        {
            printf("%d %d %d\n",cit[i].x,cit[i].y,cit[i].byte);
            i--;
        }*/
//j++;
//    }
return 0;
}
