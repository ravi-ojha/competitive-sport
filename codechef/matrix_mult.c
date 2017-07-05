#include<stdio.h>
//#include<conio.h>
main()
{
    int iA,jA,iB,jB,k,l,sizeA,sizeB,sizeC,temp=0,tAns=0;
    begin:
    printf("Enter the size of matrix A: ");
    scanf(" %d %d",&iA,&jA);
    printf("Enter the size of matrix B: ");
    scanf(" %d %d",&iB,&jB);
    if(jA != iB)
    {
        printf("Invalid sizes\nPlease Enter valid sizes now\n");
        goto begin;
    }
    else
    {
        int matrixA[iA][jA],matrixB[iB][jB],answer[iA][jB];
        printf("\nEnter the elements of matrix A: ");
        for(k=0;k<iA;k++)
        {
            for(l=0;l<jA;l++)
            {
                scanf(" %d",&matrixA[k][l]);
            }
        }
        printf("\nmatrixA is\n\n");
        for(k=0;k<iA;k++)
        {
            for(l=0;l<jA;l++)
            {
                printf(" %5d",matrixA[k][l]);
            }
            printf("\n");
        }
        printf("\nEnter the elements of matrix B: ");
        for(k=0;k<iB;k++)
        {
            for(l=0;l<jB;l++)
            {
                scanf(" %d",&matrixB[k][l]);
            }
        }
        printf("\nmatrixB is\n\n");
        for(k=0;k<iB;k++)
        {
            for(l=0;l<jB;l++)
            {
                printf(" %5d",matrixB[k][l]);
            }
            printf("\n");
        }
        int p;
        int z = 0;
        int y = 0;
        for(k=0,y=0,z=0;k<iA;k++,z++,y++)
        {
            for(p=0;p<jB;p++)
            {
                tAns = 0;
                for(l=0;l<jA;l++)
                {
                    temp = matrixA[k][l]*matrixB[l][p];
                    tAns = tAns+temp;
                }
                answer[k][p] = tAns;
            }
            z++;
            y++;
        }
        printf("\n+-----Multiplication of above matrices is-----+\n\n");
        for(k=0;k<iA;k++)
        {
            for(l=0;l<jB;l++)
            {
                printf(" %5d",answer[k][l]);
            }
            printf("\n");
        }
    }
    //getch();
}
