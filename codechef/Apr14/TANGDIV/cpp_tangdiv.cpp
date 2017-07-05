#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,k,p,i,j;
        scanf(" %d %d %d",&n,&k,&p);
        int kx[5100],ky[5100];
        for(i=0;i<k;i++)
        {
            scanf(" %d %d",&kx[i],&ky[i]);
        }
        int flag = 0;
        int qx[5100],qy[5100];
        for(i=0;i<p;i++)
        {
            scanf(" %d %d",&qx[i],&qy[i]);
        }
        for(i=0;i<p;i++)
        {

            //flag = 0;
            int px,py;
            //scanf(" %d %d",&px,&py);
            px = qx[i];
            py = qy[i];
//            if(p > k)
//            {
//                flag = 1;
//                goto japan;
//            }
            for(j=0;j<k;j++)
            {
                if(kx[j] <= ky[j] && px <= py)
                {
                    if(!(px <= kx[j] && py >= ky[j]))
                    {
                        flag = 1;
                        goto japan;
                    }
                }
                if(kx[j] <= ky[j] && px > py)
                {
                    if(!(py < kx[j] && px > ky[j]))
                    {
                        flag = 1;
                        goto japan;
                    }
                }
                if(kx[j] > ky[j] && px <= py)
                {
                    if(!(px > ky[j] && py < kx[j]))
                    {
                        flag = 1;
                        goto japan;
                    }
                }
                if(kx[j] > ky[j] && px > py)
                {
                    if(!(px <= kx[j] && py >= ky[j]))
                    {
                        flag = 1;
                        goto japan;
                    }
                }
            }
        }
        japan:
        if(flag == 1)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}
