#include<stdio.h>

#define MOD 3046201

// Fast Input Begin
int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}
// Fast Input End


// Precalculation of Factorial upto 3000000 - Begin
long long int fac[3000001];

void fact()
{
    int i;
    for(i=1;i<3000001;i++)
    {
        fac[i] = (fac[i-1]*i)%MOD;
    }
}
// Precalculation of Factorial upto 3000000 - End


// Fast Power Begin
long long fast_pow(int a,int n)
{
    long long result = 1;
    long long power = n;
    long long value = a;
    while(power>0)
    {
        if(power&1)
            {result = result*value;
            result = result%MOD;}
        value = value*value;
        value = value%MOD;
        power /= 2;
        //power >>= 1;
    }
    return result;
}
// Fast Power End

// Finding Modular Multiplicative Inverse Begin
long long int inv(long long int x)
{
    return fast_pow(x,MOD-2);
}
// Finding Modular Multiplicative Inverse End


// Building Segment Tree - Begin
// node = 1
// b = first position of our array A[]
// e = last position of our array A[]
// M = tree[] array
// A = a[] array
void createTree(int node, int b, int e, int M[], int A[])
{
    if (b == e)
        M[node] = A[b];
    else
    {
        //compute the values in the left and right subtrees
        createTree(2 * node, b, (b + e) / 2, M, A);
        createTree(2 * node + 1, (b + e) / 2 + 1, e, M, A);

        //doing stuff with children nodes
        // In this case, we are storing sum of both the children nodes in parent node
        M[node] = M[2 * node] + M[2 * node + 1];
    }
}
// Building Segment Tree - End


// Updating Tree on changing any node value
// idx = position which is to be updated by value 'val'
void update(int node, int b, int e, int M[], int idx, int val)
{
    if (b > e || b > idx || e < idx ) return;               // this condition is damn important
    if (b == e) //at leaf node
    {
        M[node] = val;
        return;
    }
    update(node*2, b, (b+e)/2, M, idx, val);
    update(node*2 + 1, (b+e)/2 + 1, e, M, idx, val);

    M[node] = M[node*2] + M[node*2 + 1];
}

// goku = range begin
// naruto - range end
int findRangeSum(int node, int b, int e, int M[], int goku, int naruto)
{
    if(goku <= b && naruto >= e)     // yeah... this condition is very confusing
    {
        return M[node];
    }
    if(b > naruto || e < goku)      // means you are in the wrong neighbourhood buddy
    {
        return 0;
    }
    return findRangeSum(2*node, b, (b+e)/2, M, goku, naruto) + findRangeSum(2*node + 1, (b+e)/2 + 1, e, M, goku, naruto);
}

int main()
{
    int n,q,i,goku,naruto,k,j;
    fac[0] = 1;
    fact();
    int tree[262143 + 1000] = {0};    // 262143 is (2*2^log(base2) 100001) - 1, added 1000 just for safety
    //scanf(" %d",&n);
    n = read();
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i] = read();
        //scanf(" %d",&a[i]);
    }
    createTree(1,0,n-1,tree,a);
    for(i=0;i<20;i++)
    {
        printf(" %3d",i);
    }
    printf("\n");
    for(i=0;i<20;i++)
    {
        printf(" %3d",tree[i]);
    }
    //scanf(" %d",&q);
    q = read();
//    update(1,0,n-1,tree,4,2);
//    for(i=0;i<20;i++)
//    {
//        printf(" %3d",i);
//    }
//    for(i=0;i<20;i++)
//    {
//        printf(" %3d",tree[i]);
//    }
int res;
    for(k=0;k<q;k++)
    {
        char ask[11];
        scanf(" %s",ask);
        //gets(ask);
        //scanf(" %d %d",&goku,&naruto);
        goku = read();
        naruto = read();
        if(ask[0] == 'c')
        {
            update(1,0,n-1,tree,goku-1,naruto);
            //printf(" %d",res);
            //    update(1,0,n-1,tree,4,2);
//            for(i=0;i<20;i++)
//            {
//                printf(" %3d",i);
//            }
//            printf("\n");
//            for(i=0;i<20;i++)
//            {
//                printf(" %3d",tree[i]);
//            }
        }
        else
        {
            res = findRangeSum(1,0,n-1,tree,goku-1,naruto-1);
            //printf(" %d",res);
            int people = naruto - goku + 1;
            if(people == 1)
            {
                printf("1\n");
            }
            else
            {
                int atleast = res/people;

                // real combination starts now
                long long int num = (fac[res]*fac[people])%MOD;
                long long int din = 1;
                int happy = res%people;
                long long int happyInv = fac[atleast+1];
                long long happyInv2 = fac[happy];
                din = (din*fast_pow(happyInv,happy))%MOD;

                din = (din*happyInv2)%MOD;
                long long sadInv = fac[atleast];
                long long sadInv2 = fac[people - happy];
                din = (din*fast_pow(sadInv,people-happy))%MOD;

                din = (din*sadInv2)%MOD;
                din = inv(din);
                printf("%lld\n",(num*din)%MOD);
                // end of combination & printing out the answer
            }
        }
    }
    return 0;
}
