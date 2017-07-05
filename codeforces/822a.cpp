#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;

long long gcd(long long a, long long b) {
    long long temp;
    while(b > 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long factorial(long long a) {
    long long res = 1;
    for(long long i=1; i<=a; i++) {
        res = res*i;
    }

    CONSOLE(res);
    return res;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long c, d;
    c = min(a, b);

    long long c_fact = factorial(c);

    cout << c_fact << endl;

    return 0;
}
