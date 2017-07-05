#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf(" %d",&n);
    float a[n];
    int minIndex = 0,  maxIndex = 0;
    float minValue = 1000000000.0, maxValue = -1;
    int i;
    for(i=0;i<n;i++)
    {
        int ax,ay,bx,by,cx,cy;
        float t;
        scanf(" %d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        t = ax*(by-cy) + bx*(cy-ay) + cx*(ay-by);
        if(t<0)
        {
            t = (-1)*t;
        }
        t = t/2;
        a[i] = t;
    }
    for(i=0;i<n;i++)
    {
        if(a[i] <= minValue)
        {
            minValue = a[i];
            minIndex = i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(a[i] >= maxValue)
        {
            maxValue = a[i];
            maxIndex = i;
        }
    }
    printf("%d %d\n",minIndex+1, maxIndex+1);
    return 0;
}
