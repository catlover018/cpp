#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 100;

int N, h[maxN+5], mark[maxN+5];
int w[maxN+5][maxN+5];
int ans = 1e18, sum = 0;

void read_input()
{
  cin >> N;
  FOR(i, 1, N) cin >> h[i];
  FOR(i, 1, N)
    FOR(j, i + 1, N)
      cin >> w[i][j];
}

void calc()
{
  sum = 0;
  FOR(i, 1, N)
  {
    sum += h[i] * mark[i];
    FOR(j, i + 1, N)
      sum += w[i][j] * mark[i] * mark[j];
  }
  ans = min(ans, sum);
}

void gen(int id)
{
  FOR(i, -1, 1)
  {
    if(i == 0) continue;
    mark[id] = i;
    if(id == N) calc();
    else gen(id + 1);
  }
}

void solve()
{
  gen(1);
  cout << ans;
}

int32_t main()
{
  file("backtrack_k");

  read_input();
  solve();

  return 0;
}
