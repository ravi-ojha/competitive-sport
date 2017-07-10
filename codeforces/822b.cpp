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
    int n, m;
    string s, t;
    scanf(" %d %d",&n, &m);
    cin >> s;
    cin >> t;
    vector<int> vres;
    int res = 10000000;
    for(int i=0; i<=(m-n); i++) {
        int cnt = 0;
        vector<int> vtmp;
        for(int j=0; j<n; j++) {
            if(s[j] != t[i+j]) {
                cnt++;
                vtmp.push_back(j+1);
            }
        }
        if(cnt < res) {
            res = cnt;
            vres = vtmp;
        }
    }
    printf("%d\n", res);
    int vlen = vres.size();
    for(int i=0; i<vlen; i++) {
        printf("%d ", vres[i]);
    }
    return 0;
}
