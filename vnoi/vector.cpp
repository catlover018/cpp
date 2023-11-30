#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

const int maxN = 100;

int x[maxN+5], y[maxN+5];
int N, U, V, a, b;
map<pii, int> m1, m2;

void read_input()
{
  cin >> N;
  FOR(i, 1, N) cin >> x[i] >> y[i];
  cin >> U >> V;
}

void gen(map<pii, int> &m, int id, int lm)
{
  if(id == lm)
  {
    ++m[mp(a, b)];
    return;
  }
  FOR(i, 0, 1)
  {
    a += i * x[id]; b += i * y[id];
    gen(m, id + 1, lm);
    a -= i * x[id]; b -= i * y[id];
  }
}

void solve()
{
  gen(m1, 1, N/2 + 1);
  gen(m2, N/2 + 1, N + 1);
  int ans = 0;
  for(pair<pii, int> e : m1)
  {
    int x = U - e.fi.fi, y = V - e.fi.se;
    if(m2.count(mp(x, y)))
    {
      ans += e.se * m2[mp(x, y)];
    }
  }
  cout << ans;
}

int32_t main()
{
  file("vector");

  read_input();
  solve();

  return 0;
}
