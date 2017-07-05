#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int i,j;
    int isPrime[95] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
    /* To find Prime, but since its a small array I just initialized it */
//    isPrime[0] = 1;
//    isPrime[1] = 1;
//    for(i=2;i*i<52;i++)
//    {
//        if(isPrime[i] == 1)
//        continue;
//        for(j=i*2;j<52;j=j+i)
//        {
//            isPrime[j] = 1;
//        }
//    }
//    for(i=0;i<53;i++)
//    {
//        if (isPrime[i] == 0)
//        cout << i << ", ";
//    }
    /* End of To Find Prime*/
    int t;
    cin >> t;
    while(t--)
    {
        int k;
        int x,y,monster = 0;
        cin >> x >> y;
        char a[502][502];
        for(i=0;i<x;i++)
        {
            scanf(" %s",a[i]);
        }
        for(i=0;i<x;i++)
        {
            for(j=0;j<y;j++)
            {
                if(a[i][j] == '^')
                {
                    //printf("hello");
                    int pre[5] = {0};
                    for(k=i+1;k<x && a[k][j]=='^';k++)
                    {
                        pre[0]++;
                    }
                    //printf("pre[0] = %d\n",pre[0]);
                    for(k=i-1;k>=0 && a[k][j]=='^';k--)
                    {
                        pre[1]++;
                    }
                    //printf("pre[1] = %d\n",pre[1]);
                    for(k=j+1;k<y && a[i][k]=='^';k++)
                    {
                        pre[2]++;
                    }
                    //printf("pre[2] = %d\n",pre[2]);
                    for(k=j-1;k>=0 && a[i][k]=='^';k--)
                    {
                        pre[3]++;
                    }
                    //printf("pre[3] = %d\n",pre[3]);
                    int min = 1000000000;
                    for(k=0;k<4;k++)
                    {
                        if(pre[k]<min)
                        {
                            min = pre[k];
                        }
                    }
                    //printf("min = %d\n",min);
                    for(k=0;k<95;k++)
                    {
                        if(isPrime[k] <= min)
                        {
                            monster++;
                        }
                    }

                }
                cout << monster;

            }
            cout << endl;
        }
        cout << monster << endl;
    }
    return 0;
}
