#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;
const int inf = 1e18;

struct vertex {
    int _u, _mx, _mn, _dis;
    vertex() {_u = 0; _mx = 0; _mn = 0; _dis = 0;}
    vertex(int u, int mx, int mn, int dis) {
        _u = u; _mx = mx; _mn = mn; _dis = dis;
    }
    bool operator < (const vertex& o) const {
        return o._dis < _dis;
    }
};

int d[2][2][maxN + 5], n, m, s, x;
vector<pii> adj[maxN + 5];
priority_queue<vertex> Q; // {_u, _mx, _mn, deep, dis}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v,w ;    cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 0; i < 2; ++i)  for(int j = 0; j < 2; ++j)
        for(int u = 0; u <= n; ++u) d[i][j][u] = inf;
}

void dijkstra(int st) {
    d[0][0][st] = 0;
    Q.push(vertex(st, 0, 0, 0));
    while(!Q.empty()) {
        auto [u, mx, mn, len] = Q.top(); Q.pop();
        if(len > d[mx][mn][u]) continue;
//        cout << "     " << u << " " << len << " " << mx << " " << mn << endl;
        for(auto [v, w] : adj[u]) {
            for(int i = 0; i <= 1 - mx; ++i) for(int j = 0; j <= 1 - mn; ++j)
            if(d[mx | i][mn | j][v] > d[mx][mn][u] + (1 - i + j) * w ) {
                d[mx | i][mn | j][v] = d[mx][mn][u] + (1 - i + j) * w;
//                cout << "       " << v << " " << (mx | i) << " " << (mn | j) << endl;
                Q.push(vertex(v, (mx | i), (mn | j), d[mx | i][mn | i][v]));
            }
        }
    }
    for(int i = 1; i <= n; ++i) if(i != st) {
        cout << d[1][1][i] << ' ';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    read();
    dijkstra(1);

    return 0;
}
