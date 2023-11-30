#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int a[maxN+5], n, m, q;
map<int, int> mp[maxN+5];
int par[maxN+5], sz[maxN+5], cnt[maxN+5];
int res[maxN+5];

void read() {
  cin >> n >> m >> q;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    par[i] = i;
    sz[i] = 1;
    cnt[a[i]]++;
    mp[i][a[i]] = 1;
  }
  for(int i = 1; i <= m; ++i)
    if(cnt[i] == 1) res[i] = -1;
}

int Find(int u) {
  return (u == par[u] ? u : (par[u] = Find(par[u])));
}

void sol() {
  for(int i = 1; i <= q; ++i) {
    int u, v; cin >> u >> v;
    u = Find(u);  v = Find(v);
    if(u != v) {
      if(sz[u] > sz[v]) swap(mp[u], mp[v]);
      sz[v] += sz[u];
      par[u] = v;
      for(auto [x, y] : mp[u]) {
        mp[v][x] += y;
        if(mp[v][x] == cnt[x] && res[x] == 0) {
          res[x] = i;
        }
      }
    }
  }
  for(int i = 1; i <= m; ++i) {
      if(res[i] == 0) res[i] = -1;
      else if(res[i] == -1) res[i] = 0;
      cout << res[i] << '\n';
  }
}

int main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
