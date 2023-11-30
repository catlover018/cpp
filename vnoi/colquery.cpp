#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int c[maxN+5], n, q;

void read() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
}

map<int, int> mp[maxN+5];
int par[maxN+5];
int sz[maxN+5];

void init() {
    for(int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
        mp[i][c[i]] = 1;
    }
}

int Find(int u) {
    return (u == par[u] ? u : (par[u] = Find(par[u])));
}

void Union(int u, int v) {
    u = Find(u);    v = Find(v);
    if(u == v) return;
    if(sz[u] > sz[v]) swap(u, v);
    par[u] = v;
    sz[v] += sz[u];
    for(auto [col, cnt] : mp[u]) mp[v][col] += cnt;
}

void sol() {
    init();
    while(q--) {
        int type, u, v; cin >> type >> u >> v;
        if(type == 1) {
            Union(u, v);
        } else {
            u = Find(u);
            cout << mp[u][v] << '\n';
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio();

    read();
    sol();

    return 0;
}
