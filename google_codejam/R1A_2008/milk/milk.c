#include<stdio.h>
int main()
{
    int T,p;
    scanf(" %d",&T);
    for(p=1;p<=T;p++)
    {
        int C,N,M;
        scanf(" %d",&C);
        int a[101] = {0};
        scanf(" %d",&N);
        for(i=0;i<N;i++)
        {
            scanf(" %d",&M);
            int b[M][2];
            for(j=0;j<M;j++)
            {
                scanf(" %d",&b[j][0]);
                scanf(" %d",&b[j][1]);
                //if()
            }
            if(j==1 && b[0][1] == 1)
            {
                if(a[b[0][0]] == 0 || a[b[0][0] == 1)
                a[b[0][0]] = 2;
            }
            if(j==1 && b[0][1] == 0)
            {
                if(a[b[0][0]] == 0 || a[b[0][0]] == 2) //for impossible
                a[b[0][0]] = 1;
            }
        }
    }
}
