#include <bits/stdc++.h>
#define DEBUG true
using namespace std;


int main() {
    int n, m, k;
    scanf(" %d %d %d",&n, &m, &k);
    int a[110][110];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] = 0;
        }
    }
    int i = 1;
    int j = 1;
    int f = 0;
    while(k--) {
        a[i][j]++;
        j++;
        if(j > m) {
            j = 1;
            if(f == 0) {
                i++;
                if(i > n) {
                    i = n-1;
                    f = 1;
                }
                
            } else {
                i--;
                if(i <= 0) {
                    i = 2;
                    f = 0;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
