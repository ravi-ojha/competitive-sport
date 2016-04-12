#include<stdio.h>
int main()
{
    int n,m,d,i,j,flag = 0,sum=0,ans =0,fact;
    float avg,t,min=10000000,value;
    scanf(" %d %d %d",&n,&m,&d);
    int a[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf(" %d",&a[i][j]);
            if((a[0][0] - a[i][j])%d != 0)
            {
                flag = 1;
            }
            sum = sum+a[i][j];
        }
    }

    if(flag == 1)
    {
        printf("-1\n");
    }
    else
    {
        fact = a[0][0]%d;
        avg = ((float)sum)/(n*m);
        value = ((int)avg/d)*d + fact;
        //printf("min v = %f",value);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                t = value - a[i][j];
                if(t < 0)
                {
                    t = -t;
                }
                ans = ans + t/d;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
