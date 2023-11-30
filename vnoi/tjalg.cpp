#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

vector<int> adj[maxN + 5];
stack<int> s;
int n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
    }
}

int num[maxN + 5], low[maxN + 5];
int vst[maxN + 5];
int Time = 0, res = 0;

void dfs(int u) {
    num[u] = low[u] = ++Time;
    s.push(u);
    for(int v : adj[u]) {
        if(vst[v]) continue;
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if(low[u] == num[u]) {
        ++res;
        while(!s.empty()) {
            int v = s.top();
            vst[v] = true;
            s.pop();
            if(v == u) break;
        }
    }
}

void sol() {
    for(int i = 1; i <= n; ++i)
        if(!num[i]) dfs(i);
    cout << res;
}

int main() {

    read();
    sol();

    return 0;
}
