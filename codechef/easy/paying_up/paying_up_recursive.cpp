#include<cstdio>
#include<iostream>
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
bool checkSubsetSum(int a[], int n, int m)
{
    if (m == 0)
    {
        return true;
    }
    if(n==0 && m!=0)
    {
        return false;
    }
    if(a[n-1] > m)
    {
        return checkSubsetSum(a,n-1,m);
    }
    return checkSubsetSum(a,n-1,m) || checkSubsetSum(a,n-1,m-a[n-1]);
}
int main()
{
    int t;
    //scanf(" %d",&t);
    fastRead_int(t);
    while(t--)
    {
        int n,m;
        int i,j;
        //scanf(" %d %d",&n,&m);
        fastRead_int(n);
        fastRead_int(m);
        int a[n];
        for(i=0;i<n;i++)
        {
            //scanf(" %d",&a[i]);
            fastRead_int(a[i]);
        }
        if(checkSubsetSum(a,n,m))
        {
            //cout<<"1"<<endl;
            printf("1\n");
        }
        else
        {
            //cout<<"0"<<endl;
            printf("0\n");
        }
    }
    return 0;
}
