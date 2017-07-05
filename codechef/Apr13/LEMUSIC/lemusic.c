#include<stdio.h>
struct music{
unsigned long long b;
unsigned long long l;
unsigned long long toSort;}le[100000];
unsigned long long int read()
{
    unsigned long long int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}
int partition(struct music a[],int low, int high)
{
    struct music temp;
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

void quicksort(struct music a[],int low,int high)
{
    if(low<high)
    {
        int pivot;

        pivot = partition(a,low,high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
int partitio(unsigned long long a[],int low, int high)
{
    unsigned long long temp;
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

void quicksor(unsigned long long a[],int low,int high)
{
    if(low<high)
    {
        int pivot;

        pivot = partitio(a,low,high);

        quicksor(a,low,pivot-1);
        quicksor(a,pivot+1,high);
    }
}
int main()
{
    unsigned long long t;
    //scanf(" %d",&t);
    t = read();
    while(t--)
    {
        int n,i,y=0,j,k,p;
        unsigned long long z,ans=0,tr[100000],ar[100000];
        scanf(" %d",&n);
        for(i=0;i<n;i++)
        {
            //scanf(" %llu %llu",&le[i].b,&le[i].l);
            le[i].b = read();
            le[i].l = read();
            le[i].toSort = le[i].b*1000000000 + le[i].l;
        }
        quicksort(le,0,n-1);
//        for(i=0;i<n;i++)
//        {
//            printf(" %lld %lld\n",le[i].b,le[i].l);
//        }
//        printf("\n\n");
        z = le[0].b;
        j = 1;
        //ans = ans + le[0].l;
        ar[j] = le[0].l;
        for(i=0;i<n;i++)
        {
            while(i<n && le[i].b == z)
            {
                tr[y] = le[i].l;
                y++;
                i++;
            }
            if(i>=n)
            break;
            j++;
            z = le[i].b;
            //ans = ans + j*le[i].l;
            ar[j] = le[i].l;
        }
        quicksor(ar,1,j);

        for(p=1;p<=j;p++)
        {
            //printf(" %5llu",ar[p]);
            ans = ans + p*ar[p];
        }
        //printf("diff ans = %llu\n",ans);
        for(k=1;k<y;k++)
        {
            //printf("tr[%d] = %lld\n",k,tr[k]);
            ans = ans + j*tr[k];
        }
        printf("%llu\n",ans);
    }
    return 0;
}
