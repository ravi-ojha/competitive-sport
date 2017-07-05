#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
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
int main()
{
    int *left = new int [1000011];
    int *right = new int [1000011];
    int i;
    for(i=0;i<1000001;i++)
    {
        left[i] = 99999999;
        right[i] = 99999999;
    }
    int n,k;
    int a[500011];
    //scanf(" %d %d",&n,&k);
    fastRead_int(n);
    fastRead_int(k);
    for(i=1;i<=n;i++)
    {
        //printf("yes\n");
        //scanf(" %d",&a[i]);
        fastRead_int(a[i]);
        if(left[a[i]] > i)
        {
            left[a[i]] = i;
        }
        if(right[a[i]] > (n+1-i))
        {
            right[a[i]] = n+1-i;
        }
    }
    int res = 99999999;
    for(i=1;i<=n;i++)
    {
        //printf("wll\n");
        int first = a[i];
        int second = k - first;
        if(second > 0 && first!=second && left[second] != 99999999)
        {
            int for_first = min(i,n+1-i);
            int tmpres = max(for_first,min(left[second],right[second]));
            if(tmpres < res)
            {
                res = tmpres;
            }
        }
    }
    if(res == 99999999)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n",res);
    }
    return 0;
}
