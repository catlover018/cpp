#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 20;

struct query {
  int x, y, c;
  query() {x = 0; y = 0; c = 0;}
  query(int _x, int _y, int _c) {
    x = _x;
    y = _y;
    c = _c;
  }
};

int f[(1 << maxN)], dp[maxN+5][(1 << maxN)];
int a[maxN+5];
int c[maxN+5][maxN+5];
int n, m, k;

void read() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
  for(int i = 1; i <= k; ++i) {
      int x, y, cost; cin >> x >> y >> cost;
    c[--x][--y] = cost;

  }
}

#define bit(n, i) ((n>>i)&1)

void sol() {
  for(int mask = 0; mask < (1 << n); ++mask)  {
    for(int i = 0; i <= n; ++i)
      if(bit(mask, i))
        f[mask] += a[i];
  }
  int ans = 0;
  for(int mask = 0; mask < (1 << n); ++mask) {
    for(int i = 0; i < n; ++i) {
      if(__builtin_popcount(mask) == 1) {
          dp[i][mask] = a[i];
      } else {
        if(bit(mask, i)) {
          int pre_mask = mask - (1<<i);
          for(int j = 0; j < n; ++j)
            if(bit(pre_mask, j)) dp[i][mask] = max(dp[i][mask], dp[j][pre_mask] + c[j][i] + a[i]);
        }
      }
      if(__builtin_popcount(mask) == m) {
          ans = max(ans, dp[i][mask]);
      }
    }
  }
  cout << ans;
}

int32_t main() {

  read();
  sol();

  return 0;
}
