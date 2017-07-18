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
    string s;
    cin >> s;
    int m;
    scanf(" %d",&m);
    for(int i=0; i<m; i++) {
        int l, r, k;
        scanf(" %d %d %d", &l, &r, &k);
        string tmp;
        l--;
        r--;
        for(int j=l; j<=r; j++) {
            tmp.push_back(s[j]);
        }
        int jlen = tmp.size();
        int z = 0;
        k = k % jlen;
        for(int p=l; p<=r; p++) {
            s[p] = tmp[(z-k+jlen) % jlen];
            z++;
        }
        //cout << s << endl;
    }
    cout << s << endl;
    return 0;
}
