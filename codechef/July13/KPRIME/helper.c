#include<stdio.h>
int main()
{
    int i,j;
    FILE *f;
    f = fopen("http://oeis.org/A001221/b001221.txt","rt");
    for(i=0;i<100000;i++)
    {
        scanf(" %d %d",&i,&j);
        printf("%d",j);
    }
    fclose(f);
    return 0;
}
