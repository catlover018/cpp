#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".ans", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 100;

int N;
bitset<30> d[maxN+5];
int ans = 0;
int mark[maxN+5];

void read_input()
{
  cin >> N;
  FOR(i, 1, N)
  {
    string s; cin >> s;
    for(char c : s) d[i][c - 'a'] = 1;
  }
}

void calc()
{
  bitset<30> base;
  FOR(i, 1, N)
  {
    if(mark[i]) base |= d[i];
  }
  if(base.count() == 26)
  {
    FOR(i, 1, N) cout << mark[i] << ' ';
    cout << endl;
    ++ans;
  }
}

void gen(int id)
{
  FOR(i, 0, 1)
  {
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

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("test_code");

  read_input();
  solve();

  return 0;
}
