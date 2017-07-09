#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

int main() {
    int dp[200010] = {0};
    int n, k, q;
    scanf(" %d %d %d",&n, &k, &q);
    for(int i=1; i<=n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        dp[x] += 1;
        dp[y+1] -= 1;
    }

    // Update the array
    for(int i=1; i<200010; i++) {
        dp[i] = dp[i-1] + dp[i];
    }

    if(DEBUG) {
        for(int i=90; i<=100; i++) {
            printf("%d ", dp[i]);
        }
    }

    // Create dp to process queries in O(1)
    int dp2[200010] = {0};
    for(int i=1; i<200010; i++) {
        if(dp[i] >= k) {
            dp2[i] = 1;
        }
    }

    int dp3[200010] = {0};
    for(int i=1; i<200010; i++) {
        dp3[i] = dp3[i-1] + dp2[i];
    }

    // Now process queries
    while(q--) {
        int a, b;
        scanf(" %d %d",&a, &b);
        printf("%d\n", dp3[b] - dp3[a-1]);
    }

    return 0;
}
