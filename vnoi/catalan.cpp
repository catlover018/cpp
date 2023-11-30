#include <bits/stdc++.h>

using namespace std;

const int maxN = 50;

int a[maxN+5], dp[maxN+5][maxN+5];
int n, k;

void read() {
  cin >> n; n = (n<<1)+1;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  cin >> k;
}

void sol() {
  dp[0][0] = 1; dp[1][1] = 1;
  for(int j = 2; j < n; ++j) {
    dp[0][j] = dp[1][j-1];
    for(int i = 1; i <= n+1; ++i)
      dp[i][j] = dp[i-1][j-1] + dp[i+1][j-1];
  }
  int cur = 0;
  for(int i = 2; i <= n; ++i) {
    if(a[i] < a[i-1] || a[i-1] == 0) continue;
    cur += dp[a[i-1]-1][n-i];
  }
  --k;
  a[1] = 0;
  for(int i = 2; i <= n; ++i) {
    if(a[i-1] == 0) a[i] = 1;
    else {
      if(k >= dp[a[i-1]-1][n-i]) {
        k -= dp[a[i-1]-1][n-i];
        a[i] = a[i-1]+1;
      } else a[i] = a[i-1]-1;
    }
  }
  cout << cur+1 << '\n';
  for(int i = 1; i <= n; ++i) cout << a[i] << " ";
}

int main() {

  read();
  sol();

  return 0;
}
