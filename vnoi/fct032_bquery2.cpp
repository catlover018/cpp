#include <bits/stdc++.h>

using namespace std;

const int maxN = 4000;

int v[maxN + 5][maxN + 5], e1[maxN + 5][maxN + 5], e2[maxN + 5][maxN + 5], n, m, q;
char c[maxN + 5][maxN + 5];

void read() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> c[i][j]; c[i][j] -= '0';
        }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            int bonus1 = 0, bonus2 = 0;
            if(c[i][j] == 1) {
                if(c[i][j - 1]) {
                    bonus1 = 1;
                }
                if(c[i - 1][j]) {
                    bonus2 = 1;
                }
            }
            v[i][j] = v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1] + c[i][j];
            e1[i][j] = e1[i - 1][j] + e1[i][j - 1] - e1[i - 1][j - 1] + bonus1;
            e2[i][j] = e2[i - 1][j] + e2[i][j - 1] - e2[i - 1][j - 1] + bonus2;
        }
    }
}

void sol() {
    for(int i = 1; i <= q; ++i) {
        int u, _v, x, y; cin >> u >> _v >> x >> y;
        int V = v[x][y] - v[u - 1][y] - v[x][_v - 1] + v[u - 1][_v  - 1];
        int E1 = e1[x][y] - e1[u - 1][y] - e1[x][_v] + e1[u - 1][_v];
        int E2 = e2[x][y] - e2[x][_v - 1] - e2[u][y] + e2[u][_v - 1];
        cout << V - E1 - E2 << '\n';
    }
}

//4 5 1
//10101
//11101
//00011
//11100
//2 3 4 5

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
