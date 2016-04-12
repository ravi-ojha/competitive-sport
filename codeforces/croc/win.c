#include<stdio.h>
int main()
{
    int n,m,i,fir=0,sec=0;
    scanf(" %d",&n);
    m = 2*n;
    char s1[2000001],s2[2000001];
    scanf(" %s",s1);
    scanf(" %s",s2);
    int both = 0,one=0,two=0,diff=0;
    for(i=0;i<m;i++)
    {
        if(s1[i] == '1' && s2[i] == '1')
        {
            both++;
            continue;
        }
        if(s1[i] == '1' && s2[i] == '0')
        {
            one++;
            continue;
        }
        if(s1[i] == '0' && s2[i] == '1')
        {
            two++;
            continue;
        }
    }
    diff = one-two;
    if(both&1)
    {
        sec = sec + (both/2);
        fir = fir + (both/2 + 1);
    }
    else
    {
        fir = fir + (both/2);
        sec = sec + (both/2);
    }
    if(diff==0)
    {
        fir = fir+one;
        sec = sec+two;
    }
    else if(diff>0)
    {
        sec = sec+two;
        fir = fir + diff/2;
    }
    else if(diff<0)
    {
        diff = -diff;
        fir = fir + one;
        sec = sec + diff/2;
    }
    //printf(" %d %d",fir,sec);
    if(fir == sec)
    {
        printf("Draw\n");
    }
    else if(fir > sec)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}
