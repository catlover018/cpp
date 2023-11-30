#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define _(X) ~(X)

using namespace std;

const int maxN = 1e3;

int a[maxN+5][maxN+5];
int N;
int col[2][maxN+5], row[2][maxN+5], dp[2][maxN+5];

void read_input()
{
  cin >> N;
  FOR(i, 1, N) FOR(j, 1, N) cin >> a[i][j];
}

void solve()
{
  FOR(i, 1, N)
  {
    FOR(j, 1, N)
    {
      col[i&1][j] = col[~i&1][j] ^ a[i][j];
      row[i&1][j] = row[i&1][j - 1] ^ a[i][j];
      dp[i&1][j] = 0;
      if(~col[i&1][j] & 1) dp[i&1][j] |= ~dp[i&1][j-1];
      if(~row[i&1][j] & 1) dp[i&1][j] |= ~dp[~i&1][j];
    }
  }
  cout << (dp[N&1][N] ? "YES" : "NO") << '\n';
}

int main()
{

  file("parigame");

  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    FOR(i, 1, N)
    {
      dp[0][i] = col[0][i] = row[0][i] = 0;
      dp[1][i] = col[1][i] = row[1][i] = 0;
    }
    read_input();
    solve();
  }


  return 0;
}
