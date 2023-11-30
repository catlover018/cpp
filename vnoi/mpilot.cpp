#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e4;

int n;
int a[maxN+5], b[maxN+5];
int dp[2][maxN+5];

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  for(int i = 0; i < 2; ++i)
    for(int j = n/2; j >= 0; --j)
      dp[i][j] = 1e9;
}

void sol() {
  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = i/2; j > 0; --j) {
      dp[i%2][j] = min(dp[(i-1)%2][j-1] + a[i], dp[(i-1)%2][j] + b[i]);
    }
    dp[i%2][0] = dp[(i-1)%2][0] + b[i];
  }
  cout << dp[n%2][n/2];
}

int32_t main() {

  read();
  sol();

  return 0;
}
