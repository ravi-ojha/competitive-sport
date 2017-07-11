#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;
#define MAXL 5000000

char res[MAXL] = {};
int main() {
    vector< pair<int, int> > v;
    int n;
    for(int i=0; i<MAXL; i++) {
        res[i] = '?';
    }
    scanf(" %d",&n);
    //printf("%s\n", res);
    int mn = MAXL;
    int mx = 1;
    v.push_back(make_pair(1, MAXL));
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        int slen = s.size();
        int k;
        scanf(" %d",&k);
        for(int j=0; j<k; j++) {
            int x;
            scanf(" %d", &x);


        }
    }
    return 0;
}
