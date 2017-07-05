#include<iostream>
#include<cstdio>
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

void createTree(int node, int b, int e, long long M[], int A[])
{
    if (b == e)
        M[node] = A[b];
    else
    {
        createTree(2 * node, b, (b + e) / 2, M, A);
        createTree(2 * node + 1, (b + e) / 2 + 1, e, M, A);
        M[node] = M[2 * node] + M[2 * node + 1];
    }
}

void update(int node, int b, int e, long long M[], int idx, int val)
{
    if (b > idx || e < idx ) return;
    if (b == e)
    {
        M[node] = val;
        return;
    }
    update(node*2, b, (b+e)/2, M, idx, val);
    update(node*2 + 1, (b+e)/2 + 1, e, M, idx, val);

    M[node] = M[node*2] + M[node*2 + 1];
}
long long findRangeSum(int node, int b, int e, long long M[], int goku, int naruto)
{
    if(goku <= b && naruto >= e)
    {
        return M[node];
    }
    if(b > naruto || e < goku)
    {
        return 0;
    }
    return findRangeSum(2*node, b, (b+e)/2, M, goku, naruto) + findRangeSum(2*node + 1, (b+e)/2 + 1, e, M, goku, naruto);
}

int main()
{
    int n,q,i;
    //scanf(" %d %d",&n,&q);
    fastRead_int(n);
    fastRead_int(q);
    int a[n];
    long long result;
    long long *sumTree = new long long [2097152 + 1000];
    for(i=0;i<n;i++)
    {
        //scanf(" %d",&a[i]);
        fastRead_int(a[i]);
    }
    createTree(1,0,n-1,sumTree,a);
    for(i=0;i<q;i++)
    {
        char event;
        int x,y;
        int marbles;
        scanf(" %c",&event,&x,&y);
        fastRead_int(x);
        fastRead_int(y);
        switch(event)
        {
            case 'S':
                result = findRangeSum(1,0,n-1,sumTree,x,y);
                printf("%lld\n",result);
            break;

            case 'G':
                marbles = a[x] + y;
                //a[x] = a[x] + y;
                update(1,0,n-1,sumTree,x,marbles);
            break;

            case 'T':
                marbles = a[x] - y;
                //a[x] = a[x] - y;
                update(1,0,n-1,sumTree,x,marbles);
            break;
        }
    }
    return 0;
}
