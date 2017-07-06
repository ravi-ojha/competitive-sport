#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

int check(int i, int j, int n, int curr, int a[][51]) {
    for(int p=0;p<n;p++) {
        int s = a[i][p];
        for(int q=0;q<n;q++) {
            int t = a[q][j];
            if(s+t == curr) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    scanf(" %d",&n);
    int a[51][51];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf(" %d",&a[i][j]);
        }
    }

    int b[51][51];
    for(int i=0;i<51;i++) {
        for(int j=0;j<51;j++) {
            b[i][j] = 0;
        }
    }

    int count = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j] == 1) {
                b[i][j] = 1;
                continue;
            }
            int curr = a[i][j];
            b[i][j] = check(i, j, n, curr, a);
        }
    }

    int res = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(b[i][j] == 0) {
                res = 0;
            }
        }
    }

    if(res) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
