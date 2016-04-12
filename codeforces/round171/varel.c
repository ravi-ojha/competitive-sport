#include<stdio.h>
int main()
{
    int x,y;
    scanf(" %d %d",&x,&y);
    if((x-y)<0 && (x+y)>=0)
    {
        printf("%d\n",2+4*(y-1));
    }
    else if((x-y)<0 &&(x+y)<0)
    {
        printf("%d\n",3+4*(-x-1));
    }
    else if((x-y)>0 && (x+y-1)<=0)
    {
        printf("%d\n",4*(-y));
    }
    else if((x-y)>=0 && (x+y-1)>0)
    {
        printf("%d",1+4*(x-1));
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
