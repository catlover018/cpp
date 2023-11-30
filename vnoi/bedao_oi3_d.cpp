#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define SZ(X) (int)(X.size())
#define pb push_back
#define mp make_pair

using namespace std;

const int maxN = 1e6;
const int inf = 1e18;

typedef pair<int, int> pii;

int N, M, K;
vector<pii> adj[maxN+5];
int mark[maxN+5], d[maxN+5], r[maxN+5], res[maxN+5];
vector<int> g;

void read_input()
{
  cin >> N >> M >> K;
  FOR(i, 1, M)
  {
    int u, v, w;  cin >> u >> v >> w;
    adj[u].pb(mp(v, w));
    adj[v].pb(mp(u, w));
  }
  FOR(i, 1, N)
  {
    d[i] = inf;
    mark[i] = -1;
  }
  FOR(i, 1, K)
  {
    int u, x;  cin >> u >> mark[u];
    if(mark[u] == 1) g.pb(u);
  }
}

void dijkstra()
{
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  FOR(i, 1, N)
  {
    d[i] = inf;
    if(mark[i] > -1)
    {
      Q.push(mp(0, i));
      d[i] = 0;
    }
  }
  while(!Q.empty())
  {
    pii top = Q.top();  Q.pop();
    int u = top.se, len = top.fi;
    if(d[u] != len) continue;
    for(pii e : adj[u])
    {
      int v = e.fi, w = e.se;
      if(d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
        Q.push(mp(d[v], v));
      }
    }
  }
}

void solve()
{
  dijkstra();
  FOR(i, 1, N) res[i] = d[i];
  FOR(i, 1, N)
  {
    if(mark[i] == 1)
    {
      mark[i] = -1;
      dijkstra();
      res[i] = d[i];
      mark[i] = 1;
    }
  }
  FOR(i, 1, N) cout << res[i] << ' ';
}

int32_t main()
{
  file("milktea");

  read_input();
  solve();

  return 0;
}
