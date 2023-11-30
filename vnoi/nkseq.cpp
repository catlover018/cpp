#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5], pref[maxN+5], n;
int dp[maxN+5];

void read() {
  cin >> n;
  dp[n+1] = 1e9;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i-1] + a[i];
    dp[n+1] = min(dp[n+1], pref[i]);
  }
}

void sol() {
    int ans = 0;
    if(pref[n] <= 0) cout << ans;
    else {
      if(dp[n+1]>0) ++ans;
      for(int i = n; i > 1; --i) {
        dp[i] = min(dp[i+1]+a[i], a[i]);
        if(dp[i] > 0) ++ans;
      }
      cout << ans;
    }
}

int32_t main() {

  read();
  sol();

  return 0;
}
