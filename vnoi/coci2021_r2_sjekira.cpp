#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

#define pii pair<int, int>
#define fi first
#define se second

int n;
pair<int, int> a[maxN+5];
vector<int> adj[maxN+5];
int Rank[maxN+5];

int mx[maxN+5], par[maxN+5];
int ans = 0;

void init() {
  for(int i = 1; i <= n; ++i) {
    par[i] = i;
    mx[a[i].se] = a[i].fi;
  }
}

int Find(int u) {
  return (u == par[u] ? u : (par[u] = Find(par[u])));
}

int Union(int u, int v) {
  u = Find(u);  v = Find(v);
  if(u == v) return 0;
  par[v] = u;
  int cur = mx[u] + mx[v];
  mx[u] = max(mx[u], mx[v]);
  return cur;
}

bool cmp(int& x, int& y) {
  return (Rank[x] < Rank[y]);
}

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].fi;
    a[i].se = i;
  }
  sort(a + 1, a + n + 1);
  init();
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; ++i) {
    Rank[a[i].se] = i;
  }
  for(int i = 1; i <= n; ++i)
      sort(adj[i].begin(), adj[i].end(), cmp);

  int m = n - 1;
  while(m--) {
    int cost = 1e9;
    int u, v;
    for(int i = 1; i <= n; ++i) {
        for(int j : adj[i]) {
          if (Find(i) != Find(j)) {
            if (mx[i] + mx[j] < cost) {
              cost = mx[i] + mx[j];
              u = i; v = j;
              break;
            }
          }
        }
    }
    ans += Union(u, v);
  }
  cout << ans;
}

void dfs(int u, int parent) {
  for(int v : adj[u]) {
    if(v == parent) continue;
    dfs(v, u);
    ans += Union(u, v);
  }
}

void sol() {
  init();
//  for(int i = 1; i <= n; ++i) cout << a[i].fi << " " << a[i].se << endl;
  dfs(a[n].se, 0);
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
//  sol();

  return 0;
}
