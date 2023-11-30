#include <bits/stdc++.h>

#define int long long

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

const int maxN = 1e3;
const pii mv1[3] = {{1, 0}, {0, 1}, {1, 1}};
const pii mv2[3] = {{1, 0}, {0, -1}, {1, -1}};

int a[maxN + 5][maxN + 5];
int n, k;

void read() {
    cin >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int u, v;   cin >> u >> v;
        a[u][v] = 1;
    }
}

queue<pii> Q1, Q2;
int d1[maxN + 5][maxN + 5], d2[maxN + 5][maxN + 5];

void loang() {
    Q1.push({1, 1});    Q2.push({1, n});
    int res = 0;
    while(true) {
        ++res;
        queue<pii> cur = Q1;
        while(!cur.empty()) {
            auto [x, y] = cur.front(); cur.pop();
            Q1.pop();
            for(int i = 0; i < 3; ++i) {
                int nx = x + mv1[i].fi,
                    ny = y + mv1[i].se;
                if(nx > 0 && ny > 0 && nx <= n && ny <= n)
                    if(a[nx][ny] == 0 && d1[nx][ny] != res) {
                        Q1.push({nx, ny});
                        d1[nx][ny] = res;
                    }
            }
        }
        cur = Q2;
        while(!cur.empty()) {
            auto [x, y] = cur.front();    cur.pop();
            Q2.pop();
            for(int i = 0; i < 3; ++i) {
                int nx = x + mv2[i].fi,
                    ny = y + mv2[i].se;
                if(nx > 0 && ny > 0 && nx <= n && ny <= n) {
                    if(a[nx][ny] == 0 && d2[nx][ny] != res) {
                        Q2.push({nx, ny});
                        d2[nx][ny] = res;
                    }
                }
            }
        }
        cur = Q1;
        while(!cur.empty()) {
            auto [x, y] = cur.front();  cur.pop();
            if(d2[x][y] == res) {
                cout << res;
                return;
            }
        }
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    loang();

    return 0;
}
