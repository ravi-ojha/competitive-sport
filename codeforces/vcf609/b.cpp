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
    scanf(" %d %d", &n, &m);
    int books_by_genre[11] = {0};
    int x;
    for(int i=0; i<n; i++) {
        scanf(" %d", &x);
        x--;
        books_by_genre[x]++;
    }
    long long res = 0;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            res = res + books_by_genre[i]*books_by_genre[j];
        }
    }
    cout << res << endl;
    return 0;
}
