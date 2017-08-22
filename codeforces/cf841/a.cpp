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
    int n, k;
    scanf(" %d %d", &n, &k);
    char s[111];
    scanf(" %s", s);
    int f[26] = {0};
    for(int i=0; i<n; i++) {
        f[s[i]-'a']++;
    }

    bool upset = false;
    for(int i=0; i<26; i++) {
        if (f[i] > k) {
            upset = true;
        }
    }

    if(upset) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
