#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define SZ(X) (int)(X.size())
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;

typedef pair<int, int> pii;

int N;
vector<pii> adj[maxN+5];
int d[maxN+5];
int ans = 0;

void read_input()
{
  cin >> N;
  FOR(i, 1, N - 1)
  {
    int u, v; char c;
    cin >> u >> v >> c;
    int w = c - 'a';
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w));
  }
}

void dfs1(int u, int p)
{
  vector<int> cnt(26);
  for(pii e : adj[u])
  {
    int v = e.fi, w = e.se;
    if(v == p) continue;
    ++cnt[w];
    dfs1(v, u);
    d[u] += d[v];
  }
  FOR(i, 0, 25)
    d[u] += cnt[i] * (cnt[i] - 1) / 2;
}

void dfs2(int u, int p, int pC)
{
  vector<int> cnt(26);
  for(pii e : adj[u])
  {
    int v = e.fi, w = e.se;
    if(v == p) continue;
    ++cnt[w];
  }
  if(p > 0)
  {
    d[u] -= cnt[pC] * (cnt[pC] - 1) / 2;
    ++cnt[pC];
    d[u] += cnt[pC] * (cnt[pC] - 1) / 2;
  }
  ans += (d[u] == 0);
  for(pii e : adj[u])
  {
    int v = e.fi, w = e.se;
    if(v == p) continue;
    int cur = d[u] - d[v] - cnt[w] * (cnt[w] - 1) / 2
            + (cnt[w] - 1) * (cnt[w] - 2) / 2;
    d[v] += cur;
    dfs2(v, u, w);
  }
}

void solve()
{
  ans = 0;
  dfs1(1, 0);
  dfs2(1, 0, 0);
  cout << ans;
}

int32_t main()
{
  file("trie");

  read_input();
  solve();

  return 0;
}
