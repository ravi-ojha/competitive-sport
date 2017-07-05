#include<stdio.h>
struct chefList{
char chefName[11];
int nationCode;
int chefVote;
}chefs[10000];

struct nationList{
char nationName[11];
int nationVote;
}nations[10000];


int partition(struct chefList a[],int low, int high)
{
    struct chefList temp;
    int left = low;
    int right = high;
    //printf(" left = low = %d\n",left);
    //printf(" right = high = %d\n",right);
    int pivot = low;
    while (left < right)
    {
        while ((strcmp(a[left].chefName,a[pivot].chefName)<=0) && left <= high)
        {
            left++;
        }
        while ((strcmp(a[right].chefName,a[pivot].chefName)>=0) && right > low)
        {
            right--;
        }
        if (left < right)
        {
            temp = a[right];
            //strcpy(temp,a[right]);
            a[right] = a[left];
            //strcpy(a[right],a[left]);
            a[left] = temp;
            //strcpy(a[left],temp);
        }
    }
    temp = a[pivot];
    //strcpy(temp,a[pivot]);
    a[pivot] = a[right];
    //strcpy(a[pivot],a[right]);
    a[right] = temp;
    //strcpy(a[right],temp);
    return right;
}

void quicksort(struct chefList a[],int low,int high)
{
    if(low<high)
    {
        int pivot;

        pivot = partition(a,low,high);

        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}



main()
{

    char tempNation[11],votechef[11],chefOfTheYear[11],nationOfTheYear[11];
    int T, N, i, j=0,k,nationCount=0, maxChef=0,maxNation=0,high,low,ans;
    scanf(" %d",&T);
    //getchar();
    scanf(" %d",&N);
    //getchar();
    scanf(" %s",chefs[0].chefName);
    chefs[0].chefVote = 0;
    //gets(chefs[0].chefName);
    //puts(chefs[0].chefName);
    scanf(" %s",nations[0].nationName);
    //gets(nations[0].nationName);
    //puts(nations[0].nationName);
    nationCount++;
    chefs[0].nationCode = 0;
    nations[0].nationVote = 0;
    for(i=1; i<T; i++)
    {
        j = 0 ;
        scanf(" %s",chefs[i].chefName);
        //gets(chefs[i].chefName);
        //puts(chefs[i].chefName);
        scanf(" %s",tempNation);
        //gets(tempNation);
        //puts(tempNation);
        //printf("\nNation Count: %d\n",nationCount);
        while(j<nationCount)
        {
//            printf("\nChecking %s with %s\n",tempNation,nations[j].nationName);
            if (strcmp(tempNation,nations[j].nationName)==0)
            {
//                printf("\ncheck\n");
                chefs[i].nationCode = j;
                chefs[i].chefVote = 0;
                j = -1;
                break;
            }
            j++;
        }
        if (j != -1)
        {
            //printf("\ntempNation: %s\n",tempNation);
            strcpy(nations[nationCount].nationName,tempNation);
            //printf("nations.nationName[%d]: %s\n",k,nations[k].nationName);
            chefs[i].nationCode = nationCount;
            chefs[i].chefVote = 0;
            nations[i].nationVote = 0;
            nationCount++;
        }
    }
//    printf("\n\nReal Entries: \n");
//    for(i=0; i<T; i++)
//    {
//        printf(" %s AND NATION_CODES %d\n",chefs[i].chefName,chefs[i].nationCode);
//    }
    low = 0;
    high = T;
    quicksort(chefs,low,high-1);

//    printf("\n\nAfter sorting by chefName\n");
//    for(i=0; i<T; i++)
//    {
//        printf(" %s AND NATION_CODES %d\n",chefs[i].chefName,chefs[i].nationCode);
//    }

//    printf("\n\nNow Enter the VOTES\n");
    while(N--)
    {
        scanf(" %s",votechef);
        low = 0;
        high = T-1;
        ans = (high+low)/2;
        while (strcmp(chefs[ans].chefName,votechef) != 0)
        {
//            printf("ans: %d\n",ans);
//            printf("\ncomapring %s and %s \n",votechef,chefs[ans].chefName);
            if (strcmp(chefs[ans].chefName,votechef) < 0)
                {low = ans + 1;}
            else
                {high = ans - 1;}
            ans = (high+low)/2;
//            printf("\nFinding");
        }
//        printf("\n%s Successfully found at %d position",votechef,ans);
        chefs[ans].chefVote += 1;
//        if(chefs[ans].chefVote > maxChef)
//        {
//            maxChef = chefs[ans].chefVote;
//            strcpy(chefOfTheYear,chefs[ans].chefName);
//        }
        if(chefs[ans].chefVote >= maxChef)
        {
            if(chefs[ans].chefVote > maxChef)
            {
                maxChef = chefs[ans].chefVote;
                strcpy(chefOfTheYear,chefs[ans].chefName);
            }
            //if(nations[chefs[ans].nationCode].nationVote == maxNation)
            else
            {
                if (strcmp(chefOfTheYear,chefs[ans].chefName) > 0)
                {
                    strcpy(chefOfTheYear,chefs[ans].chefName);
                }
            }
        }
        nations[chefs[ans].nationCode].nationVote += 1;
        if(nations[chefs[ans].nationCode].nationVote >= maxNation)
        {
            if(nations[chefs[ans].nationCode].nationVote > maxNation)
            {
                maxNation = nations[chefs[ans].nationCode].nationVote;
                strcpy(nationOfTheYear,nations[chefs[ans].nationCode].nationName);
            }
            //if(nations[chefs[ans].nationCode].nationVote == maxNation)
            else
            {
                if (strcmp(nationOfTheYear,nations[chefs[ans].nationCode].nationName) > 0)
                {
                    strcpy(nationOfTheYear,nations[chefs[ans].nationCode].nationName);
                }
            }
        }

    }
    printf("%s\n",nationOfTheYear);
    printf("%s",chefOfTheYear);
//    for(i=0; i<T; i++)
//    {
//        printf("\nChef %s got %d votes",chefs[i].chefName,chefs[i].chefVote);
//    }
//    for(i=0; i<nationCount; i++)
//    {
//        printf("\nNation %s got %d votes",nations[i].nationName,nations[i].nationVote);
//    }

//    printf("\n\n+++------Chef of the Year------+++\n\n       %s\n",chefOfTheYear);
//    printf("\n\n+++------Nation of the Year------+++\n\n       %s\n",nationOfTheYear);

//    printf("\n\nReal Entries: \n");
//    for(i=0; i<T; i++)
//    {
//        printf(" %s AND NATION_CODES %d\n",chefs[i].chefName,chefs[i].nationCode);
//    }
//    low = 0;
//    high = T;
//    quicksort(chefs,low,high-1);
//
//    printf("\n\nAfter sorting by chefName\n");
//    for(i=0; i<T; i++)
//    {
//        printf(" %s AND NATION_CODES %d\n",chefs[i].chefName,chefs[i].nationCode);
//    }
//    printf("\n\nNations Now:\n");
//    for(i=0; i<nationCount; i++)
//    {
//        printf(" %s\n",nations[i].nationName);
//    }

    return 0;
}
