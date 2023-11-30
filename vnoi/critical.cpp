#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;

int cnt[maxN], n, m;
vector<int> adj[maxN];

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int num[maxN], low[maxN], child[maxN], joint[maxN], cur_root[maxN], lt[maxN], id[maxN], par[maxN];
int Time = 0;
vector<int> d[maxN];

void dfs(int u, int p, int k) {
    num[u] = low[u] = ++Time;
    id[u] = k;  par[u] = p;
    lt[k]++;
    for(int v : adj[u]) {
        if(v != p) {
            if(!num[v]) {
                dfs(v, u, k);
                low[u] = min(low[u], low[v]);
                if(u == p) {
                    if(child[u] > 1) joint[u] = true;
                } else if(low[v] >= num[u]) joint[u] = true;
                child[u] += child[v];
            } else low[u] = min(low[u], num[v]);
        }
    }
    child[u] += 1;
}

void sol() {
    int k = 0;
    for(int i = 1; i <= n; ++i)
        if(!num[i]) {++k, dfs(i, 0, k);}
    for(int u = 1; u <= n; ++u)
        for(int v : adj[u]) {
            if(par[v] == u) d[u].push_back(child[v]);
            else d[u].push_back(lt[id[u]] - child[u]);
        }
    double ans = 0;
    for(int u = 1; u <= n; ++u)
    if(joint[u]) {
        long long cur_cnt = 0;
        for(int v : adj[u]) {
            if(par[v] == u && low[v] >= num[u]) {
                ans += child[v] * (lt[id[u]] - child[v] - 1) * 1.0;
                cur_cnt += child[v];
            }
        }
        ans += cur_cnt * (lt[id[u]] - cur_cnt - 1);
    }
    ans /= 2;
    cout << fixed << setprecision(8) << ans / n;
}

//6 5
//1 2
//1 3
//3 4
//3 5
//3 6

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
