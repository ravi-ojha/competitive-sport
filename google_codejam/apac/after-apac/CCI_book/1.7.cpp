#include <bits/stdc++.h>
using namespace std;

void make_rows_cols_zero(int ** matrix, int n, int m)
{
	int zero_rows[n];
	int zero_cols[m];
	memset(zero_rows,0,sizeof(zero_rows));
	memset(zero_cols,0,sizeof(zero_cols));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j] == 0)
			{
				zero_rows[i] = 1;
				zero_cols[j] = 1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(zero_rows[i] == 1)
		{
			for(int j=0;j<m;j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(zero_cols[i] == 1)
		{
			for(int j=0;j<n;j++)
			{
				matrix[j][i] = 0;
			}
		}
	}
}

void print_matrix(int ** matrix, int n, int m)
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%3d",matrix[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int ** matrix;
	matrix = new int *[4];
	for(int i=0;i<4;i++)
	{
		matrix[i] = new int[6];
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<6;j++)
		{
			matrix[i][j] = rand()%5;
		}
	}
	print_matrix(matrix,4,6);
	make_rows_cols_zero(matrix,4,6);
	print_matrix(matrix,4,6);
	return 0;
}
