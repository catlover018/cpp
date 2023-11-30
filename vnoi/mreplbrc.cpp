#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e3;
const int MOD = 1e5;

string s;
int n;

void read() {
  cin >> n >> s;
  s = ' ' + s;
}

int dp[maxN+5][maxN+5], mark[maxN+5][maxN+5];

int get(int i, int j) {
    if (s[i]==')' || s[i]==']' || s[i]=='}') return 0L;
    if (s[j]=='(' || s[j]=='[' || s[j]=='{') return 0L;

    if (s[i]=='?' && s[j]=='?') return 3;
    if (s[i]=='?' || s[j]=='?') return 1;

    if (s[i]=='(' && s[j]!=')') return 0;
    if (s[i]=='[' && s[j]!=']') return 0;
    if (s[i]=='{' && s[j]!='}') return 0;

    return 1;
}

void sol() {
  for(int i = 1; i <= n; ++i) dp[i][i-1] = 1;
  for(int i = 1; i < n; ++i) dp[i][i+1] = get(i, i+1);
  for(int len = 4; len <= n; ++len) {
    if(len%2==0) {
      for(int i = 1; i <= n-len+1; ++i) {
        int j = i+len-1;
        dp[i][j] = dp[i+1][j-1]*get(i, j);
        if(dp[i][j] > MOD) {
          dp[i][j] %= MOD;
          mark[i][j] = true;
        }
        for(int k = i + 1; k <= j-2; ++k) {
          dp[i][j] += dp[i+1][k-1]*get(i, k)*dp[k+1][j];
          if(dp[i][j] > MOD) {
            dp[i][j] %= MOD;
            mark[i][j] = true;
          }
        }
      }
    }
  }
  int ans = dp[1][n];
  if(!mark[1][n]) cout << ans;
  else {
    if(ans < 10) cout << "0000" << ans;
    else if(ans < 100) cout << "000" << ans;
    else if(ans < 1000) cout << "00" << ans;
    else if(ans < 10000) cout << "0" << ans;
    else cout << ans;
  }
}

int32_t main() {

//  freopen("test.inp", "r", stdin);
//  freopen("test.out", "w", stdout);

  read();
  sol();

  return 0;
}
