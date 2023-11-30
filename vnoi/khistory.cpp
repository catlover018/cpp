#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxN = 1e5 + 5;

int n, m;
vector<pii> adj[maxN];
int num[maxN], low[maxN];

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
}

int Time = 0, mark_vert[maxN], mark_edge[maxN];

#define fi first
#define se second

void dfs(int u, int par) {
    num[u] = low[u] = ++Time;
    for(pii e: adj[u]) {
        int v = e.fi, p = e.se;
        if(v == par) continue;
        if(!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
        if(low[v] > low[u]) mark_edge[p] = true;
    }
}

int col[maxN];

void dfs2(int u, int k) {
    mark_vert[u] = true;
    col[u] = k;
    for(pii e: adj[u]) {
        int v = e.fi, p = e.se;
        if(!mark_vert[v] && !mark_edge[p]) {
            dfs2(v, k);
        }
    }
}

vector<pii> n_edge;
vector<int> n_adj[maxN];
int cnt[maxN], deg[maxN];

void sol() {
    dfs(1, 0);  int k= 0;
    for(int i = 1; i <= n; ++i) if(!mark_vert[i]) {++k; dfs2(i, k);}
    for(int u = 1; u <= n; ++u)
        for(pii e : adj[u]) {
            int v = e.fi;
            if(col[v] != col[u]) {
                n_adj[col[u]].push_back(col[v]);
                n_adj[col[v]].push_back(col[u]);
            }
        }
    for(int i = 1; i <= n; ++i) ++cnt[col[i]];
}

//9 12
//1 2
//2 3
//3 1
//4 5
//5 6
//5 7
//7 8
//8 9
//7 9
//2 9
//6 4
//1 4

int main() {

    read();
    sol();

    return 0;
}
