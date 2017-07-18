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

char g[1010][1010];
int v[1010][1010];
int res[1010][1010];
int cnt = 0;
void dfs(int x, int y) {
    // If this cell is not passable then return
    if(g[x][y] == '*') {
        return;
    }
    // If this cell was visited then return
    if(v[x][y] == 1) {
        return;
    }
    v[x][y] = 1;
    if(g[x-1][y] == '*') {
        cnt++;
    }
    if(g[x+1][y] == '*') {
        cnt++;
    }
    if(g[x][y-1] == '*') {
        cnt++;
    }
    if(g[x][y+1] == '*') {
        cnt++;
    }
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
    return;
}


void update_res(int x, int y, int cnt) {
    // If this cell is not passable then return
    if(g[x][y] == '*') {
        return;
    }
    // If this cell was visited then return
    if(res[x][y] != -1) {
        return;
    }
    res[x][y] = cnt;
    update_res(x-1, y, cnt);
    update_res(x+1, y, cnt);
    update_res(x, y-1, cnt);
    update_res(x, y+1, cnt);
    return;
}

int main() {
    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    for(int i=0; i<1010; i++) {
        for(int j=0; j<1010; j++) {
            v[i][j] = 0;
            res[i][j] = -1;
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf(" %c", &g[i][j]);
        }
    }

    for(int z=0; z<k; z++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        if(res[x][y] == -1) {
            //printf("====");
            cnt = 0;
            dfs(x, y);
            update_res(x, y, cnt);
            printf("%d\n", res[x][y]);
        } else {
            printf("%d\n", res[x][y]);
        }
    }

    return 0;
}
