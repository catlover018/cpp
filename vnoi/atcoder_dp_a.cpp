#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1e6;

int N, a[maxN+5], dp[maxN+5];

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> N;
  FOR(i, 1, N) cin >> a[i];

  dp[1] = 0;
  FOR(i, 2, N)
  {
    dp[i] = 1e9;
    if(i - 1 >= 1) dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
    if(i - 2 >= 1) dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
  }
  cout << dp[N];

  return 0;
}
