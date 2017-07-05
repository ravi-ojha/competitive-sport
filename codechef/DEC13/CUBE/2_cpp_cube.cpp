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
        int dp[n][n][n];
        if(ca[0][0][0] == cb[0][0][0])
        {
            dp[0][0][0] = 1;
        }
        else
        {
            dp[0][0][0] = 0;
        }

        //linear 1D, Downward
        for(i=1;i<n;i++)
        {
            dp[i][0][0] = dp[i-1][0][0];
            if(ca[i][0][0] == cb[i][0][0])
            {
                dp[i][0][0]++;
            }
        }
        //linear 1D, Right Hand Side
        for(j=1;j<n;j++)
        {
            dp[0][j][0] = dp[0][j-1][0];
            if(ca[0][j][0] == cb[0][j][0])
            {
                dp[0][j][0]++;
            }
        }
        //linear 1D, Going inside the plane of paper
        for(k=1;k<n;k++)
        {
            dp[0][0][k] = dp[0][0][k-1];
            if(ca[0][0][k] == cb[0][0][k])
            {
                dp[0][0][k]++;
            }
        }

        //2D - Along the plane of paper
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                dp[i][j][0] = dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0];
                if(ca[i][j][0] == cb[i][j][0])
                {
                     dp[i][j][0]++;
                }
            }
        }
        //2D - Along the plane which becomes visible when viewed from top
        for(j=1;j<n;j++)
        {
            for(k=1;k<n;k++)
            {
                dp[0][j][k] = dp[0][j-1][k] + dp[0][j][k-1] - dp[0][j-1][k-1];
                if(ca[0][j][k] == cb[0][j][k])
                {
                     dp[0][j][k]++;
                }
            }
        }
        //2D - Along the plane which becomes visible when viewed from left
        for(i=1;i<n;i++)
        {
            for(k=1;k<n;k++)
            {
                dp[i][0][k] = dp[i-1][0][k] + dp[i][0][k-1] - dp[i-1][0][k-1];
                if(ca[i][0][k] == cb[i][0][k])
                {
                     dp[i][0][k]++;
                }
            }
        }

        //3D - Along the cube
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                for(k=1;k<n;k++)
                {
                    dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1] - dp[i-1][j-1][k] - dp[i-1][j][k-1] - dp[i][j-1][k-1] + dp[i-1][j-1][k-1];
                    if(ca[i][j][k] == cb[i][j][k])
                    {
                        dp[i][j][k]++;
                    }
                }
            }
        }
        int z,temp;
        int c_size = 0;
        for(z=(n-1);z>=0;z--)
        {
            int exp = p*(z+1)*(z+1)*(z+1);
            if(exp%100 == 0)
            {
                exp = exp/100;
            }
            else
            {
                exp = exp/100;
                exp++;
            }
            //printf(" exp = %d\n",exp);
            for(i=n-1;(i-z) >= 0;i--)
            {
                for(j=n-1;(j-z) >= 0;j--)
                {
                    for(k=n-1;(k-z) >= 0;k--)
                    {
                        if((i-z) != 0 && (j-z) != 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i][j-z-1][k] - dp[i-z-1][j][k] + dp[i][j-z-1][k-z-1] + dp[i-z-1][j][k-z-1] + dp[i-z-1][j-z-1][k] - dp[i-z-1][j-z-1][k-z-1];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) == 0 && (j-z) != 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i][j-z-1][k] + dp[i][j-z-1][k-z-1];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) != 0 && (j-z) == 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i-z-1][j][k] + dp[i-z-1][j][k-z-1];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) != 0 && (j-z) != 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i][j-z-1][k] - dp[i-z-1][j][k] + dp[i-z-1][j-z-1][k];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) != 0 && (j-z) == 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i-z-1][j][k];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) == 0 && (j-z) != 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i][j-z-1][k];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else if((i-z) == 0 && (j-z) == 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1];
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                        else
                        {
                            temp = dp[i][j][k];
                            //printf(" temp = %d\n",temp);
                            if(temp >= exp)
                            {
                                c_size = z+1;
                                goto japan;
                            }
                        }
                    }
                }
            }
        }
        japan:
        if(c_size == 0)
        {
            printf("-1\n");
        }
        else
        {
            z = c_size;
            z--;
            int c_cnt = 0;
            int exp = p*(z+1)*(z+1)*(z+1);
            if(exp%100 == 0)
            {
                exp = exp/100;
            }
            else
            {
                exp = exp/100;
                exp++;
            }
            for(i=n-1;(i-z) >= 0;i--)
            {
                for(j=n-1;(j-z) >= 0;j--)
                {
                    for(k=n-1;(k-z) >= 0;k--)
                    {
                        if((i-z) != 0 && (j-z) != 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i][j-z-1][k] - dp[i-z-1][j][k] + dp[i][j-z-1][k-z-1] + dp[i-z-1][j][k-z-1] + dp[i-z-1][j-z-1][k] - dp[i-z-1][j-z-1][k-z-1];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) == 0 && (j-z) != 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i][j-z-1][k] + dp[i][j-z-1][k-z-1];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) != 0 && (j-z) == 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1] - dp[i-z-1][j][k] + dp[i-z-1][j][k-z-1];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) != 0 && (j-z) != 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i][j-z-1][k] - dp[i-z-1][j][k] + dp[i-z-1][j-z-1][k];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) != 0 && (j-z) == 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i-z-1][j][k];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) == 0 && (j-z) != 0 && (k-z) == 0)
                        {
                            temp = dp[i][j][k] - dp[i][j-z-1][k];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else if((i-z) == 0 && (j-z) == 0 && (k-z) != 0)
                        {
                            temp = dp[i][j][k] - dp[i][j][k-z-1];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                        else
                        {
                            temp = dp[i][j][k];
                            if(temp >= exp)
                            {
                                c_cnt++;
                            }
                        }
                    }
                }
            }
            printf("%d %d\n",c_size,c_cnt);
        }
    }
    return 0;
}
