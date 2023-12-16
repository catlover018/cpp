#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1e6;

int N, K;
int a[maxN+5];

void read_input()
{
  cin >> N >> K;
  FOR(i, 1, N) cin >> a[i];
}

void solve()
{
  sort(a + 1, a + N + 1);
//  FOR(i, 1, N) cout << a[i] << ' '; cout << endl;
  int res = 0, num = N / K;
  for(int i = num; i <= N; i += num)
  {
    res += a[i] - a[i - num + 1];
  }
  cout << res;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("fcb054_rock");

  read_input();
  solve();

  return 0;
}
