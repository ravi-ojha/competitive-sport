#include<stdio.h>
int main()
{
char a[51][51];
int N,i,j,xBEG,xEND,count=0;
scanf(" %d",&N);
for(i=0;i<N;i++)
{
for(j=0;j<N;j++)
{
scanf(" %c",&a[i][j]);
}
}
for(j=0;j<N;j++)
{
for(i=0;i<N;i++)
{
if(a[i][j] == 'B')
{
xBEG = i;
while(a[i][j] == 'B')
{
i++;
}
xEND = i-1;
// printf("\n%d %d %d %d B",xBEG,j,xEND,j);
count++;
}
}
}
printf("%d\n",count);
for(j=0;j<N;j++)
{
for(i=0;i<N;i++)
{
if(a[i][j] == 'B')
{
xBEG = i;
while(a[i][j] == 'B')
{
i++;
}
xEND = i-1;
printf("%d %d %d %d B\n",xBEG,j,xEND,j);
//count++;
}
}
}
return 0;
}
