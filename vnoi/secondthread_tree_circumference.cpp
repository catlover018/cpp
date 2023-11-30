#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n;
vector<int> adj[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool vst[maxN + 5];
int d[maxN + 5];

void dfs(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}

void sol() {
    int st = 1; d[1] = 0;
    dfs(st, 0);
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        if(mx < d[i]) {
            mx = d[i];
            st = i;
        }
    }
    d[st] = 0;
    dfs(st, 0);
    cout << 3 * *max_element(d + 1, d + n + 1);
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
