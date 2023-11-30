#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define SZ(X) (int)(X.size())
#define all(X) X.begin(), X.end()
#define pb push_back

using namespace std;

typedef pair<int, int> pii;

const int maxN = 1e6;
const int inf = 1e9;

int N, M, s;
vector<int> adj[maxN+5];
int d[maxN+5], stable[maxN+5], g[maxN+5];

void read_input()
{
  cin >> N >> M >> s;
  FOR(i, 1, M)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
  FOR(i, 1, N)
  {
    d[i] = 0;
    g[i] = 0;
    stable[i] = false;
  }
}

void bfs()
{
  queue<int> Q;
  d[s] = 1; g[s] = s;
  stable[s] = false;
  Q.push(s);
  while(!Q.empty())
  {
    int u = Q.front(); Q.pop();
    for(int v : adj[u])
    {
      if(g[v] == u) continue;
      if(d[v] == 0)
      {
        d[v] = d[u] + 1;
        g[v] = u;
        stable[v] = stable[u];
        Q.push(v);
      }
      else if(d[v] == d[u] + 1) stable[v] = true;
    }
  }
}

void solve()
{
  bfs();
  int ans = 0;
  FOR(i, 1, N)
  {
    if(i == s) continue;
    ans += (stable[i] > 0);
  }
  cout << ans;
}

int main()
{
  file("stable");

  read_input();
  solve();

  return 0;
}
