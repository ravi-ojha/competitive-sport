#include<stdio.h>
int main()
{
    int N,M,K,i,j,n,I,J;
    scanf(" %d %d %d",&N,&M,&K);
    for(i=1;i<N;i=i+3)
    {
        for(j=1;j<N;j=j+3)
        {
            printf("S %d %d\n",i,j);
            fflush(stdout);
            char res;
            scanf(" %c",&res);
            if(res == 'M')
            {
                printf("N %d %d\n",i,j);
                fflush(stdout);
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
//                            flag++;
//                            if(flag == 1)
//                            {
//                                //printf("check1\n");
//                                break;
//                            }

                        }
                    }
//                    if(flag==1)
//                    {
//                        //printf("check2\n");
//                        break;
//                    }
            }
            }
            else if(res == '0')
            continue;
            else if(res == '1')
            {
                n = 1;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 1)
                            {
                                //printf("check1\n");
                                break;
                            }

                        }
                    }
                    if(flag==1)
                    {
                        //printf("check2\n");
                        break;
                    }
                }
            }

            else if(res == '2')
            {
                n = 2;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 2)
                            break;
                        }
                    }
                    if(flag==2)
                    break;
                }
            }

            else if(res == '3')
            {
                n = 3;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 3)
                            break;
                        }
                    }
                    if(flag==3)
                    break;
                }
            }

            else if(res == '4')
            {
                n = 4;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 4)
                            break;
                        }
                    }
                    if(flag==4)
                    break;
                }
            }

            else if(res == '5')
            {
                n = 5;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 5)
                            break;
                        }
                    }
                    if(flag==5)
                    break;
                }
            }

            else if(res == '6')
            {
                n = 6;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 6)
                            break;
                        }
                    }
                    if(flag==6)
                    break;
                }
            }

            else if(res == '7')
            {
                n = 7;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 7)
                            break;
                        }
                    }
                    if(flag==7)
                    break;
                }
            }

            else if(res == '8')
            {
                n = 8;
//                I=i-1;
//                J=j-1;
                for(I=i-1;I<i+2;I=I+1)
                {
                    int flag = 0;
                    for(J=j-1;J<j+2;J=J+1)
                    {
                        if(I==i && J==j)
                        continue;
                        if(I>=N || J>=N)
                        continue;
                        printf("S %d %d\n",I,J);
                        fflush(stdout);
                        scanf(" %c",&res);
                        if(res == 'M')
                        {
                            printf("N %d %d\n",I,J);
                            fflush(stdout);
                            flag++;
                            if(flag == 8)
                            break;
                        }
                    }
                    if(flag == 8)
                    break;
                }
            }


            //fflush(stdout);
        }
    }
    if(N%3 == 1)
    {
        i = N-1;
        for(j=0;j<N;j++)
        {
            printf("S %d %d\n",i,j);
            fflush(stdout);
            char res;
            scanf(" %c",&res);
            if(res == 'M')
            printf("N %d %d\n",i,j);
            fflush(stdout);
        }
        j = N-1;
        for(i=0;i<N-1;i++)
        {
            printf("S %d %d\n",i,j);
            fflush(stdout);
            char res;
            scanf(" %c",&res);
            if(res == 'M')
            printf("N %d %d\n",i,j);
            fflush(stdout);
        }
    }
    printf("Done\n");
    return 0;
}
