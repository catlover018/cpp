#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define bit(X, i) ((X >> i)&1)

using namespace std;

const int maxN = 100;
const int need = (1ll << 26)-1;

int N;
int mask[maxN+5], choose = 0;
int ans = 0;

void read_input()
{
  cin >> N;
  FOR(i, 1, N)
  {
    string s; cin >> s;
    mask[i] = 0;
    for(char c : s)
      if(bit(mask[i], c - 'a') == 0)
      mask[i] += (1ll << (c - 'a'));
  }
}

void gen(int id, int cur)
{
//  cout << id << ' ' << choose << endl;
  if(cur == need && id == N + 1) ++ans;

  if(id > N) return;

  gen(id + 1, cur | mask[id]);

  gen(id + 1, cur);
}

void solve()
{
  gen(1, 0);
  cout << ans;
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("backtrack_d");

  read_input();
  solve();

  return 0;
}
