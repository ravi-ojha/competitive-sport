#include<stdio.h>
int partition(int a[],int low, int high)
{
int temp;
int left = low;
int right = high;
int pivot = low;
while (left < right)
{
while (a[left] <= a[pivot] && left < high)
{
left++;
}
while (a[right] >= a[pivot] && right > low)
{
right--;
}
if (left < right)
{
temp = a[right];
a[right] = a[left];
a[left] = temp;
}
}
temp = a[pivot];
a[pivot] = a[right];
a[right] = temp;
return right;
}

void quicksort(int a[],int low,int high)
{
if(low<high)
{
int pivot;

pivot = partition(a,low,high);

quicksort(a,low,pivot-1);
quicksort(a,pivot+1,high);
}
}

int main()
{
int T;
scanf(" %d",&T);
while(T--)
{
int N,M,K,star,i,j,k,p,low,high,sum=0,min;
scanf(" %d %d %d",&N,&M,&K);
//printf("\nN = %d M = %d K = %d\n",N,M,K);
char state[M];
int stars[50];
for(i=0;i<N;i++)
{
star = 0;
scanf(" %s",state);
//dot = 0;
for(j=0;j<M;j++)
{
// printf("state is %c\n",state[j]);
if(state[j] == '*')
star = star + 1;
// printf("star = %d\n",star);
}
// printf("\nstar = %d\n",star);
stars[i] = star;
//dots[i] = dot;
}
// printf("\nStars Array\n");
// for(i=0;i<N;i++)
// {
// printf(" %5d",stars[i]);
// }

low = 0;
high = N-1;
quicksort(stars,low,high);
// printf("\nSorted Stars Array\n");
// for(i=0;i<N;i++)
// {
// printf(" %5d",stars[i]);
// }
// printf("\n");
//min = stars[0];
for(k=0;k<K;k++)
{
stars[0] = M - stars[0];
low = 0;
high = N-1;
quicksort(stars,low,high);
}
// printf("\n\nFinal\n");
for(p=0;p<N;p++)
{
// printf("%5d",stars[p]);
sum = sum + stars[p];
}
printf("%d\n",sum);
}
return 0;
}
