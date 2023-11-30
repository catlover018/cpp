#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define cntbit(X) __builtin_popcountll(X)

using namespace std;

const int maxN = 100;

int N, M, ans = 0;
int mask[maxN+5], c[maxN+5];

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, M)
  {
    string s;
    cin >> s >> c[i];
    for(int j = 0; j < N; ++j)
      if(s[j] == '1') mask[i] += (1ll << j);
  }
}

void gen(int id, int cur, int k)
{
  if(id == N)
  {
    FOR(i, 1, M) if(N - __builtin_popcountll(cur ^ mask[i]) != c[i]) return;
    ++ans;
    return;
  }
  gen(id + 1, cur ^ (1ll << id), k);
  if(k > 0) gen(id + 1, cur, k - 1);
}

void solve()
{
  gen(0, mask[1], c[1]);
  cout << ans;
}

int32_t main()
{
  file("backtrack_i");

  read_input();
  solve();

  return 0;
}
