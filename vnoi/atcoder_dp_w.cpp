#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(X) (int)(X.size())
#define pb push_back

using namespace std;

const int maxN = 1e6;

struct Qs
{
  int l, r, w;
};

int dp[maxN+5];
Qs a[maxN+5];
int N, M;

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, M) cin >> a[i].l >> a[i].r >> a[i].w;
}

namespace trau
{
  bool inside(int x, int id)
  {
    int l = a[id].l, r = a[id].r;
    return (l <= x && x <= r);
  }

  void solve()
  {
    int ans = 0;
    FOR(i, 1, N)
    {
      int cur = 0;
      FOR(j, 1, M) if(inside(i, j)) cur += a[j].w;
      FOR(j, 0, i - 1)
      {
        FOR(k, 1, M)
        {
          if(inside(i, k) && !inside(j, k))
          {
            dp[i] = max(dp[i], dp[j] + cur);
          }
        }
      }
      ans = max(ans, dp[i]);
      cout << dp[i] << ' ';
    }
    cout << ans;
  }
}

void solve()
{
  trau::solve();
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("atcoder_dp_w");

  read_input();
  solve();

  return 0;
}
