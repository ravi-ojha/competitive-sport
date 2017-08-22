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
    int n;
    scanf(" %d",&n);
    long long a[1000111];
    long long suma = 0;
    for(int i=0; i<n; i++) {
        scanf(" %I64d", &a[i]);
        suma += a[i];
    }
    int fwin = 0;
    if(suma % 2 == 1) {
        fwin = 1;
    } else if(suma % 2 == 0) {
        int odd_idx = -1;
        for(int i=0; i<n; i++) {
            if(a[i] % 2 == 1) {
                odd_idx = i;
                break;
            }
        }
        if(odd_idx != -1) {
            fwin = 1;
        }
    }
    if(fwin) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
    return 0;
}
