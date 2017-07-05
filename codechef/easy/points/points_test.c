#include<stdio.h>
#include<math.h>
#define BUFF 32*1024
char ibuf[BUFF];
int ipt=BUFF;
struct points{
int x;
int y;
int toSort;
};
//int read()
//{
//    int _n = 0;
//    char p = getchar_unlocked();
//    for(;p<33;) { p = getchar_unlocked(); }
//    while(p>32)
//    {
//        _n = (_n<<3) + (_n<<1) + (p-'0');
//        p = getchar_unlocked();
//    }
//    return _n;
//}
int geti()
{
// /*
int n=0;
while(ipt<BUFF && ibuf[ipt]<'0')ipt++;
if(ipt==BUFF)
{
ipt=0;
fread(ibuf,1,BUFF,stdin);
while(ipt<BUFF && ibuf[ipt]<'0')ipt++;
}
while(ipt<BUFF && ibuf[ipt]>='0')
n=(n*10)+(ibuf[ipt++]-'0');
if(ipt==BUFF)
{
ipt=0;
fread(ibuf,1,BUFF,stdin);
while(ipt<BUFF && ibuf[ipt]>='0')
n=(n*10)+(ibuf[ipt++]-'0');
}
return n;
}
int partition(struct points a[],int low, int high)
{
    struct points temp;
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

void quicksort(struct points a[],int low,int high)
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
    //scanf(" %d",&T);
    //T = read();
    T = geti();
    while(T--)
    {
        int i,j,low,high,m,n,k,l,a[100000][2],b[100000][2];
        struct points vert[100000];
        int N,linear = 0;
        float hypo = 0.0,t;
        //scanf(" %d",&N);
        //N = read();
        N = geti();
        for(i=0;i<N;i++)
        {
            //scanf(" %d %d",&vert[i].x,&vert[i].y);
//            vert[i].x = read();
//            vert[i].y = read();
            vert[i].x = geti();
            vert[i].y = geti();
            vert[i].toSort = vert[i].x*10000 + vert[i].y;
        }
        low = 0;
        high = N-1;
        quicksort(vert,low,high);

//        for(i=0;i<N;i++)
//        {
//            printf("point (%d %d)\n",vert[i].x,vert[i].y);
//        }
        j = 0;
        i = 0;
        k = 0;
        while(i<N)
        {
            while(i<N && (vert[i].x == vert[j].x))
            {
                i++;
            }
            a[k][0] = vert[j].x;
            a[k][1] = vert[j].y;
            b[k][0] = vert[i-1].x;
            b[k][1] = vert[i-1].y;
            k++;
            j = i;
        }
//        for(i=0;i<k;i++)
//        {
//            printf("a(%d %d)\t b(%d %d)\n",a[i][0],a[i][1],b[i][0],b[i][1]);
//        }
        linear = b[0][1] - a[0][1];
        for(i=1;i<k;i++)
        {
            linear = linear + b[i][1] - a[i][1];
            m = b[i][0] - a[i-1][0];
            n = b[i][1] - a[i-1][1];
            t = m*m + n*n;
            t = sqrt(t);
            hypo = hypo + t;
        }
//        while(i<N)
//        {
//            while(i<N && (vert[i].x == vert[j].x))
//            {
//                i++;
//            }
//            linear = linear + vert[i-1].y - vert[j].y;
//            k = i-1;
//            j = i;
//            while(i<N && (vert[i].x == vert[j].x))
//            {
//                i++;
//            }
//            l = i-1;
//            linear = linear + vert[i-1].y - vert[j].y;
//            printf(" %d %d\n",vert[l].x,vert[k].x);
//            printf(" %d %d\n",vert[l].y,vert[k].y);
//            m = (vert[l].x - vert[k].x);
//            n = (vert[l].y - vert[k].y);
//            t = m*m + n*n;
//            t = sqrt(t);
//            hypo = hypo + t;
//            j = i;
//        }
        //printf("hypo = %f\n",hypo);
        //printf("linear = %d\n",linear);
        //hypo = sqrt(hypo);
        hypo = hypo + linear;
        //printf("%f\n",hypo);
        printf("%.2f\n",hypo);
        //printf("%.2f\n",3.7777778);
    }
    return 0;
}
