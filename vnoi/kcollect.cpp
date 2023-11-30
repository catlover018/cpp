#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1005;

#define pii pair<int, int>
#define fi first
#define se second

int n, m, a[maxN * maxN];
char c[maxN][maxN];
vector<int> adj[maxN * maxN], tadj[maxN * maxN];

int cal(int x, int y) {
    return (x - 1) * m + y;
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> c[i][j];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if(c[i][j] == '#') continue;
            if('0' <= c[i][j] && c[i][j] <= '9') a[cal(i, j)] = c[i][j] - '0';
            if(c[i][j] == 'W') {
                if(j != 1 && c[i][j - 1] != '#') {
                    adj[cal(i, j)].push_back(cal(i, j - 1));
                    tadj[cal(i, j - 1)].push_back(cal(i, j));
                }
            }
            if(c[i][j] == 'N' && c[i - 1][j] != '#') {
                if(i != 1) {
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
//    for(int i = 1; i <= n * m; ++i) { for(int v : adj[i]) cout << i << " " << v << "\n"; cout << endl; }
}

stack<int> topo;
int mark[maxN * maxN], col[maxN * maxN];

void dfs(int u) {   // topo
    mark[u] = true;
    for(int v : adj[u])
        if(!mark[v]) dfs(v);
    topo.push(u);
}

void kosaraju(int u, int k) { // tim tplt manh
    col[u] = k;
    for(int v : tadj[u])
        if(!col[v]) kosaraju(v, k);
}

int cnt[maxN * maxN], pos[maxN * maxN], dp[maxN * maxN];
vector<int> adj1[maxN * maxN];

void dfs2(int u) {
    mark[u] = 1;
    for(int v : adj1[u]) {
        if(mark[v] == 0) dfs2(v);
        dp[u] = max(dp[u], dp[v]);
//        if(u == 3) cout << v << " ";
    }
    dp[u] += cnt[u];
}

void sol() {
    for(int i = 1; i <= n * m; ++i)
    if(!mark[i]) dfs(i);
    int k = 0;
    while(!topo.empty()) {
        int top = topo.top();   topo.pop();
        if(!col[top]) {
            ++k;
            kosaraju(top, k);
        }
//        cout << top << " ";
    }
    int ans = col[1];
    for(int i = 1; i <= n * m; ++i) {
        cnt[col[i]] += a[i];
    }
    memset(mark, 0, sizeof(mark));
    for(int u = 1; u <= n * m; ++u) {
        for(int v : adj[u]) {
            if(col[u] != col[v]) adj1[col[u]].push_back(col[v]);
//            cout << v << " ";
        }
//        cout << endl;
    }
    dfs2(ans);
//    for(int i = 1; i <= n * m; ++i) cout << col[i] << " ";
    cout << *max_element(dp + 1, dp + k + 1);
}

//2 3
//5#7
//8W9


int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
