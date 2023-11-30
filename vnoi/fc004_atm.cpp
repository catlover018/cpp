#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

vector<int> adj[maxN + 5], tadj[maxN + 5];
int n, m, st;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        tadj[v].push_back(u);
    }
}

int col[maxN + 5];
vector<int> DAG[maxN + 5];
stack<int> topo;
int vst[maxN + 5], n_DAG = 0;

void dfs(int u) {
    vst[u] = true;
    for(int v : adj[u])
        if(!vst[v]) dfs(v);
    topo.push(u);
}

void kosaraju(int u, int k) {
    col[u] = k;
    for(int v : tadj[u])
        if(!col[v]) kosaraju(v, k);
}

void build_DAG() {
    for(int i = 1; i <= n; ++i)
        if(!vst[i]) dfs(i);
    while(!topo.empty()) {
        int u = topo.top(); topo.pop();
        if(!col[u]) {
            ++n_DAG;
            kosaraju(u, n_DAG);
        }
    }
    for(int u = 1; u <= n; ++u)
        for(int v : adj[u])
            if(col[v] != col[u]) {
                DAG[col[u]].push_back(col[v]);
            }
}

int dp[2][maxN + 5];
int cnt[maxN + 5], mark[maxN + 5];

void bfs(int u) {
    memset(dp, -1, sizeof(dp));
    memset(vst, 0, sizeof(vst));
    queue<int> Q;
    Q.push(u);  vst[u] = true;
    dp[0][u] = cnt[u];
    if(mark[u] == true) dp[1][u] = cnt[u];
    while(!Q.empty()) {
        int u = Q.front();    Q.pop();
        for(int v : DAG[u]) {
//            if(vst[v]) continue;
            if(dp[0][v] < max(dp[0][u], dp[1][u]) + cnt[v]) {
                dp[0][v] = dp[0][u] + cnt[v];
                vst[v] = true;
                Q.push(v);
            }
            if(mark[v] == true) {
                if(dp[1][v] < max(dp[0][u], dp[1][u]) + cnt[v]) {
                    dp[1][v] = max(dp[0][u], dp[1][u]) + cnt[v];
                    vst[v] = true;
                    Q.push(v);
                }
            }
        }
    }
}

void sol() {
    build_DAG();
    for(int i = 1; i <= n; ++i) {
        int x;  cin >> x;
        cnt[col[i]] += x;
    }
    int n_bar;  cin >> st >> n_bar;
    for(int i = 1; i <= n_bar; ++i) {
        int bar;    cin >> bar;
        mark[col[bar]] = true;
    }
    bfs(col[st]);
    int ans = 0;
    for(int i = 1; i <= n_DAG; ++i)
        if(mark[i]) ans = max(ans, dp[1][i]);
    cout << ans;
}

int32_t main() {

    cin.tie()->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
