#include<stdio.h>

int fast_int()
{
        int n = 0;
    int negflag=0;
        char c = getchar_unlocked();
    if(c=='-')
        negflag=1;
        while (!('0' <= c && c <= '9'))
        {
                c = getchar_unlocked();
        }
        while ('0' <= c && c <= '9')
        {
                n = (n<<3)+(n<<1) + c - '0';
                c = getchar_unlocked();
        }
    if(negflag==1)
        n*=-1;
        return n;
}
// Building Segment Tree - Begin
// node = 1
// b = first position of our array A[]
// e = last position of our array A[]
// M = tree[] array
// A = a[] array
void createTree(int node, int b, int e, long long SumTree[], int A[])
{
    if (b == e)
    {
        SumTree[node] = A[b];
    }
    else
    {
        //compute the values in the left and right subtrees
        createTree(2 * node, b, (b + e) / 2, SumTree, A);
        createTree(2 * node + 1, (b + e) / 2 + 1, e, SumTree, A);

        //doing stuff with children nodes
        //In this case, we are storing sum of both the children nodes in parent node
        SumTree[node] = SumTree[2*node] + SumTree[2*node + 1];
    }
}

// Building Segment Tree - End
// Updating Tree on changing any node value
// idx = position which is to be updated by value 'val'
void update(int node, int b, int e, long long SumTree[], int idx, int val)
{
    if (b > e || b > idx || e < idx ) return;               // this condition is damn important
    if (b == e) //at leaf node
    {
        SumTree[node] = val;
        return;
    }
    update(node*2, b, (b+e)/2, SumTree, idx, val);
    update(node*2 + 1, (b+e)/2 + 1, e, SumTree, idx, val);

    SumTree[node] = SumTree[2*node] + SumTree[2*node + 1];
}

// goku = range begin
// naruto - range end
long long findRangeSum(int node, int b, int e, long long SumTree[], int goku, int naruto)
{
    if(goku <= b && naruto >= e)     // yeah... this condition is very confusing
    {
        return SumTree[node];
    }
    if(b > naruto || e < goku)      // means you are in the wrong neighbourhood buddy
    {
        return 0;
    }
    return findRangeSum(2*node, b, (b+e)/2, SumTree, goku, naruto) + findRangeSum(2*node + 1, (b+e)/2 + 1, e, SumTree, goku, naruto);
}

int main()
{
    int n,m,i,j;
    n = fast_int();
    m = fast_int();
    int a[n+1];
    for(i=0;i<n;i++)
    {
        a[i] = fast_int();
    }
    long long sumTree[262143 + 1000] = {0};
    createTree(1,0,n-1,sumTree,a);
    long long pairs[m];
    int l[m+1];
    int r[m+1];
    for(i=0;i<m;i++)
    {
        l[i] = fast_int();
        r[i] = fast_int();
        pairs[i] = findRangeSum(1,0,n-1,sumTree,l[i]-1,r[i]-1);
    }
    int k;
    int count;
    int change = 0;

    k = fast_int();
    while(k--)
    {
        int x,y;
        count = 0;
        x = fast_int();
        y = x + change;
        for(j=0;j<m;j++)
        {
            if(y>=l[j] && y<=r[j])
            {
                pairs[j]--;
            }
            if(pairs[j] == 0)
            {
                count++;
            }
        }
        change = count;
        printf("%d\n",count);
    }
    return 0;
}
