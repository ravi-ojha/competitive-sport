#include<stdio.h>
#define get getchar_unlocked

inline int scan()
{
    int n=0,s=1;
    char p=get();
    if(p=='-') s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}

int Parent[100002];
int PeopleInRoute[100002];

int FindParent(int Child)
{
    return Parent[Child] = (Parent[Child]==Child) ? Child : FindParent(Parent[Child]);
}
void makeUnion(int a,int b)
{
    Parent[FindParent(a)] = FindParent(b);
}

int main()
{
    int i,T,N,M,A,B,Routes;
    long long int SelectionWays;
    T = scan();
    while(T--)
    {
        SelectionWays=1; Routes=0;
        N = scan(); M = scan();
        for(i=1;i<=N;i++)
            PeopleInRoute[Parent[i]=i]=0; // Parent[i] = i; PeopleInRoutes[i] = 0;
        while(M--)
        {
            A = scan(); B = scan();
            makeUnion(A,B);
            //printf(" %d %d %d\n",Parent[1],Parent[2],Parent[3]);
        }
        for(i=1;i<=N;i++)
            PeopleInRoute[FindParent(i)]++;
        for(i=1;i<=N;i++)
            if(PeopleInRoute[i])
            {
                SelectionWays = (SelectionWays*PeopleInRoute[i])%1000000007;
                Routes++;
            }
        printf("%d %lld\n",Routes,SelectionWays);
    }
return 0;
}
