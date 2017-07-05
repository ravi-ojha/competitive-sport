#include<iostream>
#include<cstdio>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n, p;
        scanf(" %d %d",&n,&p);
        char sa[n*n*n + 1], sb[n*n*n + 1];
        char ca[n][n][n], cb[n][n][n];
        scanf(" %[^\n]",sa);
        scanf(" %[^\n]",sb);
        int i,j,k;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    ca[i][j][k] = sa[i*n*n + j*n + k];
                    cb[i][j][k] = sb[i*n*n + j*n + k];
                }
            }
        }
        int c,cc,z;
        int size = 0;
        int y = n;
        while(y>0)
        {
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            cc = 0;
            for(z=0;z<n;z++)
            {
                int flag = 0;
                int x = p*y*y*y;
                if(x%100 == 0)
                {
                    x = x/100;
                }
                else
                {
                    x = x/100;
                    x++;
                }
                printf(" x = %d\n",x);
                c = 0;
                for(i=z;i<n && (i-z)<y;i++)
                {
                    for(j=z;j<n && (j-z)<y;j++)
                    {
                        for(k=z;k<n && (k-z)<y;k++)
                        {
                            printf(" %c %c\n",ca[i][j][k],cb[i][j][k]);
                            if(ca[i][j][k] == cb[i][j][k])
                            {
                                c++;
                            }
                            if(c>=x)
                            {
                                size = y;
                                flag = 1;
                                cc++;
                                break;
                            }
                        }
                        if(flag == 1)
                        {
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        break;
                    }
                }
            }
            if(cc != 0)
            {
                break;
            }
            y--;
            printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        }
        if(cc!=0)
        {
            printf("%d %d\n",size,cc);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
