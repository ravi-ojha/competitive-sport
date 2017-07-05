#include<iostream>
using namespace std;
int main()
{
    int i,j;
    int isPrime[502] = {0};

    isPrime[0] = 1;
    isPrime[1] = 1;
    for(i=2;i*i<502;i++)
    {
        if(isPrime[i] == 1)
        continue;
        for(j=i*2;j<502;j=j+i)
        {
            isPrime[j] = 1;
        }
    }
    for(i=0;i<502;i++)
    {
        if (isPrime[i] == 0)
        cout << i << ", ";
    }
    /* End of To Find Prime*/
    return 0;
}
