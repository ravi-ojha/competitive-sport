
#include<stdio.h>

struct kilowhat{
int x;
int y;
int byte;
int toSort;
}cit[200];

int partition(struct kilowhat a[],int low, int high)
{
    struct kilowhat temp;
    int left = low;
    int right = high;
    int pivot = low;
    while (left < right)
    {
        while ((a[left].toSort <= a[pivot].toSort) && left <= high)
        {
            left++;
        }
        while ((a[right].toSort >= a[pivot].toSort) && right > low)
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

void quicksort(struct kilowhat a[],int low,int high)
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
    int i,j,k,p,q,z,iX=0,iY=0;
    int N;
    int maxX=0,minY=999,tempX,tempY,tempByte,low,high;
    scanf(" %d",&N);
    for(i=0;i<N;i++)
    {
        scanf(" %d %d %d",&cit[i].x,&cit[i].y,&cit[i].byte);
        cit[i].toSort = cit[i].x*1000 + cit[i].y;
        if(cit[i].y < minY)
        {
            minY = cit[i].y;
        }
    }
    low = 0;
    high = N;
    quicksort(cit,low,high-1);
    /*printf("\nAfter Final Sorting\n");
    for(i=0;i<N;i++)
    {
        printf(" %d %d %d %d\n",cit[i].x,cit[i].y,cit[i].byte,cit[i].toSort);
    }*/
    printf("%d\n",N+2);
    printf("%d %d\n",cit[0].x,minY-1);
    //printf("%d %d\n",cit[0].x,cit[0].y);
    for(i=0;cit[i].x==cit[0].x;i++)
    {
        printf("%d %d\n",cit[i].x,cit[i].y);
    }
    while(i<N)
    {
        if(cit[i].x == cit[N-1].x)
        {
            //printf("yaha kyu ni gaya tu...!!\n");
            p = i;
            while(i<N)
            {
                i++;
            }
            i--;
            while(i>=p)
            {
                printf("%d %d\n",cit[i].x,cit[i].y);
                i--;
            }
            //printf("%d %d\n",cit[i].x,cit[i].y);
            printf("%d %d",cit[i].x+1,minY-1);
            goto end;
            break;
        }
        else if (cit[i-1].x != cit[i].x && cit[i].x != cit[i+1].x && cit[i+1].x == cit[i+2].x)
        {
            i++;
            z = i;
            while(cit[i].x == cit[z].x)
            {
                i++;
            }
            i--;
            if((cit[i].y - cit[z-1].y) > (cit[z].y - cit[z-1].y))
            {
                //printf("Way to go..Naruto\n");
                p = i;
                i = z-1;
                while(i<=p)
                {
                    printf("%d %d\n",cit[i].x,cit[i].y);
                    i++;
                }
            }
            else
            {
                p = i;
                while(cit[i].x == cit[p].x)
                {
                    i++;
                }
                q = i;
                i--;
                while(i>=p)
                {
                    printf("%d %d\n",cit[i].x,cit[i].y);
                    i--;
                }
                i = q;
                while(cit[i].x == cit[q].x)
                {
                    printf("%d %d\n",cit[i].x,cit[i].y);
                    i++;
                }
            }
        }
        else if (cit[i].x != cit[i-1].x)
        {
            //printf("\nelse if me gaya kya???\n");
            p = i;
            while(cit[i].x == cit[p].x)
            {
                i++;
            }
            q = i;
            i--;
            while(i>=p)
            {
                printf("%d %d\n",cit[i].x,cit[i].y);
                i--;
            }
            i = q;
            while(cit[i].x == cit[q].x)
            {
                printf("%d %d\n",cit[i].x,cit[i].y);
                i++;
            }
        }
        else
        {
            //printf("\nO teri..\n");
            printf("%d %d\n",cit[i].x,cit[i].y);
            i++;
        }

    }
    printf("%d %d",cit[i-1].x+1,minY-1);
    end:
    ;
return 0;
}
