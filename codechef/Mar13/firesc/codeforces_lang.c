#include<stdio.h>
int e[100][100]={0},el[100]={0},m,n;
int herded[100]={0};
void herder(int leader)
{
	if(herded[leader]==1)
		return;
	herded[leader]=1;
	int i=0;
//	printf("\nanother herder %d",i+1);
	while(i<n)
	{

			if(el[i]==el[leader])
			{
				i++;
				continue;
			}
			int k=0;
//			printf("analysing langs");
			while(k<m)
			{
				if(e[i][k]==1 && e[leader][k]==1)
				{

						el[i]=el[leader];
//						printf("\n%d is now %d",i+1,el[i]);
						herder(i);

				}
				k++;
			}

		i++;
	}
}
int main()
{

	scanf(" %d %d",&n,&m);
	int sumk=0;
	int i=0,j,k,lang;
	while(i<n)
	{
//		printf("\n%d",i);
		scanf(" %d",&k);
		sumk+=k;
		j=0;
		while(j<k)
		{
			scanf(" %d",&lang);
			e[i][lang-1]=1;
			j++;
		}
		i++;
	}
	i=0;
	while(i<n)
	{
		el[i]=i+1;
		i++;
	}
	i=0;
	while(i<n)
	{
		herder(i);
		i++;
	}

/*	while(i<n)
	{
		int j=0;
		while(j<m)
		{
			printf("%d ",e[i][j]);
		 	j++;
		}
		printf("\n");
		i++;
	}*/

/*	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			int q;
			for(q=0;q<m;q++)
			{
				if(e[i][q]==1 && e[j][q]==1)
				{
					if(el[j]!=j+1)
						el[i]=el[j];
					else
						el[j]=el[i];
				}
			}
		}
	}*/

/*	i=0;
	printf("\n");
	while(i<n)
		printf("%d ",el[i++]);*/
	i=0;
	int check[100]={0},nos=0;
	while(i<n)
	{
		if(check[el[i]-1]==0)
			nos++;
		check[el[i]-1]=1;
		i++;
	}
	if(sumk==0)
		printf("%d",n);
	else
	printf("%d",nos-1);
/*	i=0;
	int c2[100][100]={0};
	while(i<n)
	{
		j=0;
		while(j<m)
		{
			c2[el[i]][j]=e[i][j];
			j++;
		}
		i++;
	}
	i=0;
	int sums[100]={0};
	int max=-1;
	while(i<m)
	{
		j=0;

		while(j<n)
		{
			sums[i]+=c2[j][i];
			j++;
		}
		if(c2[j][i]>max)
			max=c2[j][i];
		i++;
	}
	printf("%d",nos-max-1);*/
	return 0;
}
