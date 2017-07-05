#include <bits/stdc++.h>
using namespace std;
#define N 4
struct heap_node
{
	int data; //min data
	int i; //i,j denote the position of that data in original matrix
	int j;
};

heap_node *min_heap = new heap_node[N];

void min_heapify(int i, int size)
{
	int smallest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	if(left < size && min_heap[left].data < min_heap[smallest].data)
	{
		smallest = left;
	}
	if(right < size && min_heap[right].data < min_heap[smallest].data)
	{
		smallest = right;
	}
	if(smallest != i)
	{
		heap_node temp = min_heap[smallest];
		min_heap[smallest] = min_heap[i];
		min_heap[i] = temp;
		min_heapify(smallest, size);
	}
}

void build_heap(int size)
{
	int i=(size-1)/2;
	while(i>=0)
	{
		min_heapify(i,size);
		i--;
	}
}

void solve(int matrix[N][N])
{
	for(int i=0;i<N;i++)
	{
		min_heap[i].data = matrix[i][0];
		min_heap[i].i = i;
		min_heap[i].j = 1;
	}
	build_heap(N);
	for(int z=0;z<N*N;z++)
	{
		heap_node root = min_heap[0];
		cout << root.data << " ";
		if(root.j < N)
		{
			root.data = matrix[root.i][root.j];
			root.j++;
		}
		else
		{
			root.data = INT_MAX; // replace by INT_MIN if building Max Heap
		}
		min_heap[0] = root; // a new element is added to heap
		min_heapify(0,N);     // since a new element is added, again min_heapify the heap
	}
}

int main()
{
	int mat[N][N] = { 
						{10, 20, 30, 40},
		                {15, 25, 35, 45},
		                {27, 29, 37, 48},
		                {32, 33, 39, 50},
                  	};
  	solve(mat);
	return 0;
}
