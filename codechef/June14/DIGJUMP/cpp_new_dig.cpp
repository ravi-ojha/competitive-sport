#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<int> v[10];
int slen;
int a[100010] = {0};
int vis[100010] = {0}, used[10] = {0};
char s[100010];
int main()
{
    int i;
    scanf(" %s",s);
    slen = strlen(s);
    if(slen == 1)
    {
        printf("0\n");
    }
    else
    {
        for(i=0;i<slen;i++)
        {
            v[s[i]-'0'].push_back(i);
        }
        queue<int> fifo;
        int curr, idx;
        fifo.push(0);
        a[0] = 0;
        vis[0] = 1;
        while(!fifo.empty())
        {
            curr = fifo.front();
            fifo.pop();
            if(curr == (slen-1))
            {
                printf("%d\n",a[curr]);
                return 0;
            }
            idx = s[curr]-'0';
            for(i=0;i<v[idx].size() && (used[idx] == 0);i++)
            {
                if(vis[v[idx][i]] == 1)
                {
                    continue;
                }
                vis[v[idx][i]] = 1;
                a[v[idx][i]] = a[curr]+1;
                fifo.push(v[idx][i]);
            }
            if(curr > 0 && vis[curr-1] == 0 && used[s[curr-1]-'0'] == 0 && s[curr] != s[curr-1])
            {
                vis[curr-1] = 1;
                a[curr-1] = a[curr]+1;
                fifo.push(curr-1);
            }
            if(curr < (slen-1) && vis[curr+1] == 0 && used[s[curr+1]-'0'] == 0 && s[curr] != s[curr+1])
            {
                vis[curr+1] = 1;
                a[curr+1] = a[curr]+1;
                fifo.push(curr+1);
            }
            used[idx] = 1;
        }
    }
    return 0;
}