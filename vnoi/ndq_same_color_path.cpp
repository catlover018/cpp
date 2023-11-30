#include <bits/stdc++.h>

#define int long long

#define bit(n, i) ((n>>i)&1)

using namespace std;

const int maxN = 1e6;

vector<int> col[maxN+5], adj[maxN+5];
set<int> s;
int n;

void read() {
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; ++i) {
    int x;  cin >> x;
    s.insert(x);
    col[x].push_back(i);
  }
}

int h[maxN+5], par[18][maxN+5];
void dfs(int u, int p) {
  for(int v : adj[u]) {
      if(v == p) continue;
      h[v] = h[u] + 1;
      par[0][v] = u;
      for(int i = 1; i < 18; ++i)
        par[i][v] = par[i-1][par[i-1][v]];
      dfs(v, u);
  }
}

int lca(int u, int v) {
  if(h[u] != h[v]) {
    if(h[u] < h[v]) swap(u, v);
    int k = h[u]-h[v];
    for(int i = 0; (1 << i) <= k; ++i)
      if(bit(k, i)) u = par[i][u];
  }
  if(u == v) return u;
  for(int i = 17; i >= 0; --i)
    if(par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  return par[0][u];
}

void sol() {
  dfs(1, 0);
  int ans = 0;
  for(int x : s) {
    int lm = col[x].size();
    for(int i = 0; i < lm; ++i) {
      for(int j = i + 1; j < lm; ++j) {
        int cha = lca(col[x][i], col[x][j]);
        ans += h[col[x][i]] + h[col[x][j]] - 2 * h[cha];
      }
    }
  }
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
