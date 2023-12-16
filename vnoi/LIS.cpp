#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define SZ(X) ((X).size())
#define all(X) X.begin(), X.end()
#define pb push_back

using namespace std;

const int maxN = 2e5;

int N;
int a[maxN+5];

struct Fenwick
{
  int BIT[maxN+5];

  void update(int x, int val)
  {
    for(; x <= maxN; x += (x&-x)) BIT[x] = max(BIT[x], val);
  }

  int get(int x)
  {
    int res = 0;
    for(; x > 0; x -= (x&-x)) res = max(res, BIT[x]);
    return res;
  }
} st;

int main()
{
  cin.tie(0)->sync_with_stdio();

  cin >> N;
  vector<int> v;
  FOR(i, 1, N)
  {
    cin >> a[i];
    v.pb(a[i]);
  }
  sort(all(v));
  v.resize(unique(all(v)) - v.begin());

  int res = 0;
  FOR(i, 1, N)
  {
    int x = lower_bound(all(v), a[i]) - v.begin() + 1;
    int cur = st.get(x - 1) + 1;
    st.update(x, cur);
    res = max(res, cur);
  }
  cout << res;

  return 0;
}

