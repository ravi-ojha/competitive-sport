#include<stdio.h>
int fast_int()
{
        int n = 0;
        char c = getchar();
        while (!('0' <= c && c <= '9'))
        {
            c = getchar();
        }
        while ('0' <= c && c <= '9')
        {
            n = (n<<3)+(n<<1) + c - '0';
            c = getchar();
        }
        return n;
}

int main()
{
    int N,Q,C,k,l,temp;
    int x,maxX,y,maxY;
    N = fast_int();
    Q = fast_int();
    int a[N][2];
    for(k=0;k<N;k++)
    {
        //scanf(" %d %d",&a[k][0],&a[k][1]);
        a[k][0] = fast_int();
        a[k][1] = fast_int();
    }
    while(Q--)
    {
        int count = 0;
        //scanf(" %d %d %d",&x,&y,&C);
        x = fast_int();
        y = fast_int();
        C = fast_int();
        maxX = x+C;
        maxY = y+C;
        for(k=0;k<N;k++)
        {
            if(a[k][0]>=x && a[k][0]<=maxX)
            {
                if(a[k][1]>=y && a[k][1]<=(y+maxX-a[k][0]))
                    count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
