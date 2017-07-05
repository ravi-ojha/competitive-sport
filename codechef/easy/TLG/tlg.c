#include<stdio.h>
struct player{
int score;
int player;
}pl[10001];
int partition(struct player a[],int low, int high)
{
    struct player temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while (a[left].score <= a[pivot].score && left < high)
        {
            left++;
        }
        while (a[right].score >= a[pivot].score && right > low)
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

void quicksort(struct player a[],int low,int high)
{
    if(low<high)
    {
        int pivot;

        pivot = partition(a,low,high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
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
int main()
{
    int n,p,low,high,x=0,y=0,i;
    //int a[10001][2];
    n = read();
    for(p=0;p<n;p++)
    {
        x = x + read();
        y = y + read();
        //printf("x = %d\ty = %d\n",x,y);
        //x = x+pl[p-1].score;
        //y = y+pl[p-1].score;
        if(x>y)
        {
            pl[p].score = x-y;
            pl[p].player = 1;
        }
        else
        {
            pl[p].score = y-x;
            pl[p].player = 2;
        }
    }
    low = 0;
    high = n-1;
    quicksort(pl,low,high);
//    for(i=0;i<n;i++)
//    {
//        printf("%d %d\n",pl[i].score,pl[i].player);
//    }
    printf("\n%d %d\n",pl[n-1].player,pl[n-1].score);
    return 0;
}

