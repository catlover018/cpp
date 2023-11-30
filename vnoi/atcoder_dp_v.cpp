#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(X) (int)(X.size())
#define pb push_back

using namespace std;

const int maxN = 1e6;

int N, M;
vector<int> adj[maxN+5];
int f[maxN+5], g[maxN+5], pref[maxN+5], suff[maxN+5];

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, N - 1)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
}

void dfs_f(int u, int p)
{
  f[u] = 1;
  for(int v : adj[u])
  {
    if(v == p) continue;
    dfs_f(v, u);
    f[u] *= f[v];
    f[u] %= M;
  }
  f[u] += 1;
  f[u] %= M;
}

void dfs_g(int u, int p)
{
  vector<int> x;
  for(int v : adj[u])
  {
    if(v == p) continue;
    x.pb(v);
  }
  int n = SZ(x);
  pref[0] = suff[n + 1] = 1;
  FOR(i, 1, n)
  {
    pref[i] = pref[i - 1] * f[x[i - 1]];
    pref[i] %= M;
  }
  FORD(i, n, 1)
  {
    suff[i] = suff[i + 1] * f[x[i - 1]];
    suff[i] %= M;
  }
  FOR(i, 0, n - 1)
  {
    int v = x[i];
    (g[v] = (g[u] * pref[i])) %= M;
    (g[v] = (g[v] * suff[i + 2])) %= M;
    (g[v] = (g[v] + 1)) %= M;
  }
  for(int v : x)
  {
    dfs_g(v, u);
  }
}

void solve()
{
  dfs_f(1, 1);
  g[1] = 1;
  dfs_g(1, 1);
  FOR(i, 1, N)
  {
    cout << ((f[i] - 1ll + M) * g[i]) % M << '\n';
  }
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("atcoder_dp_v");

  read_input();
  solve();

  return 0;
}
