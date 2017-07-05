#include<iostream>
#include<string>
#define lim 1000141
#define LL long long
using namespace std;
int c[lim]={0};
int h[lim]={0};
int e[lim]={0};
int f[lim]={0};
int ch[lim]={0};
int ce[lim]={0};
int cf[lim]={0};
int hc[lim]={0};
int he[lim]={0};
int hf[lim]={0};
int ec[lim]={0};
int eh[lim]={0};
int ef[lim]={0};
int fc[lim]={0};
int fh[lim]={0};
int fe[lim]={0};
int main()
{
    char Str[lim];
    gets(Str);
    int i;
    int len=strlen(Str);
    for(i=len;i>=1;i--)
    {
        c[i]=c[i+1]; h[i]=h[i+1]; e[i]=e[i+1]; f[i]=f[i+1];
        if(Str[i-1]=='c') c[i]++;
        if(Str[i-1]=='h') h[i]++;
        if(Str[i-1]=='e') e[i]++;
        if(Str[i-1]=='f') f[i]++;
    }
    //for(i=1;i<=len;i++)
      //  printf("%d %d %d %d\n",c[i],h[i],e[i],f[i]);
    for(i=1;i<=len;i++)
    {
        ch[i]=ch[i-1];
        ce[i]=ce[i-1];
        cf[i]=cf[i-1];
        hc[i]=hc[i-1];
        he[i]=he[i-1];
        hf[i]=hf[i-1];
        ec[i]=ec[i-1];
        eh[i]=eh[i-1];
        ef[i]=ef[i-1];
        fc[i]=fc[i-1];
        fh[i]=fh[i-1];
        fe[i]=fe[i-1];
        if(Str[i]=='c')
        {
            ch[i]+=h[i];
            ce[i]+=e[i];
            cf[i]+=f[i];
        }
        if(Str[i]=='h')
        {
            hc[i]+=c[i];
            he[i]+=e[i];
            hf[i]+=f[i];
        }
        if(Str[i]=='e')
        {
            ec[i]+=c[i];
            eh[i]+=h[i];
            ef[i]+=f[i];
        }
        if(Str[i]=='f')
        {
            fc[i]+=c[i];
            fh[i]+=h[i];
            fe[i]+=e[i];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        char a,b;
        int l,r;
        cin>>a>>b>>l>>r;
        //printf("%c %c %d %d\n",a,b,l,r);
        if(a=='c')
        {
            if(b=='h')
            {
                LL m = c[l] - c[r+1];
                LL Ans = ch[r] - ch[l-1];
                Ans = Ans - m*h[r+1];
                printf("%lld\n",Ans);
            }
            else if(b=='e')
            {
                LL m = c[l] - c[r+1];
                LL Ans = ce[r] - ce[l-1];
                Ans = Ans - m*e[r+1];
                printf("%lld\n",Ans);
            }
            else
            {
                LL m = c[l] - c[r+1];
                LL Ans = cf[r] - cf[l-1];
                Ans = Ans - m*f[r+1];
                printf("%lld\n",Ans);
            }
        }
        else if(a=='h')
        {
            if(b=='c')
            {
                LL m = h[l] - h[r+1];
                LL Ans = hc[r] - hc[l-1];
                Ans = Ans - m*c[r+1];
                printf("%lld\n",Ans);
            }
            else if(b=='e')
            {
                LL m = h[l] - h[r+1];
                LL Ans = he[r] - he[l-1];
                Ans = Ans - m*e[r+1];
                printf("%lld\n",Ans);
            }
            else
            {
                LL m = h[l] - h[r+1];
                LL Ans = hf[r] - hf[l-1];
                Ans = Ans - m*f[r+1];
                printf("%lld\n",Ans);
            }
        }
        else if(a=='e')
        {
            if(b=='c')
            {
                LL m = e[l] - e[r+1];
                LL Ans = ec[r] - ec[l-1];
                Ans = Ans - m*c[r+1];
                printf("%lld\n",Ans);
            }
            else if(b=='h')
            {
                LL m = e[l] - e[r+1];
                LL Ans = eh[r] - eh[l-1];
                Ans = Ans - m*h[r+1];
                printf("%lld\n",Ans);
            }
            else
            {
                LL m = e[l] - e[r+1];
                LL Ans = ef[r] - ef[l-1];
                Ans = Ans - m*f[r+1];
                printf("%lld\n",Ans);
            }
        }
        else
        {
            if(b=='c')
            {
                LL m = f[l] - f[r+1];
                LL Ans = fc[r] - fc[l-1];
                Ans = Ans - m*c[r+1];
                printf("%lld\n",Ans);
            }
            else if(b=='h')
            {
                LL m = f[l] - f[r+1];
                LL Ans = fh[r] - fh[l-1];
                Ans = Ans - m*h[r+1];
                printf("%lld\n",Ans);
            }
            else
            {
                LL m = f[l] - f[r+1];
                LL Ans = fe[r] - fe[l-1];
                Ans = Ans - m*e[r+1];
                printf("%lld\n",Ans);
            }
        }
    }
    return 0;
}
