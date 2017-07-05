#include<stdio.h>

struct kilowhat{
long long x;
long long y;
long long toSort;
}cit[100000];

//struct remem{
//char r[100000];
//}rem[100000];
int partition(struct kilowhat a[],int low, int high)
{
    struct kilowhat temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while ((a[left].toSort <= a[pivot].toSort) && left < high)
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
    int T;
    //char remem[100000][10000];
    //short int rem[100000][10];
    scanf(" %d",&T);
    while(T--)
    {
        int N,M,i,low,high,subsets=0;
        long long ways = 1;
        scanf(" %d %d",&N,&M);
        int count[100001],parent[100001];
        for(i=1;i<=N;i++)
        {
            parent[i] = i;
            count[i] = 1;
        }
        for(i=0;i<M;i++)
        {
            scanf(" %llu %llu",&cit[i].x,&cit[i].y);
            cit[i].toSort = cit[i].y + 100000*cit[i].x;
//            printf("cit[%d].toSort = %llu\n",i,cit[i].toSort);
        }
//        for(i=0;i<M;i++)
//        {
//            printf(" %llu %llu\n",cit[i].x,cit[i].y);
//        }
        low = 0;
        high = M;
        quicksort(cit,low,high-1);
//        printf("\n\nAfter Sorting\n");
//        for(i=0;i<M;i++)
//        {
//            printf(" %llu %llu\n",cit[i].x,cit[i].y);
//        }

        for(i=0;i<M;i++)
        {
            if(parent[cit[i].x] < parent[cit[i].y])
            {
                parent[cit[i].y] = parent[cit[i].x];
                count[parent[cit[i].x]]++;
            }
            else if(parent[cit[i].x] > parent[cit[i].y])
            {
                parent[cit[i].x] = parent[cit[i].y];
                count[parent[cit[i].y]]++;
            }
        }
//        for(i=0;i<M;i++)
//        {
//            if(parent[cit[i].x] < parent[cit[i].y])
//            {
//                count[parent[cit[i].y]]--;
//                parent[cit[i].y] = parent[cit[i].x];
//
//                count[parent[cit[i].x]]++;
//            }
//            else if(parent[cit[i].x] > parent[cit[i].y])
//            {
//                count[parent[cit[i].x]]--;
//                parent[cit[i].x] = parent[cit[i].y];
//
//                count[parent[cit[i].y]]++;
//            }
//        }
        for(i=1;i<=N;i++)
        {
//            printf("parent[%d] = %d\t",i,parent[i]);
//            printf("count[%d] = %d\n",i,count[i]);
            if(parent[i] == i)
            subsets++;
        }
        for(i=1;i<=N;i++)
        {
            ways = ways*count[i];
            ways = ways%1000000007;
        }
        printf("%d %llu\n",subsets,ways);
    }
    return 0;
}
