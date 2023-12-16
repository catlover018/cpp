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
int mark[maxN+5], d[2][maxN+5], o[2][maxN+5], res[maxN+5];

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
    d[0][i] = d[1][i] = inf;
    mark[i] = -1;
  }
  FOR(i, 1, K)
  {
    int u;  cin >> u >> mark[u];
  }
}

void dijkstra()
{
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  FOR(i, 1, N)
  {
    d[0][i] = d[1][i] = inf;
    if(mark[i] > -1)
    {
      d[0][i] = 0;  o[0][i] = i;
      Q.push(mp(0, i));
    }
  }
  int type;
  while(!Q.empty())
  {
    pii top = Q.top();  Q.pop();
    int u = top.se, len = top.fi;

    if(u > N) type = 1, u -= N;
    else type = 0;

    if(d[type][u] != len) continue;

    int r = o[type][u];

    for(pii e : adj[u])
    {
      int v = e.fi, w = e.se;
      if(type == 0 && d[0][v] > len + w)
      {
        if(o[0][v] != r)
        {
          o[1][v] = o[0][v];
          d[1][v] = d[0][v];
          Q.push(mp(d[1][v], v + N));
        }
        o[0][v] = r;
        d[0][v] = len + w;
        Q.push(mp(d[0][v], v));
      }
      else if(d[1][v] > len + w && o[0][v] != r)
      {
        o[1][v] = r;
        d[1][v] = len + w;
        Q.push(mp(d[1][v], v + N));
      }
    }
  }
}

void solve()
{
  dijkstra();
  FOR(u, 1, N)
  {
    if(mark[u] == 1) cout << d[1][u] << ' ';
    else cout << d[0][u] << ' ';
  }
}

int32_t main()
{
  file("milktea");

  read_input();
  solve();

  return 0;
}
