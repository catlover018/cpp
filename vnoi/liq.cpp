#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)

using namespace std;

const int maxN = 2e5;

int N;

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

  int res = 0;
  FOR(i, 1, N)
  {
    int x;  cin >> x;
    int cur = st.get(x - 1) + 1;
    st.update(x, cur);
    res = max(res, cur);
  }
  cout << res;

  return 0;
}
