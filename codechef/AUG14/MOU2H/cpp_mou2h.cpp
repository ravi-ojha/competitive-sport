#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int pos[4000010];
int neg[4000010];
int res[2000010] = {0};

int main()
{
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,i;
        /*for(i=0;i<3000010;i++)
        {
            pos[i] = 0;
            neg[i] = 0;
            res[i] = 0;
        }*/
        scanf(" %d",&n);
        int a[n];

        int shift;
        scanf(" %d",&shift);

        for(i=1;i<n;i++)
        {
            int z;
            scanf(" %d",&z);
            a[i] = shift - z;
            if(a[i]<0)
            {
                int p_ai = (-1)*a[i];
                neg[p_ai] = 0;
            }
            else
            {
                pos[a[i]] = 0;
            }
            shift = z;
        }

        res[0] = 1;
        for(i=1; i<n; i++)
        {
            res[i] = 2*res[i-1];
            if(a[i] < 0)
            {
                int p_ai = (-1)*a[i];
                if(neg[p_ai])
                {
                    res[i] -= res[neg[p_ai]-1];
                }
                neg[p_ai] = i;
            }
            else
            {
                if(pos[a[i]])
                {
                    res[i] -= res[pos[a[i]]-1];
                }
                pos[a[i]] = i;
            }

            if(res[i]<0)
            {
                res[i] += 1000000009;
            }
            res[i] %= 1000000009;
        }
        printf("%d\n", res[n-1]-1);
    }
    return 0;
}