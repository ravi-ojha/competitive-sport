#include <stdio.h>
unsigned short partition(unsigned int *arr, unsigned short left, unsigned short right)
{
unsigned int pivot;
unsigned short i, j;
pivot = arr[left];
i = left;
j = left+1;
while(j <= right)
{
if(arr[j] <= pivot)
{
unsigned int temp;
i++;
temp = arr[j];
arr[j] = arr[i];
arr[i] = temp;
}
j++;
}
arr[left] = arr[i];
arr[i] = pivot;
return i;
}
void sort_array(unsigned int *arr, short start, short end)
{
if(start < end)
{
unsigned short pivot;
pivot = partition( arr, start, end);
sort_array( arr, start, pivot-1);
sort_array( arr, pivot+1, end);
}
}
int main()
{
unsigned short N;
unsigned int arr[2000];
scanf("%hu", &N);
while(N)
{
unsigned short i, j, k;
unsigned int side1, side2, side3, count = 0;
for(i = 0; i < N; i++)
scanf("%u", &arr[i]);
sort_array( arr, 0, N-1);
i = N-1;
while(i >= 2)
{
side3 = arr[i];
k = i-1;
j = 0;
while(j < k)
{
side1 = arr[j];
while(j < k)
{
side2 = arr[k];
if(side1+side2 < side3)
{
count += k-j;
break;
}
k--;
}
j++;
}
i--;
}
printf("%u\n", count);
scanf("%hu", &N);
}
return 0;
}
