#include <bits/stdc++.h>
#define DEBUG true
using namespace std;

int isprime[10000001] = {0};
void sieve() {
    int i = 2, j;
    isprime[0] = 1;
    isprime[1] = 1;
    for(i=2;i*i<=10000000;i++)
    {
        // if the number is marked, it is skipped
        if(isprime[i]==1) {
          continue;
        }
        for(j=i*2;j<=10000000;j+=i)
        {
            // Mark every multiple of i
            isprime[j]=1; 
        }
    }
}

int main() {
    sieve();
    for(int t=1;t<=1000;t++) {
        int n;
        //scanf(" %d",&n);
        n = t;
        int result = 1;
        for(int i=1; i<1001; i++) {
            int tmp = n*i + 1;
            if(isprime[tmp] == 1) {
                result = i;
                break;
            }
        }
        printf("%d\n", result);
        
    }
    return 0;
}
