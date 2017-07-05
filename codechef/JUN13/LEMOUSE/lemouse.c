#include<stdio.h>
int min(int i, int j)
{
    if(i<j)
    return i;
    else
    return j;
}
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int i,j,t1,t2;
        int n, m;
        scanf(" %d %d",&n,&m);
        char b[n+10][m+10];
        int a[n+10][m+10], acopy[n+10][m+10];
        int u[111][111] = {0,0};
        for(i=0;i<n;i++)
        {
            scanf(" %s",b[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(b[i][j] == '0')
                {
                    a[i][j] = 0;
                    acopy[i][j] = 0;
                }
                else
                {
                    a[i][j] = 1;
                    acopy[i][j] = 1;
                }
            }
        }
//        printf("\n\n");
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//            {
//                printf("%3d",a[i][j]);
//            }
//            printf("\n");
//        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    a[i][j] = a[i][j] + acopy[i+1][j] + acopy[i][j+1];
                    //u[0][0] = 1;
                    //v[0][0] = 1;
                    //u[0][1] = 1;
                    //v[0][1] = 1;
                    //u[1][0] = 1;
                    //v[1][0] = 1;
                }
                else if(i==0 && j!=0)
                {
                    if(j==(m-1))
                    {
                        a[i][j] = a[i][j-1] + acopy[1][j];
                        u[i][j] = 2;
                        //u[1][j] = 1;
                        //v[1][j] = 1;
                    }
                    else
                    {
                        a[i][j] = a[i][j-1] + acopy[i][j+1] + acopy[1][j];
                        u[i][j] = 2;
                        //u[i][j+1] = 1;
                        //v[i][j+1] = 1;
                        //u[1][j] = 1;
                        //v[1][j] = 1;
                    }
                }
                else if(i!=0 && j==0)
                {
                    if(i == (n-1))
                    {
                        a[i][j] = a[i-1][j] + a[i][1];
                        u[i][j] = 1;
                        //u[i][1] = 1;
                        //v[i][1] = 1;
                    }
                    else
                    {
                        a[i][j] = a[i-1][j] + a[i+1][j] + a[i][1];
                        u[i][j] = 1;
                        //u[i+1][j] = 1;
                        //v[i+1][j] = 1;
                        //u[i][1] = 1;
                        //v[i][1] = 1;
                    }
                }
                else if(i==1 && j==1)
                {
                    t1 = a[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    t2 = a[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                    //a[i][j] = min(a[i-1][j] + acopy[i][j+1] + acopy[i+1][j], a[i][j-1] + acopy[i][j+1] + acopy[i+1][j]);
                }
                else if (i==(n-1) && j == (m-1))
                {
                    a[i][j] = min(a[i-1][j],a[i][j-1]);
                }
                else if(i == (n-1))
                {
                    if(u[i-1][j] == 1)
                    {
                        t1 = a[i-1][j] + acopy[i][j-1] + acopy[i][j+1];
                    }
                    else
                    {
                        t1 = a[i-1][j] + acopy[i][j+1];
                    }
                    if(u[i][j-1] == 1)
                    {
                        t2 = a[i][j-1] + acopy[i][j+1];
                    }
                    else
                    {
                        t2 = a[i][j-1] + acopy[i-1][j] + acopy[i][j+1];
                    }
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                    //a[i][j] = min(a[i][j-1] + acopy[i-1][j] + acopy[i][j+1], acopy[i][j-1] + a[i-1][j] + acopy[i][j+1]);
                }
                else if(j == (m-1))
                {
                    if(u[i-1][j] == 1)
                    {
                        t1 = a[i-1][j] + acopy[i][j-1] + acopy[i+1][j];
                    }
                    else
                    {
                        t1 = a[i-1][j] + acopy[i+1][j];
                    }
                    if(u[i][j-1] == 1)
                    {
                        t2 = a[i][j-1] + acopy[i+1][j];
                    }
                    else
                    {
                        t2 = a[i][j-1] + acopy[i-1][j] + acopy[i+1][j];
                    }
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                    //a[i][j] = min(a[i-1][j] + acopy[i][j-1] + acopy[i+1][j], acopy[i-1][j] + a[i][j-1] + acopy[i+1][j]);
                }
                else if(i==1 && j!= 1)
                {
                    t1 = a[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    if(u[i][j-1] == 1)
                    {
                        t2 = a[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    else
                    {
                        t2 = a[i][j-1] + acopy[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                }
                else if(i!=1 && j==1)
                {
                    if(u[i-1][j] == 1)
                    {
                        t1 = a[i-1][j] + acopy[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    else
                    {
                        t1 = a[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    t2 = a[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                }


                else
                {
                    if(u[i-1][j] == 1)
                    {
                        t1 = a[i-1][j] + acopy[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    else
                    {
                        t1 = a[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    if(u[i][j-1] == 1)
                    {
                        t2 = a[i][j-1] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    else
                    {
                        t2 = a[i][j-1] + acopy[i-1][j] + acopy[i][j+1] + acopy[i+1][j];
                    }
                    if(t1<=t2)
                    {
                        u[i][j] = 1;
                        a[i][j] = t1;
                    }
                    else
                    {
                        u[i][j] = 2;
                        a[i][j] = t2;
                    }
                    //a[i][j] = min(a[i-1][j] + acopy[i][j-1] + acopy[i][j+1] + acopy[i+1][j], acopy[i-1][j] + a[i][j-1] + acopy[i][j+1] + acopy[i+1][j]);
                }
            }
        }
//        printf("\n\n");
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//            {
//                printf("%3d",u[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n\n");
//        for(i=0;i<n;i++)
//        {
//            for(j=0;j<m;j++)
//            {
//                printf("%3d",a[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",a[n-1][m-1]);
    }
    return 0;
}
