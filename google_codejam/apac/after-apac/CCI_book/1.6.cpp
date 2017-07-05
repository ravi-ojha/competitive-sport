#include <bits/stdc++.h>
using namespace std;

void rotate_matrix_by_90(int **matrix, int n)
{
	for(int i=0;i<n/2;i++)
	{
		for(int j=i;j<n-1-i;j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[n-1-j][i];
			matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
			matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
			matrix[j][n-1-i] = temp;
		}
	}
}
void print_matrix(int **matrix, int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int **a;
	a = new int *[4];
	for(int i=0;i<4;i++)
	{
		a[i] = new int[4];
	}
	int c = 1;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			a[i][j] = c;
			c++;
		}
	}
	print_matrix(a,4);
	rotate_matrix_by_90(a,4);
	print_matrix(a,4);
	
	int **b;
	b = new int *[3];
	for(int i=0;i<3;i++)
	{
		b[i] = new int[3];
	}
	c = 1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			b[i][j] = c;
			c++;
		}
	}
	print_matrix(b,3);
	rotate_matrix_by_90(b,3);
	print_matrix(b,3);
	return 0;
}
