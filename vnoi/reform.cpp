#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define SZ(X) (int)(X.size())

using namespace std;

const int maxN = 1e6;

vector<int> adj[maxN+5];
vector<int> tplt[maxN+5];
int vst[maxN+5];
int Time = 0;
int N, M;

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, M)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
}

void count_cpn(int u, int k)
{
  vst[u] = Time;
  tplt[k].pb(u);
  for(int v : adj[u])
  {
    if(vst[v] == Time) continue;
    count_cpn(v, k);
  }
}

namespace _1component
{
  int num[maxN+5], low[maxN+5];
  int timer = 0, res = 0, cnt = 0;
  int child[maxN+5];

  void dfs_sz(int u)
  {
    vst[u] = Time;
    for(int v : adj[u])
    {
      if(vst[v] == Time) continue;
      dfs_sz(v);
      child[u] += child[v];
    }
    ++child[u];
  }

  void dfs(int u, int p)
  {
    num[u] = low[u] = ++timer;
    for(int v : adj[u])
    {
      if(v == p) continue;
      if(num[v] == false)
      {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if(low[v] == num[v])
        {
          res += child[v] * (N - child[v]) - 1;
          ++cnt;
        }
      } else low[u] = min(low[u], num[v]);
    }
  }

  void calc()
  {
    ++Time;
    dfs_sz(1);
    dfs(1, 0);
    res += (M - cnt) * ((N - 1) * N / 2 - M);
    cout << res;
  }
}

namespace _2component
{
  int res = 0;
  int num[maxN+5], low[maxN+5];
  int timer = 0;

  void dfs(int u, int p)
  {
    num[u] = low[u] = ++timer;
    for(int v : adj[u])
    {
      if(v == p) continue;
      if(num[v] == false)
      {
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if(low[v] == num[v]) ++res;
      } else low[u] = min(low[u], num[v]);
    }
  }

  void calc()
  {
    FOR(i, 1, N)
      if(!num[i]) dfs(i, 0);
    res = (M - res) * SZ(tplt[1]) * SZ(tplt[2]);
    cout << res;
  }
}


void solve()
{
  read_input();

  // Count the number of components
  int cnt = 0;  ++Time;
  for(int i = 1; i <= N; ++i)
  {
    if(vst[i] != Time)
    {
      ++cnt;
      count_cpn(i, cnt);
    }
  }

  if(cnt > 2) cout << 0;
  else if(cnt == 1) _1component::calc();
  else _2component::calc();
}

int32_t main()
{
  file("reform");

  solve();

  return 0;
}
