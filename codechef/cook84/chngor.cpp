#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF_32 2147483647

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

int main() {
    int t;
    scanf(" %d",&t);
    while(t--) {
        int n;
        scanf(" %d",&n);
        int res = 0;
        int x;
        for(int i=0; i<n; i++) {
            scanf(" %d", &x);
            res = res | x;
        }
        printf("%d\n", res);
    }
    return 0;
}
