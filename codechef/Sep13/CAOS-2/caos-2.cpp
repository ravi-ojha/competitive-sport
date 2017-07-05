#include<iostream>
#include<cstdio>
using namespace std;
struct dp
{
    int above;
    int below;
    int left;
    int right;
}dp[502][502];
int main()
{
    int primes[502] = {0, 0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 10, 10, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 17, 17, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 20, 20, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 26, 26, 27, 27, 27, 27, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 32, 32, 33, 33, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 35, 35, 36, 36, 36, 36, 36, 36, 37, 37, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 39, 39, 40, 40, 40, 40, 40, 40, 41, 41, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 43, 43, 44, 44, 44, 44, 45, 45, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 48, 48, 48, 48, 49, 49, 50, 50, 50, 50, 51, 51, 51, 51, 51, 51, 52, 52, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 54, 54, 54, 54, 54, 54, 55, 55, 55, 55, 55, 55, 56, 56, 56, 56, 56, 56, 57, 57, 58, 58, 58, 58, 58, 58, 59, 59, 59, 59, 60, 60, 61, 61, 61, 61, 61, 61, 61, 61, 61, 61, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 62, 63, 63, 63, 63, 64, 64, 65, 65, 65, 65, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 67, 67, 67, 67, 67, 67, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 69, 69, 70, 70, 70, 70, 71, 71, 71, 71, 71, 71, 72, 72, 72, 72, 72, 72, 72, 72, 73, 73, 73, 73, 73, 73, 74, 74, 74, 74, 74, 74, 75, 75, 75, 75, 76, 76, 76, 76, 76, 76, 77, 77, 77, 77, 77, 77, 77, 77, 78, 78, 78, 78, 79, 79, 79, 79, 79, 79, 79, 79, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 81, 81, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 83, 83, 84, 84, 84, 84, 84, 84, 85, 85, 85, 85, 86, 86, 86, 86, 86, 86, 87, 87, 87, 87, 87, 87, 87, 87, 88, 88, 88, 88, 89, 89, 90, 90, 90, 90, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 92, 92, 92, 92, 92, 92, 92, 92, 93, 93, 93, 93, 94, 94, 94, 94, 94, 94, 94, 94, 95, 95, 95};
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int k,i,j,c;
        int x,y,monster = 0,min;
        scanf(" %d %d",&x,&y);
        char a[502][502];
        for(i=0;i<x;i++)
        {
            scanf(" %s",a[i]);
        }
        for(i=0;i<y;i++)
        {
            c = 0;
            for(j=1;j<x && a[j][i] == '^';j++)
            {
                c++;
            }
            dp[0][i].below = c;
            dp[0][i].above = 0;
        }
        for(i=0;i<x;i++)
        {
            c = 0;
            for(j=1;j<y && a[i][j] == '^';j++)
            {
                c++;
            }
            dp[i][0].right = c;
            dp[i][0].left = 0;
        }
        for(j=1;j<y;j++)
        {
            if(a[0][j-1] == '^')
            {
                dp[0][j].left = dp[0][j-1].left + 1;
            }
            else
            {
                dp[0][j].left = 0;
            }
            if(a[0][j] == '^')
            {
                dp[0][j].right = dp[0][j-1].right - 1;
            }
            else
            {
                c = 0;
                for(k=j+1;k<y && a[0][k] == '^';k++)
                {
                    c++;
                }
                dp[0][j].right = c;
            }
            min = 1000000000;
            if(dp[0][j].above < min)
            {
                min = dp[0][j].above;
            }
            if(dp[0][j].below < min)
            {
                min = dp[0][j].below;
            }
            if(dp[0][j].left < min)
            {
                min = dp[0][j].left;
            }
            if(dp[0][j].right < min)
            {
                min = dp[0][j].right;
            }
            if(a[0][j] == '^')
            monster = monster + primes[min];
//            cout << monster;
        }
//        cout << endl;
        for(i=1;i<x;i++)
        {
            if(a[i-1][0] == '^')
            {
                dp[i][0].above = dp[i-1][0].above + 1;
            }
            else
            {
                dp[i][0].above = 0;
            }
            if(a[i][0] == '^')
            {
                dp[i][0].below = dp[i-1][0].below - 1;
            }
            else
            {
                c = 0;
                for(k=i+1;k<x && a[k][0] == '^';k++)
                {
                    c++;
                }
                dp[i][0].below = c;
            }
            min = 1000000000;
            if(dp[i][0].above < min)
            {
                min = dp[i][0].above;
            }
            if(dp[i][0].below < min)
            {
                min = dp[i][0].below;
            }
            if(dp[i][0].left < min)
            {
                min = dp[i][0].left;
            }
            if(dp[i][0].right < min)
            {
                min = dp[i][0].right;
            }
            if(a[i][0] == '^')
            monster = monster + primes[min];
//            cout << monster;
        }
//        cout << endl;
        for(i=1;i<x;i++)
        {
            for(j=1;j<y;j++)
            {
                if(a[i][j-1] == '^')
                {
                    dp[i][j].left = dp[i][j-1].left + 1;
                }
                else
                {
                    dp[i][j].left = 0;
                }
                if(a[i][j] == '^')
                {
                    dp[i][j].right = dp[i][j-1].right - 1;
                }
                else
                {
                    c = 0;
                    for(k=j+1;k<y && a[i][k] == '^';k++)
                    {
                        c++;
                    }
                    dp[i][j].right = c;
                }
                if(a[i-1][j] == '^')
                {
                    dp[i][j].above = dp[i-1][j].above + 1;
                }
                else
                {
                    dp[i][j].above = 0;
                }
                if(a[i][j] == '^')
                {
                    dp[i][j].below = dp[i-1][j].below - 1;
                }
                else
                {
                    c = 0;
                    for(k=i+1;k<x && a[k][j] == '^';k++)
                    {
                        c++;
                    }
                    dp[i][j].below = c;
                }
                min = 1000000000;
                if(dp[i][j].above < min)
                {
                    min = dp[i][j].above;
                }
                if(dp[i][j].below < min)
                {
                    min = dp[i][j].below;
                }
                if(dp[i][j].left < min)
                {
                    min = dp[i][j].left;
                }
                if(dp[i][j].right < min)
                {
                    min = dp[i][j].right;
                }
                if(a[i][j] == '^')
                monster = monster + primes[min];
                //cout << monster;
            }
            //cout << endl;
        }

//        for(i=0;i<y;i++)
//        {
//            cout << dp[0][i].below << " ";
//        }
//        cout << endl;
//        for(i=0;i<x;i++)
//        {
//            cout << dp[i][0].right << " ";
//        }
//        cout << endl;
//        for(i=1;i<x;i++)
//        {
//            for(j=1;j<y;j++)
//            {
//                if(a[i][j] == '^')
//                {
//                    //printf("hello");
//                    int pre[5] = {0};
//                    for(k=i+1;k<x && a[k][j]=='^';k++)
//                    {
//                        pre[0]++;
//                    }
//                    //printf("pre[0] = %d\n",pre[0]);
//                    for(k=i-1;k>=0 && a[k][j]=='^';k--)
//                    {
//                        pre[1]++;
//                    }
//                    //printf("pre[1] = %d\n",pre[1]);
//                    for(k=j+1;k<y && a[i][k]=='^';k++)
//                    {
//                        pre[2]++;
//                    }
//                    //printf("pre[2] = %d\n",pre[2]);
//                    for(k=j-1;k>=0 && a[i][k]=='^';k--)
//                    {
//                        pre[3]++;
//                    }
//                    //printf("pre[3] = %d\n",pre[3]);
//                    int min = 1000000000;
//                    for(k=0;k<4;k++)
//                    {
//                        if(pre[k]<min)
//                        {
//                            min = pre[k];
//                        }
//                    }
//                    //printf("min = %d\n",min);
//                    monster = monster + primes[min];
//                }
//            }
//        }
        printf("%d\n",monster);
    }
    return 0;
}
