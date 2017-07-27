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
    char a[1000111];
    char b[1000111];
    scanf(" %s", a);
    scanf(" %s", b);
    string c;
    string d;

    int alen = strlen(a);
    int blen = strlen(b);

    int i=0;
    while(a[i] == '0') {
        i++;
        continue;
    }
    while(i < alen) {
        c.push_back(a[i]);
        i++;
    }

    i=0;
    while(b[i] == '0') {
        i++;
        continue;
    }
    while(i < blen) {
        d.push_back(b[i]);
        i++;
    }


    char res = '=';
    if(c.size() > d.size()) {
        res = '>';
    } else if(c.size() < d.size()) {
        res = '<';
    } else {
        if(c == d) {
            res = '=';
        } else {
            i = 0;
            while(i < c.size() && c[i] == d[i]) {
                i++;
            }
            if(c[i] > d[i]) {
                res = '>';
            } else {
                res = '<';
            }
        }
    }
    printf("%c\n", res);

    return 0;
}
