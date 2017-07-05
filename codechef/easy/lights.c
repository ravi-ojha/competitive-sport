#include<stdio.h>


void toggle(int a[3][3],int i,int j)
{
    if(a[i][j] == 0)
    a[i][j] = 1;
    else
    a[i][j] = 0;
}

int main()
{
    int i,j,n,k;
    int a[3][3] = {1,1,1,1,1,1,1,1,1};
    for(k=0;k<9;k++)
    {
        scanf(" %d",&n);
        if(n&1)
        {
            switch(k)
            {
                case 0:
                toggle(a,0,0);
                toggle(a,0,1);
                toggle(a,1,0);
                break;
                case 1:
                toggle(a,0,0);
                toggle(a,0,1);
                toggle(a,0,2);
                toggle(a,1,1);
                break;
                case 2:
                toggle(a,0,2);
                toggle(a,0,1);
                toggle(a,1,2);
                break;
                case 3:
                toggle(a,0,0);
                toggle(a,1,0);
                toggle(a,1,1);
                toggle(a,2,0);
                break;
                case 4:
                toggle(a,0,1);
                toggle(a,1,0);
                toggle(a,1,1);
                toggle(a,1,2);
                toggle(a,2,1);
                break;
                case 5:
                toggle(a,0,2);
                toggle(a,1,1);
                toggle(a,1,2);
                toggle(a,2,2);
                break;
                case 6:
                toggle(a,1,0);
                toggle(a,2,0);
                toggle(a,2,1);
                break;
                case 7:
                toggle(a,1,1);
                toggle(a,2,0);
                toggle(a,2,1);
                toggle(a,2,2);
                break;
                case 8:
                toggle(a,1,2);
                toggle(a,2,1);
                toggle(a,2,2);
                break;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        printf("%d",a[i][j]);
        printf("\n");
    }
    return 0;
}
