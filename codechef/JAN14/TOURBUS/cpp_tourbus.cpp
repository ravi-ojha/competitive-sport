#include<cstdio>
using namespace std;

int a[100][100];

struct vertex
{
    int x;
    int y;
} vertexs[100];

int find_pos(vertex p, vertex q, vertex r)
{
    int z;
    z = ((q.y - p.y) * (r.x - q.x)) - ((q.x - p.x) * (r.y - q.y));
    if (z == 0)
    {
        return 0;
    }
    if(z < 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int check_cut(vertex p1, vertex q1, vertex p2, vertex q2)
{
    int r1, r2, r3, r4;
    r1 = find_pos(p1, q1, p2);
    r2 = find_pos(p1, q1, q2);
    r3 = find_pos(p2, q2, p1);
    r4 = find_pos(p2, q2, q1);
    if (r1 != r2 && r3 != r4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char path[100][100];
    int vis[55] = {0};
    int t,n,res[3000][100],k=0,flag,i,j,l;
    scanf(" %d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %d %d",&vertexs[i].x,&vertexs[i].y);
    }
    for(i=0; i<n; i++)
    {
        scanf(" %s",path[i]);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(path[i][j]=='Y' && a[i][j]==0)
            {
                a[i][j]=1;
                a[j][i]=1;
                res[k][0]=1;
                res[k][1]=i;
                res[k][2]=j;
                vis[i]=1;
                vis[j]=1;
                int x=i,y=j;
                flag = 1;
                while(flag)
                {
                    flag = 0;
                    for(l=0; l<n; l++)
                    {
                        if(path[y][l]=='Y' && a[y][l]==0 && vis[l]==0)
                        {
                            int v = 0;
                            for(int w=1; w<res[k][0]; w++)
                            {
                                v = check_cut(vertexs[y], vertexs[l], vertexs[res[k][w]], vertexs[res[k][w+1]]);
                                if(v)
                                {
                                    break;
                                }
                            }
                            if(v == 0)
                            {
                                res[k][0]++;
                                int o = res[k][0];
                                res[k][o+1] = l;
                                vis[l] = 1;
                                a[y][l] = 1;
                                a[l][y] = 1;
                                flag = 1;
                                x = y;
                                y = l;
                            }
                        }
                    }
                }
                int xi = res[k][res[k][0] + 1];
                int yi = res[k][1];
                if(a[x][y] == 0 && path[x][y] == 'Y')
                {
                    res[k][0]++;
                    res[k][res[k][0] + 1] = y;
                }
                k++;
                for(i=0;i<55;i++)
                {
                    vis[i] = 0;
                }
            }
        }
    }
    printf("%d\n",k);
    for(i=0; i<k; i++)
    {
        printf("%d ",res[i][0]);
        for(j=1; j <= (res[i][0]+1); j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
