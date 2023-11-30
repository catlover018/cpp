#include <bits/stdc++.h>

#define int long long

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxN = 1e3;

int a[maxN + 5][maxN + 5];
int n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
}

int d[maxN + 5][maxN + 5];

void sol() {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> Q;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            d[i][j] = 1e9;
    for(int i = 1; i <= n; ++i) {
        d[i][1] = a[i][1];  d[i][m] = a[i][m];
        Q.push({d[i][1], {i, 1}});
        Q.push({d[i][m], {i, m}});
    }
    for(int i = 2; i < m; ++i) {
        d[1][i] = a[1][i];  d[n][i] = a[n][i];
        Q.push({d[1][i], {1, i}});
        Q.push({d[n][i], {n, i}});
    }
    while(!Q.empty()) {
        auto top = Q.top(); Q.pop();
        int len = top.fi,
            x = top.se.fi,
            y = top.se.se;
        if(len != d[x][y]) continue;
        for(int i = 0; i < 4; ++i) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx > 0 && ny > 0 && nx <= n && ny <= m) {
                if(d[nx][ny] > max(d[x][y], a[nx][ny])) {
                    d[nx][ny] = max(d[x][y], a[nx][ny]);
                    Q.push({d[nx][ny], {nx, ny}});
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(d[i][j] > a[i][j])
            ans += d[i][j] - a[i][j];
        cout << ans;
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
