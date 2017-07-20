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
    int slen = s.size();
    int a[30] = {0};
    for(int i=0; i<slen; i++) {
        a[s[i] - 'a']++;
    }

    string pakka;
    for(int i=0; i<26; i++) {
        int upto = a[i]/2;
        for(int j=0; j<upto; j++) {
            pakka.push_back(i+'a');
        }
        a[i] = a[i] % 2;
    }

    string kacha;
    for(int i=0; i<26; i++) {
        if(a[i] == 1) {
            kacha.push_back(i+'a');
        }
    }

    int i=0;
    int j=kacha.size()-1;

    while(i < j) {
        kacha[j] = kacha[i];
        j--;
        i++;
    }

    for(int i=0; i<kacha.size()/2; i++) {
        pakka.push_back(kacha[i]);
    }

    sort(pakka.begin(), pakka.end());

    string res = pakka;
    if(kacha.size() % 2 == 1) {
        res.push_back(kacha[kacha.size()/2]);
    }

    for(int j=pakka.size()-1; j>=0; j--) {
        res.push_back(pakka[j]);
    }

    cout << res << endl;

    return 0;
}
