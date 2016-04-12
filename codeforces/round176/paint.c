#include<stdio.h>
int main()
{
    char a[4][4];
    int count = 0,flag = 0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            count = 0;
            if(a[i][j] == a[i+1][j])
            count++;
            if(a[i][j] == a[i][j+1])
            count++;
            if(a[i][j] == a[i+1][j+1])
            count++;
            if(count != 1)
            {
                flag = 1;
                goto hell;
            }
        }
    }
    hell:
    if(flag == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
