#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector < pair <int, int> > goku[100010];


int main()
{
    int n, m, i;
    scanf(" %d %d",&n,&m);
    int res[100010];

    for(i = 0; i <= 100010; i++)
    {
        res[i] = 1000000007;
    }

    for(i = 0; i < m; i++)
    {
        int x, y;
        scanf(" %d %d",&x,&y);
        goku[x].push_back(pair<int,int>(y, 0));
        goku[y].push_back(pair<int,int>(x, 1));
    }

    int s = 1;
    res[s] = 0;
    queue < pair<int,int> > q;
    q.push(make_pair(s, res[s]));

    while(!q.empty())
    {
        int z = q.front().first;
        q.pop();
        int len = goku[z].size();

        for(i = 0; i < len; i++)
        {
            int a = goku[z][i].first;
            int b = goku[z][i].second;

            if(res[a] > res[z] + b)
            {
                res[a] = res[z] + b;
                q.push(make_pair(a, res[a]));
            }
        }
    }
    if(res[n] == 1000000007)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",res[n]);
    }
    return 0;
}
