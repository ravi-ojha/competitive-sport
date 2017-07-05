#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,m,i,j;
        int res = 0;
        scanf(" %d %d",&n,&m);
        int freq[401] = {0};
        vector <int> dis[401];
        int a[401];
        for(i=1;i<=m;i++)
        {
            scanf(" %d",&a[i]);
            freq[a[i]]++;
        }
        for(i=m;i>=0;i--)
        {
            dis[a[i]].push_back(i);
        }
        int b[401];
        int used[401] = {0};
        i = 1;
        j = 1;
        while(j<=n && i<=m)
        {
            if(!used[a[i]])
            {
                used[a[i]] = 1;
                b[j] = a[i];
                j++;
                res++;
            }
            dis[a[i]].pop_back();
            freq[a[i]]--;
            i++;
        }
        if(j > n)
        {
            while(i<=m)
            {
                if(!used[a[i]])
                {
                    used[a[i]] = 1;
                    int idx_to_remove = 0;
                    int mn = -1;
                    for(int k=1;k<=n;k++)
                    {
                        if(freq[b[k]] > 0)
                        {
                            if(dis[b[k]].back() > mn)
                            {
                                mn = dis[b[k]].back();
                                idx_to_remove = k;
                            }
                        }
                        else
                        {
                            idx_to_remove = k;
                            break;
                        }
                    }
                    //printf(" %d",b[idx_to_remove]);
                    used[b[idx_to_remove]] = 0;
                    b[idx_to_remove] = a[i];
                    res++;
                }
                dis[a[i]].pop_back();
                freq[a[i]]--;
                i++;
            }
            printf("%d\n",res);
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}
