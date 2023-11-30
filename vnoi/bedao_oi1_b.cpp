#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4;

int a[maxN+5], b[maxN+5];
int n, m;

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= m; ++i) cin >> b[i];
}

int dp[maxN+5][maxN+5];
int g[maxN+5][maxN+5];

void sol() {
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
      if(a[i] == b[j]) {
        dp[i][j] = dp[i-1][j-1]+1;
        g[i][j] = 1;
      } else {
        if(dp[i-1][j] > dp[i][j-1]) {
          dp[i][j] = dp[i-1][j];
          g[i][j] = g[i-1][j];
        } else if(dp[i-1][j] < dp[i][j-1]) {
          dp[i][j] = dp[i][j-1];
          g[i][j] = dp[i][j-1];
        } else if(dp[i-1][j] == dp[i][j-1] && dp[i][j-1] != 0) {
          dp[i][j] = dp[i][j-1];
          g[i][j] = g[i-1][j] + g[i][j-1];
        }
      }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j)
      cout << g[i][j] << " ";
      cout << endl;
  }
  cout << dp[n][m] << " " << g[n][m];
}

int main() {

  read();
  sol();

  return 0;
}
