#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define se second
#define fi first

using namespace std;

typedef pair<int, int> pii;

const int maxN = 1e3;
const int inf = 1e9;

int N, M;
int st[maxN+5], e[maxN+5], d[maxN+5], c[maxN+5][maxN+5];
vector<pii> adj[maxN+5];

void read_input()
{
  cin >> N;
  FOR(i, 1, N) cin >> st[i];
  cin >> M;
  FOR(i, 1, M)
  {
    int u, v, _c, _t;
    cin >> u >> v >> _t >> _c;
    c[u][v] = c[v][u] = _c;
    adj[u].pb({v, _t});
    adj[v].pb({u, _t});
  }
}

int dijkstra(int W)
{
  FOR(i, 1, N) d[i] = inf, e[i] = 0;
  d[1] = 0;
  e[1] = W;
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  Q.push({d[1], 1});
  while(!Q.empty())
  {
    pii top = Q.top();   Q.pop();
    int u = top.se, len = top.fi;
    if(len > d[u]) continue;
    for(pii edge : adj[u])
    {
      int v = edge.fi, w = edge.se;
      if(d[v] > d[u] + w && e[u] >= c[u][v])
      {
        d[v] = d[u] + w;
        e[v] = (st[v] ? W : e[u] - c[u][v]);
        Q.push({d[v], v});
      }
      else if(d[v] == d[u] + w)
      {
        e[v] = max(e[v], e[u] - c[u][v]);
      }
    }
  }
  return d[N];
}

void solve()
{
  int base = dijkstra(inf);
  int ans = inf, l = 1, r = inf;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(dijkstra(mid) == base)
    {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("qbrobot");

  read_input();
  solve();

  return 0;
}
