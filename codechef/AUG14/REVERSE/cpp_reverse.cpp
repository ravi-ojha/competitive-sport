#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int res[100010];
vector < pair<int,int> > goku[100010];

int main()
{
    int n,m,i;
    scanf(" %d %d",&n,&m);

    for(i=0;i<100010;i++)
    {
        res[i] = 1000000007;
    }

    for(i=0;i<m;i++)
    {
        int x,y;
        scanf(" %d %d",&x,&y);
        /*if(x == y)
        {
            continue;
        }*/
        x--;
        y--;
        goku[x].push_back(make_pair(y, 0));
        goku[y].push_back(make_pair(x, 1));
    }

    priority_queue<pair<int,int>, vector < pair<int, int> >, greater< pair<int, int > > > fifo;
    fifo.push(make_pair(0,0));

    while(!fifo.empty())
    {
        int temp;
        temp = fifo.top().first;
        fifo.pop();
        int len = goku[temp].size();
        for(i=0;i<len;i++)
        {
            int k,j;
            k = goku[temp][i].first;
            j = goku[temp][i].second;
            if(res[k] > res[temp] + j)
            {
                res[k] = res[temp] + j;
                fifo.push(make_pair(k, res[k]));
            }
        }
    }
    if(res[n-1] == 1000000007)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",res[n-1]);
    }
    return 0;
}