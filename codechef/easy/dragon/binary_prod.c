#include<stdio.h>

void decToBinary(int i)
{
    char a[100] = {0};
      int j=1,m=1,k=0;
      while (i >= j)       // value of j is extended upto the 8,16,32,64 etc acc. to requirement
      {
            j = j << 1;
            m++;
      }

      while(k<m)
      {
              if ((j&i)>0)
                       a[k] = '1';
              else
                       a[k] = '0';
              j = j >> 1;
              k++;
      }
//      printf("\narray= %s",a);
      for (k = 1; k<m; k++)
      {
         printf("%c",a[k]);
      }
      printf("\n");
}

main()
{
    int i;
    for(i=0;i<65;i++)
    {
        printf("%d = ",i);
        decToBinary(i);
    }
}
