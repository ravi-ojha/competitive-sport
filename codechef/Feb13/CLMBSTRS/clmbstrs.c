#include<stdio.h>

int rec(int a,int steps,int sum)
{
    int i,b;
    for(i=2;i<=(a-steps);i++)
    {
        b = a-i;
        int vice_step = steps-1;
        while(vice_step != 2)
        {
            b = b-2;
            vice_step--;
        }
        sum = sum + double_two(b-2);
    }
    return sum;
}

int double_two(int a)
{
    return a*(a+1)/2;
}


int findOnes(int i)
{
      int count = 0;
      int j=1,m=1,k=0;
      while (i >= j)       // value of j is extended upto the 8,16,32,64 etc acc. to requirement
      {
            j = j << 1;
            m++;
      }
      while(k<m)
      {
              if ((j&i)>0)
                       count++;
              j = j >> 1;
              k++;
      }
      return count;
}


main()
{
    int T;
    scanf(" %d",&T);
    while(T--)
    {
        int j,g,N,G,steps,final=1;
        scanf(" %d %d",&N,&G);
        steps = N/2;
        N = N-1;
        if(steps == 0)
        {
            final = 1;
        }
        else if(steps == 1)
        {
            final = N;
        }
        else if(steps == 2)
        {
            final = 1+N+double_two(N-2);
        }
        else
        {
            final = 1+N+double_two(N-2);
            //printf("\nfinal upto step 2: %d\n",final);
            for(j=3;j<=steps;j++)
            final = final + rec(N,j,0);
        }
        final = final%(1000000007);
        g = findOnes(final);
        //printf("\ng = %d",g);
        if(g == G)
        {
            printf("CORRECT\n");
        }
        else
        {
            printf("INCORRECT\n");
        }
    }
    return 0;
}
