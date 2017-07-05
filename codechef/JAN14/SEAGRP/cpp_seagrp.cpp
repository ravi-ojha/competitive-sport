#include<cstdio>
using namespace std;
int vis[110];
int grid[110][110];

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
     x = -x;
}

int dfs(int n, int c)
{
    int i,j;
    if(c == 0)
    {
        return 1;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                for(j=0;j<n;j++)
                {
                    if(vis[j] == 0 && grid[i][j] == 1)
                    {
                        vis[j] = 1;
                        if(dfs(n,c-2)) //backtrack
                        {
                            return 1;
                        }
                        vis[j] = 0;
                    }
                }
                vis[i] = 0;
                if(j >= n)
                {
                    return 0;
                }
            }
        }
        return 0;
    }
}

int main()
{
    int t;
    //scanf(" %d",&t);
    fastRead_int(t);
    while(t--)
    {
        int n,m,i,j;
        //scanf(" %d %d",&n,&m);
        fastRead_int(n);
        fastRead_int(m);
        for(i=0;i<110;i++)
        {
            vis[i] = 0;
            for(j=0;j<110;j++)
            {
                grid[i][j] = 0;
            }
        }
        for(i=0;i<m;i++)
        {
            int x,y;
            //scanf(" %d %d",&x,&y);
            fastRead_int(x);
            fastRead_int(y);
            x--;
            y--;
            grid[x][y] = 1;
            grid[y][x] = 1;
        }
        int c = n;
        if(n%2)
        {
            printf("NO\n");
        }
        else
        {
            if(dfs(n,c))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
