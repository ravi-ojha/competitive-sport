#include<iostream>
#include<cstdio>
using namespace std;
class result{
public:
int c;
int u;
int d;
int l;
int r;
}resx[1000001],resy[1000001];
int main()
{
    int n,i,j;
    scanf(" %d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf(" %d",&a[i][j]);
        }
    }
    int z;
    int x = 0;
    for(i=0;i<n;i++)
    {
        j=0;
        while(j<n)
        {
            z = a[i][j];
            if(z!=0)
            {
                resx[x].c = z;
                resx[x].u = i+1;
                resx[x].l = j+1;
                while(j<n && a[i][j] == z)
                {
                    j++;
                }
                resx[x].d = i+1;
                resx[x].r = j;
                x++;
            }
            else
            {
                j++;
            }
        }
    }
    int y = 0;
    for(i=0;i<n;i++)
    {
        j=0;
        while(j<n)
        {
            z = a[j][i];
            if(z!=0)
            {
                resy[y].c = z;
                resy[y].u = j+1;
                resy[y].l = i+1;
                while(j<n && a[j][i] == z)
                {
                    j++;
                }
                resy[y].d = j;
                resy[y].r = i+1;
                y++;
            }
            else
            {
                j++;
            }
        }
    }
    if(x<=y)
    {
        printf("%d\n",x);
        for(i=0;i<x;i++)
        {
            printf("%d %d %d %d %d\n",resx[i].c,resx[i].u,resx[i].d,resx[i].l,resx[i].r);
        }
    }
    else
    {
        printf("%d\n",y);
        for(i=0;i<y;i++)
        {
            printf("%d %d %d %d %d\n",resy[i].c,resy[i].u,resy[i].d,resy[i].l,resy[i].r);
        }
    }
    return 0;
}
