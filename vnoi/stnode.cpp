#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(X) (int)(X.size())
#define all(X) X.begin(), X.end()
#define pb push_back

using namespace std;

const int maxN = 1e5;

int N, M, s, t;
vector<int> adj[maxN+5];
int trace[maxN+5], vst[maxN+5], id[maxN+5];
vector<int> path;

void read_input()
{
  cin >> N >> M >> s >> t;
  FOR(i, 1, M)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
  }
}

void find_path()
{
  queue<int> Q; Q.push(s);
  trace[s] = 0;
  while(!Q.empty())
  {
    int u = Q.front();  Q.pop();
    for(int v : adj[u])
    {
      if(trace[v] == -1)
      {
        Q.push(v);
        trace[v] = u;
      }
    }
  }
  int cur = t;
  while(cur)
  {
    path.pb(cur);
    cur = trace[cur];
  }
  reverse(all(path));
}

int bfs(int s)
{
  queue<int> Q; Q.push(s);
  int r = -1;
  vst[s] = true;
  while(!Q.empty())
  {
    int u = Q.front();  Q.pop();
    for(int v : adj[u])
    {
      if(!vst[v] && id[v] < 0)
      {
        vst[v] = true;
        Q.push(v);
      }
      else r = max(r, id[v]);
    }
  }
  return r;
}

void solve()
{
  FOR(i, 1, N)
  {
    trace[i] = -1;
    id[i] = -1;
  }
  find_path();
  FOR(i, 0, SZ(path) - 1)
  {
    id[path[i]] = i;
  }
  int ans = 0, r = -1;
  for(int x : path)
  {
    if(x != s && x != t && r <= id[x]) ++ans;
    r = max(r, bfs(x));
  }
  cout << ans;
}

int main()
{
  file("stnode");

  read_input();
  solve();

  return 0;
}
