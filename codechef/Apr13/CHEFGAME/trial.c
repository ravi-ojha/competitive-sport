#include<stdio.h>
struct limbo{
long long di[5];
//int ver;
int vis;}a[7000];

struct edge{
long long w;
int src;
int dest;}e[22214445];


int partition(struct edge a[],int low, int high)
{
    struct edge temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while ((a[left].w <= a[pivot].w) && left <= high)
        {
            left++;
        }
        while ((a[right].w >= a[pivot].w) && right > low)
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

void quicksort(struct edge a[],int low,int high)
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
    scanf(" %d",&t);
    //t = read();
    while(t--)
    {
        int n,d,i,j,k,q;
        scanf(" %d %d",&n,&d);
        //n = read();
        //d = read();
        for(i=0;i<n;i++)
        {
            for(j=0;j<d;j++)
            {
                scanf(" %lld",&a[i].di[j]);
                //a[i].di[j] = read();
            }
            //a[i].ver = i;
            a[i].vis = 0;
        }
        int po = 0;
        long long t = 0;
        long long final = 1;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                t = 0;
                for(k=0;k<d;k++)
                {
                    t = t + ((a[i].di[k] - a[j].di[k])*(a[i].di[k] - a[j].di[k]))%747474747;
                }
                e[po].w = t;
                e[po].src = i;
                e[po].dest = j;
                po++;
            }
        }
//        for(q=0;q<po;q++)
//        {
//            printf(" %lld %d %d\n",e[q].w,e[q].src,e[q].dest);
//        }
        //quicksort(e,0,po-1);
//        printf("After Sorting\n");
//        for(q=0;q<po;q++)
//        {
//            printf(" %lld %d %d\n",e[q].w,e[q].src,e[q].dest);
//        }
        int mycount=0;
        for(q=po-1;mycount!=n;q--)
        {
            if(a[e[q].src].vis == 0)
            mycount++;
            if(a[e[q].dest].vis == 0)
            mycount++;
            if(a[e[q].src].vis == 0 || a[e[q].dest].vis == 0)
            {
                //printf("e[q].w = %lld\n",e[q].w);
                final = (final*e[q].w)%747474747;
                a[e[q].src].vis = 1;
                a[e[q].dest].vis = 1;
            }
        }
        printf("%lld\n",final);
    }
    return 0;
}
