#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN + 5], par[20][maxN+5], h[maxN+5];
int n, f[maxN+5];
vector<pair<int, int>> adj[maxN+5];
int c[maxN+5], d[maxN+5];
tuple<int, int, int> canh[maxN+5];

void read() {
  cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v >> c[i] >> d[i];
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
}

void dfs(int u, int p) {
  for(auto [v, id] : adj[u]) {
    if(v != p) {
      h[v] = h[u] + 1;
      par[0][v] = u;
      canh[v] = make_tuple(c[id], d[id], 0);
      for(int i = 1; i <= 18; ++i)
        par[i][v] = par[i-1][par[i-1][v]];
      dfs(v, u);
    }
  }
}

int lca(int u, int v) {
  if(h[u] < h[v]) swap(u, v);
  int k = h[u] - h[v];
  for(int i = 0; (1 << i) <= k; ++i)
    if((k>>i)&1) u = par[i][u];
  if(u == v) return u;
  for(int i = 18; i >= 0; --i) {
    if(par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}

int g[maxN+5], cnt[maxN+5];

int dfs2(int u, int p) {
  int cur = f[u];
  for(auto [v, id] : adj[u])
  if(v != p) {
    cur += dfs2(v, u);
  }
  auto [_c, _d, _used] = canh[u];
  canh[u] = make_tuple(_c, _d, cur);
  return cur;
}

void sol() {
  dfs(1, 0);
  for(int i = 1; i < n; ++i) {
    int p = lca(i, i+1);
    ++f[i];
    ++f[i+1];
    f[p]-=2;
  }
  dfs2(1, 0);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    auto [_c, _d, _cur] = canh[i];
//    cout << _cur << " ";
    ans += min(_cur*_c, _d);
  }
  cout << ans;
}

int32_t main() {

  read();
  sol();

  return 0;
}
