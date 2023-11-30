#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 100;

int N, K;
int h[maxN+5];
int ans = 0;
int delta[maxN+5], newH[maxN+5], pref[maxN+5], suff[maxN+5];

void read_input()
{
  cin >> N >> K;
  FOR(i, 1, N) cin >> h[i];
}

void calc()
{
  int sum = 0;
  pref[0] = 0;  suff[N + 1] = 0;
  FOR(i, 1, N)
  {
    newH[i] = h[i] + delta[i];
    pref[i] = max(pref[i - 1], newH[i]);
  }
  FORD(i, N, 1)
  {
    suff[i] = max(suff[i + 1], newH[i]);
    sum += max(0ll, min(pref[i], suff[i]) - newH[i]);
  }
  ans = max(ans, sum);
}

void gen(int id, int exp)
{
  for(int i = 0; i <= exp; ++i)
  {
    delta[id] += i;
    if(id == N) calc();
    else gen(id + 1, exp - i);
    delta[id] -= i;
  }
}

void solve()
{
  gen(1, K);
  cout << ans;
}

int32_t main()
{
  file("backtrack_c");

  read_input();
  solve();

  return 0;
}
