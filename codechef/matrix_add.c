#include<stdio.h>
//#include<conio.h>
main()
{
    int i,j,k,size;
    printf("Enter the size of matrix: ");
    scanf(" %d %d",&i,&j);
    size = i*j;
    int matrixA[size],matrixB[size],answer[size];
    printf("\nEnter the elements of matrix A: ");
    for(k=0;k<size;k++)
    {
        scanf(" %d",&matrixA[k]);
    }
    printf("\nEnter the elements of matrix B: ");
    for(k=0;k<size;k++)
    {
        scanf(" %d",&matrixB[k]);
    }
    for(k=0;k<size;k++)
    {
        answer[k] = matrixA[k]+matrixB[k];
    }
    printf("\n+-----Addition of above matrices is-----+\n\n");
    int n = 1;
    for(k=0;k<size;k++)
    {
        printf(" %4d",answer[k]);
        if((k+1) == j*n)
        {
            printf("\n");
            n++;
        }
    }
    //getch();
}
