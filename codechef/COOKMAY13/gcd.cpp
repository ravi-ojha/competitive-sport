#include<iostream>
#include<cstdio>
using namespace std;

int gcd(int a,int b)
{
    int t;
    while(a)
    {
        t = a;
        a = b%a;
        b = t;
    }
    return b;
}

int main()
{
    int T;
    //cin>>T;
    scanf(" %d",&T);
    while(T--)
    {
        int N,ans,i;
        //cin>>N;
        scanf(" %d",&N);
        int a[N];
        for(i=0;i<N;i++)
        {
            //cin>>a[i];
            scanf(" %d",&a[i]);
        }
        ans = a[0];
        for(i=1;i<N;i++)
        {
            ans = gcd(ans,a[i]);
        }
        cout<<ans<<endl;
        //printf("%d\n",ans);
    }
    return 0;
}
