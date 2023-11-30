#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 17;

int dp[maxN+5][(1<<maxN)+5];
int a[maxN+5], n, k;

#define bit(n, i) ((n>>i)&1)

void read() {
  cin >> n >> k;
  for(int i = 0; i < n; ++i) cin >> a[i];
}

void sol() {
  for(int mask = 0; mask < (1 << n); ++mask) {
    for(int i = 0; i < n; ++i) {
    if(!bit(mask, i)) continue;
      if(__builtin_popcount(mask)==1) {
          if(bit(mask, i)) dp[i][mask] = 1;
          else dp[i][mask] = 0;
          continue;
      } else {
        int pre_mask = mask-(1<<i);
        for(int j = 0; j < n; ++j) {
          if(bit(pre_mask, j) && abs(a[i] - a[j]) > k) {
            dp[i][mask] += dp[j][pre_mask];
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; ++i) ans += dp[i][(1<<n)-1];
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
