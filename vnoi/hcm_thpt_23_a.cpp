#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;

typedef pair<int, int> pii;

int BIT[maxN+5];
int N;
pii a[maxN+5];

void read_input()
{
  cin >> N;
  FOR(i, 1, N) cin >> a[i].fi, a[i].se = i;
}

int get(int x)
{
  int res = 0;
  for(; x > 0; x -= (x&-x)) res += BIT[x];
  return res;
}

void update(int x, int val)
{
  for(; x <= N; x += (x&-x)) BIT[x] += val;
}

void solve()
{
  update(1, 1);
  FOR(i, 2, N) update(i, 1);
  sort(a + 1, a + N + 1);
  int l = 1, r = N;
  FOR(i, 1, N)
  {
    if(i & 1)
    {
      int p = get(a[l].se);
      update(a[l].se, -1);
      cout << p - 1 << '\n';
      ++l;
    }
    else
    {
      int p = get(N) - get(a[r].se);
      update(a[r].se, -1);
      cout << p << '\n';
      --r;
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("hcm_thpt_23_a");

  read_input();
  solve();

  return 0;
}
