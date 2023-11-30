#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int maxM = 100;
const int MOD = 1e9+7;

int a[maxN+5], n, m;

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

int dp[maxN+5][maxM+5];

void sol() {
  if(a[1] == 0) {
    for(int i = 1; i <= m; ++i) dp[1][i] = 1;
  } else {
    dp[1][a[1]] = 1;
  }
  a[n+1] = 0;
  for(int i = 2; i <= n+1; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i] == 0 || j == a[i]) {
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
        dp[i][j] %= MOD;
      }
    }
  }
  int ans = 0;
  if(a[n] == 0) {
    for(int i = 1; i <= m; ++i) {
      ans += dp[n][i];
      ans %= MOD;
    }
  } else ans = dp[n][a[n]];
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("AD.inp", "r", stdin);
  freopen("AD.out", "w", stdout);

  read();
  sol();

  return 0;
}
