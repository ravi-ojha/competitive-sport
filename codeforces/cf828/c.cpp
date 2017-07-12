#include <bits/stdc++.h>

// Some constants that are frequently used
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

// Something to print to console and debug
#define DEBUG false
#define CONSOLE(x) if(DEBUG) {cout << '>' << #x << ':' << x << endl;}

using namespace std;
#define MAXL 25

char res[MAXL];
int nxt[MAXL];
int main() {
    int n;
    for(int i=0; i<MAXL; i++) {
        res[i] = '?';
        nxt[i] = i;
    }
    scanf(" %d",&n);
    //printf("%s\n", res);
    int mn = MAXL;
    int mx = 0;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        int slen = s.size();
        int k;
        scanf(" %d",&k);
        for(int j=0; j<k; j++) {
            int x;
            scanf(" %d", &x);
            x--;
            mn = min(mn, x);
            mx = max(mx, x+slen);

            int res_i = x;
            int s_i = 0;
            while(s_i < slen) {
                if(nxt[res_i] != res_i) {
                    // This means that we have to make a jump
                    // Which position to jump on is specified by nxt[res_i]

                    // It is imp that we update s_i before res_i
                    // Nahi to hum res_i ko loose kar baithenge
                    s_i = s_i + nxt[res_i] - res_i;
                    res_i = nxt[res_i];
                } else {
                    // Update nxt
                    nxt[res_i] = x+slen;

                    res[res_i] = s[s_i];
                    s_i += 1;
                    res_i += 1;
                }
            }
        }

        for(int z=0;z<MAXL;z++) {
            printf(" %c", res[z]);
        }
        printf("\n");
        for(int z=0;z<MAXL;z++) {
            printf("%2d", nxt[z]);
        }

    }

    for(int i=0; i<mx; i++) {
        if(res[i] != '?') {
            printf("%c", res[i]);
        } else {
            printf("a");
        }
    }
    return 0;
}
