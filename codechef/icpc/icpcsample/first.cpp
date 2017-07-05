#include<iostream>
#include<cstdio>
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n, m , r, first = 1 , second = 1, i;
        int turn = 0;
        int fw = 0;
        int sw = 0;
        scanf(" %d %d %d",&n, &m, &r);
        int grid[111];
        int s[111] = {0};
        for(i=0;i<m;i++)
        {
            int a, b;
            scanf(" %d %d",&a, &b);
            s[a] = b;
        }
        for(i=1;i<=n;i++)
        {
            int tmp = s[i];
            while(s[tmp]!=0)
            {
                s[i]=s[tmp];
                tmp = s[i];
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            printf("  %d",s[i]);
//        }
//        printf("\n\n");
        for(i=0;i<r;i++)
        {
            int d;
            if(first == n)
            {
                fw = 1;
                break;
            }
            if(second == n)
            {
                sw = 1;
                break;
            }
            scanf(" %d",&d);
            if(turn == 0)
            {
                if((first+d > n))
                {
                    if(d != 6)
                    {turn = 1;}
                    continue;
                }
                first += d;
                turn = 1;
                while(s[first] != 0)
                {
                    first = s[first];
                    turn = 0;
                }
                if(first == second)
                {
                    second = 1;
                }
                if(d == 6)
                {
                    turn = 0;
                }
            }
            else
            {
                if((second+d) > n )
                {
                    if(d != 6)
                    {turn = 0;}
                    continue;
                }
                second += d;
                turn = 0;
                while(s[second] != 0)
                {
                    second = s[second];
                    turn = 1;
                }
                if(first == second)
                {
                    first = 1;
                }
                if(d == 6)
                {
                    turn = 1;
                }
            }
        }
        while(i<r)
        {
            int z;
            scanf(" %d",&z);
        }
        if(fw == 1)
        printf("%d %d %d\n",1,first,second);
        else if(sw == 1)
        printf("%d %d %d\n",2,first,second);
        else
        printf("%d %d %d\n",0,first,second);
    }
    return 0;
}
