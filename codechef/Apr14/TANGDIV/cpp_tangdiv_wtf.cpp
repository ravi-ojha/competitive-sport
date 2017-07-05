#include<cstdio>
#include<iostream>
#include<set>
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
    int t;
    //scanf(" %d",&t);
    fastRead_int(t);
    while(t--)
    {
        int n,k,p,i;
        //scanf(" %d %d %d",&n,&k,&p);
        fastRead_int(n);
        fastRead_int(k);
        fastRead_int(p);
        int kx[510];
        int ky[510];
        for(i=0;i<k;i++)
        {
            //scanf(" %d %d",&kx[i],&ky[i]);
            fastRead_int(kx[i]);
            fastRead_int(ky[i]);
        }
        int flag = 0;
        int qx[510],qy[510];
        for(i=0;i<p;i++)
        {
            //scanf(" %d %d",&qx[i],&qy[i]);
            fastRead_int(qx[i]);
            fastRead_int(qy[i]);
        }
        set <int> goku;
        for(i=0;i<k;i++)
        {
            if(kx[i] == n)
            {
                goku.insert(0);
            }
            else
            {
                goku.insert(kx[i]);
            }
            goku.insert(ky[i]);
        }
        for(i=0;i<p;i++)
        {
            int x,y;
            if(qx[i] == n)
            {
                x = 0;
            }
            else
            {
                x = qx[i];
            }
            y = qy[i];
            set<int>::iterator it = goku.end();
            if(goku.find(x) ==  it || goku.find(y) == it)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}
