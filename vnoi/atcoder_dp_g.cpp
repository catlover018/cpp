#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

int n, m;
vector<int> adj[maxN + 5];

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
    }
}

int mark[maxN + 5], h[maxN + 5];
stack<int> topo;

int dfs(int u) {
    if(h[u]) return h[u];

    for(int v : adj[u]) {
        h[v] = dfs(v);
        h[u] = max(h[u], h[v] + 1);
    }

    return h[u];
}

void sol() {
    for(int i = 1; i <= n; ++i) if(!mark[i]) dfs(i);
    cout << *max_element(h + 1, h + n + 1);
//    for(int i = 1; i <= n; ++i) cout << h[i] << " ";
}

int main() {

    read();
    sol();

    return 0;
}
