#include<cstdio>
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
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int n,m;
        int i,j;
        scanf(" %d %d",&n,&m);
        int a[n];
        for(i=0;i<n;i++)
        {
            scanf(" %d",&a[i]);
        }
        int upto = 1<<n;
        //printf("upto == %d\n",upto);
        int shift = 0;
        int flag = 0;
        for(i=0;i<upto;i++)
        {
            int bugger = 0;
            j = i;
            for(shift = 0; shift<n; shift++)
            {
                if((j>>shift)&1)
                {
                    bugger += a[shift];
                }
            }
            if(bugger == m)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
