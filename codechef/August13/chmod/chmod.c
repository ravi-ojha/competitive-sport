#include<stdio.h>

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
    int tree[262143] = {0};
    int n,i;
    scanf(" %d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf(" %d",&a[i]);
    }
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        int l, r, mod;
    }
}
