#include <bits/stdc++.h>

using namespace std;

const int maxN = 20;

int a[maxN+5], n;
int dp[maxN+5];

void init() {
  dp[0] = 1;
  for(int i = 1; i <= 12; ++i) dp[i] = dp[i-1]*i;
}

int mark[maxN+5];

void sol() {
  init();
  n = 0;
  while(cin >> a[++n]);
  int p = a[--n]; --n;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
      int x = 0;
      for(int j = 1; j <= n; j ++) {
        if (a[i] > j && !mark[j]) x ++;
      }
      mark[a[i]] = 1;
      ans += x * dp[n - i];
  }
  memset(mark, 0, sizeof mark);
  memset(a, 0, sizeof a);
  cout << ans + 1 << '\n';
  for(int i = 1; i <= n; i ++) {
    int x = 0;
    while(p > dp[n - i]) {
      x ++;
      p -= dp[n - i];
    }
    int cnt = 0;
    for(int j = 1; j <= n; j ++) {
      if (!mark[j] && cnt == x) {
        a[i] = j;
        mark[j] = 1;
        break;
      }
      if (!mark[j]) cnt ++;
    }
  }
  for(int i = 1; i <= n; i ++) cout << a[i] << ' ';
}

int main() {

//  freopen("test.inp", "r", stdin);
//  freopen("test.out", "w", stdout);

  sol();

  return 0;
}
