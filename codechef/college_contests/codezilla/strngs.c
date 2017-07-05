#include<stdio.h>
#include<string.h>
int read()
{
    int _n = 0;
    char p = getchar_unlocked();
    for(;p<33;) { p = getchar_unlocked(); }
    while(p>32)
    {
        _n = (_n<<3) + (_n<<1) + (p-'0');
        p = getchar_unlocked();
    }
    return _n;
}
int main()
{
    int T,i,j;
    T = read();
    int lenA, lenB, sumA = 0, sumB = 0;
    char al[30];
    int power[150] = {0};
gets(al);
    for(i=0;i<26;i++)
    {
        power[al[i]] = i;
    }

    //puts(al);
    while(T--)
    {
        int usedA[150] = {0};
        int usedB[150] = {0};
        sumA = 0;
        sumB = 0;
        char a[110],b[110];
        gets(a);
        gets(b);
        //lenA = strlen(a);
        //lenB = strlen(b);
        for(i=0;a[i]!='\0';i++)
        {
                usedA[a[i]]++;
        }
//        for(j=0;j<200;j++)
//        {
//            printf("%d",usedA[j]);
//        }
        for(i=0;b[i]!='\0';i++)
        {
            if(usedA[b[i]] != 0)
            {
                usedA[b[i]]--;
            }
            else
            usedB[b[i]]++;
        }
        for(i=97;i<123;i++)
        {
            if(usedA[i] > 0)
            {
                sumA = sumA + power[i];
            }
            if(usedB[i] > 0)
            {
                sumB = sumB + power[i];
            }
        }
        //printf("sumA = %d sumB = %d\n",sumA,sumB);
        if(sumA==sumB)
        {
            puts("TIE");
        }
        else if(sumA>sumB)
        {
            puts("ALICE");
        }
        else
        {
            puts("BOB");
        }
        //puts(a);
        //puts(b);
    }
    return 0;
}
