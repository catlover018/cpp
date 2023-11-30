#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int MOD = 1e9;

int a[maxN+5], pref[maxN+5];
int n, k;

void read() {
  cin >> n >> k;
}

int dp[maxN+5];

void sol() {
  dp[0] = pref[0] = 1;
  for(int i = 1; i <= n; ++i) {
    dp[i] = 2*dp[i-1];  dp[i] %= MOD;
    pref[i] = pref[i-1]+dp[i];  pref[i] %= MOD;
  }
  for(int i = k+1; i <= n; ++i) {
    dp[i] = pref[i-1] - pref[i-k-1]+MOD;  dp[i] %= MOD;
    pref[i] = pref[i-1]+dp[i];  pref[i] %= MOD;
  }
  cout << dp[n];
}

int32_t main() {

  read();
  sol();

  return 0;
}
