#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(X) (int)(X.size())
#define fi first
#define se second
#define pb push_back
#define cntbit(X) __builtin_popcountll(X);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 2e3;

ll pref[maxN+5][maxN+5];
int N, M, Q;

ll getSum(int x, int y, int u, int v)
{
  return pref[u][v] - pref[x - 1][v] - pref[u][y - 1] + pref[x - 1][y - 1];
}

ll getQuery(int x, int y, int u, int v)
{
  ll res = 1e18,
    full = getSum(x, y, u, v),
    half = full / 2;

  int l = x, r = u;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    int cur = getSum(x, y, mid, v);
    if(cur < half) l = mid + 1;
    else r = mid - 1;
  }
  res = min(abs(full - 2 * getSum(x, y, l, v)),
              abs(full - 2 * getSum(x, y, r, v)));


  l = y; r = v;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    int cur = getSum(x, y, u, mid);
    if(cur < half) l = mid + 1;
    else r = mid - 1;
  }
//  cout << l << endl;
  res = min({res, abs(full - 2 * getSum(x, y, u, l)),
                  abs(full - 2 * getSum(x, y, u, r))});

  return res;
}

void read_input()
{
  cin >> N >> M >> Q;
  FOR(i, 1, N)  FOR(j, 1, M)
  {
    cin >> pref[i][j];
    pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
  }
}

void solve()
{
  while(Q --> 0)
  {
    int x, y, u, v; cin >> x >> y >> u >> v;
    cout << getQuery(x, y, u, v) << '\n';
  }
}

int32_t main()
{

  cin.tie(0)->sync_with_stdio(0);

  file("mincut");

  read_input();
  solve();

  return 0;
}

