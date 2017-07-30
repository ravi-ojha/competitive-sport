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

int ones_in_op(int op[30]) {
    int res = 0;
    for(int i=0; i<26; i++) {
        if(op[i] != 0) {
            res++;
        }
    }
    return res;
}

int main() {
    int op[30] = {0};
    int fr[30] = {0};

    int n, k;
    scanf(" %d %d", &n, &k);
    char s[1000111];
    scanf(" %s", s);

    for(int i=0; i<n; i++) {
        fr[s[i] - 'A'] += 1;
    }

    if(DEBUG) {
        for(int i=0; i<30; i++) {
            cout << char(i+'A') << " ";
        }
        cout << endl;
        for(int i=0; i<30; i++) {
            cout << fr[i] << " ";
        }
        cout << endl;
    }

    int ans = 0; // 0 is NO
    for(int i=0; i<n; i++) {
        op[s[i]-'A'] = 1;
        int res = ones_in_op(op);
        if(res > k) {
            ans = 1;
            break;
        }
        fr[s[i]-'A']--;
        if(fr[s[i]-'A'] == 0) {
            op[s[i]-'A'] = 0;
        }
    }

    if(ans) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
