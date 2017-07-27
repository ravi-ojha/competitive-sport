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
    int n, m;
    int x;
    int res[111];
    for(int i=0; i<111; i++) {
        res[i] = INF_32;
    }
    scanf(" %d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf(" %d",&x);
            res[i] = min(x, res[i]);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, res[i]);
    }
    printf("%d\n", ans);
    return 0;
}
