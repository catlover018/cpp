#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define SZ(X) (int)(X.size())
#define fi first
#define se second
#define all(X) X.begin(), X.end()

using namespace std;

typedef pair<int, int> pii;

const int maxN = 100;

int N, M, X;
vector<pii> adj[maxN+5];
int a[maxN+5], ans = 0, cnt = 0;
vector<int> f[maxN+5];
int mark[maxN+5];

void read_input()
{
  cin >> N >> M >> X;
  FOR(i, 1, M)
  {
    int x, y, g;  cin >> x >> y >> g;
    mark[x] = mark[y] = true;
    if(x > y) swap(x, y);
    adj[y].pb({x, g});
    for(int j = g; j <= X; j += g)
    {
      f[x].pb(j);
      f[y].pb(j);
    }
  }
  FOR(i, 1, N)
  {
    cnt += !mark[i];
    if(SZ(f[i]) > 0) continue;
    FOR(j, 1, X) f[i].pb(j);
  }
  FOR(i, 1, N)
  {
    sort(all(f[i]));
    f[i].resize(unique(all(f[i])) - f[i].begin());
  }
}

void gen(int id)
{
  if(mark[id] == 0)
  {
    if(id == N) ++ans;
    else gen(id + 1);
    return;
  }
  for(int i : f[id])
  {
    a[id] = i;
    bool ok = true;
    for(pii e : adj[id])
    {
      int pre = e.fi, g = e.se;
      if(__gcd(a[id], a[pre]) != g)
      {
        ok = false;
        break;
      }
    }
    if(!ok) continue;
    if(id == N) ++ans;
    else gen(id + 1);
  }
}

void solve()
{
  ans = 0;
  cnt = pow(X, cnt);
  gen(1);
  cout << ans * cnt;
}

int32_t main()
{
  file("backtrack_f");

  read_input();
  solve();

  return 0;
}
