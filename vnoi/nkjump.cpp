#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;

int n, a[maxN+5];
int dp[maxN+5];

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
}

void sol() {
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for(int j = 1; j < i; ++j) {
      int cur = a[i] - a[j];
      if(!binary_search(a+1, a+j, cur) && !binary_search(a+j+1, a+n+1, cur)) continue;
      dp[i] = max(dp[i], dp[j]+1);
    }
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

int main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("JUMP.inp", "r", stdin);
  freopen("JUMP.out", "w", stdout);

  read();
  sol();

  return 0;
}
