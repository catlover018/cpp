#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

vector<int> adj[maxN + 5];
int vst[11][maxN + 5], n, m;

struct query {
    int _u, _d, _c;
    query() {_u = 0; _d = 0; _c = 0;}
    query(int u, int d, int c) {
        _u = u;
        _d = d;
        _c = c;
    }
};

query q[maxN + 5];
int n_Query;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> n_Query;
    for(int i = 1; i <= n_Query; ++i) {
        int u, d, c;    cin >> u >> d >> c;
        q[i] = query(u, d, c);
    }
}

int color[maxN + 5];

void dfs(int u, int d, int c) {
    if(d < 0 || vst[d][u]) return;
    vst[d][u] = true;
    if(!color[u]) color[u] = c;
    for(int v : adj[u]) {
        dfs(v, d - 1, c);
    }
}

void sol() {
    for(int i = n_Query; i > 0; --i) {
        auto [u, d, c] = q[i];
        dfs(u, d, c);
    }
    for(int i = 1; i <= n; ++i) cout << color[i] << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}

