#include <bits/stdc++.h>
#define DEBUG true
using namespace std;


int main() {
    int n, m;
    scanf(" %d %d",&n, &m);
    int a[110][110];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] = 0;
        }
    }

    int pupils = (m*(n-1))
    int avg = k/pupils;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            a[i][j] = avg;
            k = k - avg;
        }
    }
    return 0;
}
