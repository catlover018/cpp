#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define pb push_back

using namespace std;

const int maxN = 1e6;

vector<int> adj[maxN+5];
int X, Y, N;
int ri[maxN+5], d[maxN+5];
int Time = 0;

void read_input()
{
  cin >> X >> Y >> N;
  FOR(i, 1, N)
  {
    int u, v; cin >> u >> v;
    v += X;
    adj[u].pb(v);
    adj[v].pb(u);
  }
}

int Match(int i)
{
  if(d[i] == Time) return false;
  d[i] = Time;
  for(int j : adj[i])
  {
    if(ri[j] == 0 || Match(ri[j]))
    {
      ri[j] = i;
      return true;
    }
  }
  return false;
}

void solve()
{
  int ans = 0;
  FOR(i, 1, X)
  {
    ++Time;
    ans += Match(i);
  }
  cout << ans;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("nkbm");

  read_input();
  solve();

  return 0;
}
