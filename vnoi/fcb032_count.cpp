#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e5;

set<int> s[maxN + 5];
int n;
vector<int> adj[maxN + 5];
int col[maxN + 5], dp[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) cin >> col[i];
}

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            if(s[v].size() > s[u].size()) swap(s[u], s[v]);
            for(int x : s[v]) s[u].insert(x);
        }
    }
    s[u].insert(col[u]);
    dp[u] = s[u].size();
}

void sol() {
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) cout << dp[i] << " ";
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
