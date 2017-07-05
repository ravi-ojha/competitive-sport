#include<stdio.h>
int main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int n,i,x,y,ans,ser1=0,ser2=0,ser3=0,ser4=0;
        scanf(" %d",&n);
        for(i=0;i<n;i++)
        {
            scanf(" %d %d",&x,&y);
            ans = (x*x) + (y*y);
            if(ans<=3600)
            {
                ser1++;
            }
            else if(ans>3600 && ans<=14400)
            {
                ser2++;
            }
            else if(ans>14400 && ans<= 32400)
            {
                ser3++;
            }
            else if(ans>32400 && ans<=40000)
            {
                ser4++;
            }
        }
        printf("%d %d %d %d\n",ser1,ser2,ser3,ser4);
    }
    return 0;
}
