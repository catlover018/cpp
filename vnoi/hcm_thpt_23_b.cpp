#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1000;

int dp[maxN+5][maxN+5];
int N, K, total = 0;
int d[maxN+5];

void read_input()
{
  cin >> N >> K;
  FOR(i, 1, N) cin >> d[i], total += d[i];
}

void solve()
{
  memset(dp, 60, sizeof(dp));
  int mx = 0, sum = 0;
  FOR(i, 1, N)
  {
    mx = max(mx, d[i]);
    sum += d[i];
    dp[i][0] = mx * i - sum;
  }
  FOR(i, 1, N)
  {
    FOR(j, 1, K)
    {
      int mx = d[i], sum = d[i];
      dp[i][j] = dp[i - 1][j - 1];
      FORD(k, i - 1, 1)
      {
        mx = max(mx, d[k]);
        sum = sum + d[k];
        dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + mx * (i - k + 1) - sum);
      }
//      cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
  }
  cout << dp[N][K];
}

int32_t main()
{
  file("hcm_thpt_23_b");

  read_input();
  solve();

  return 0;
}
