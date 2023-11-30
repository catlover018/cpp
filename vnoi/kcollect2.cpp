#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e3;

int a[maxN * maxN + 5];
char c[maxN + 5][maxN + 5];
vector<int> adj[maxN * maxN + 5], tadj[maxN * maxN + 5];
int n, m;

int cal(int i, int j) {
    return (i - 1) * m + j;
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> c[i][j];
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
        if(c[i][j] == '#') continue;
        if(c[i][j] >= '0' && c[i][j] <= '9') a[cal(i, j)] = c[i][j] - '0';
        if(c[i][j] == 'W') {
            if(j != 1 && c[i][j - 1] != '#') {
                adj[cal(i, j)].push_back(cal(i, j - 1));
                tadj[cal(i, j - 1)].push_back(cal(i, j));
            }
        }
        if(c[i][j] == 'N') {
            if(i != 1 && c[i - 1][j] != '#') {
                adj[cal(i, j)].push_back(cal(i - 1, j));
                tadj[cal(i - 1, j)].push_back(cal(i, j));
            }
        }
        if(i < n && c[i + 1][j] != '#') {
            adj[cal(i, j)].push_back(cal(i + 1, j));
            tadj[cal(i + 1, j)].push_back(cal(i, j));
        }
        if(j < m && c[i][j + 1] != '#') {
            adj[cal(i, j)].push_back(cal(i, j + 1));
            tadj[cal(i, j + 1)].push_back(cal(i, j));
        }
    }
}

stack<int> topo;
int mark[maxN * maxN + 5];
int col[maxN * maxN + 5];

void dfs(int u) {
    mark[u] = true;
    for(int v : adj[u]) {
        if(!mark[v]) dfs(v);
    }
    topo.push(u);
}

void kosaraju(int u, int k) {
    col[u] = k;
    for(int v : tadj[u]) {
        if(!col[v]) kosaraju(v, k);
    }
}

vector<int> adj1[maxN * maxN + 5];
int cnt[maxN * maxN + 5], dp[maxN * maxN + 5];

void dfs2(int u) {
    mark[u] = 1;
    for(int v : adj1[u]) {
        if(!mark[v]) dfs2(v);
        dp[u] = max(dp[v], dp[u]);
    }
    dp[u] += cnt[u];
}

void sol() {
    for(int i = 1; i <= n * m; ++i)
        if(!mark[i]) dfs(i);
    int k = 0;
    while(!topo.empty()) {
        int u = topo.top(); topo.pop();
        if(!col[u]) {
            ++k;
            kosaraju(u, k);
        }
    }
    int ans = col[1];
    for(int i = 1; i <= n * m; ++i)
        cnt[col[i]] += a[i];
//    for(int i = 1; i <= k; ++i) cout << cnt[i] << " ";
    memset(mark, 0, sizeof(mark));
    for(int i = 1; i <= n * m; ++i) {
        for(int j : adj[i]) {
            if(col[i] != col[j]) adj1[col[i]].push_back(col[j]);
        }
//        cout << endl;
        }
    dfs2(ans);
//    for(int i = 1; i <= k; ++i) cout << dp[i] << " ";
    cout << *max_element(dp + 1, dp + k + 1);
}

int32_t main() {

    read();
    sol();

    return 0;
}
