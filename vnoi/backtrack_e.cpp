#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) FOR(i, 0, a - 1)
#define SZ(X) (int)(X.size())
#define all(X) X.begin(), X.end()
#define mp make_pair
#define fi first
#define se second
#define i128 __int128

using namespace std;

typedef pair<int, int> ii;

const int maxN = 100;
const int MOD = 1e9+7;

int N, M;
int a[maxN+5];
int ans = 0;

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, N) cin >> a[i], a[i] %= M;
}

void solve()
{
  read_input();
  int res = 0;
  FOR(i, 0, (int)(pow(3, N - 1)) - 1)
  {
    int x = i, s = 0, r = 1;
    FOR(j, 1, N)
    {
      r = r * a[j] % M;
      int b = x % 3;
      x /= 3;
      if(b == 0)
      {
        s = (s + r) % M;
        r = 1;
      }
      else if(b == 1)
      {
        s = (s + r) % M;
        r = M - 1;
      }
    }
      res += !s;
  }
  cout << res << '\n';
}

int32_t main()
{
  file("backtrack_e");

  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    solve();
  }

  return 0;
}
