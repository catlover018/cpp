#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define SZ(X) (int)(X.size())
#define pb push_back

using namespace std;

const int maxN = 1e6;

int N;
vector<int> prime;
int ans = 0;

void sieve()
{
  int cur = 1;
  while(SZ(prime) <= 20)
  {
    int i = 2;
    bool ok = true;
    while(i * i <= cur)
    {
      if(cur % i == 0)
      {
        ok = false;
        break;
      }
      ++i;
    }
    if(ok) prime.pb(cur);
    ++cur;
  }
}

void read_input()
{
  cin >> N;
}

void gen(int id, int exp, int val, int numdiv)
{
  ans = max(ans, numdiv);
  if(id == SZ(prime)) return;
  FOR(i, 1, exp)
  {
    if(val > N / prime[id]) return;
    val *= prime[id];
    gen(id + 1, i, val, numdiv * (i + 1));
  }
}

void solve()
{
  ans = -1;
  gen(1, 64, 1, 1);
  cout << ans << '\n';
}

int32_t main()
{
  file("backtrack_h");

  sieve();

  int testcase; cin >> testcase;
  while(testcase --> 0)
  {
    read_input();
    solve();
  }

  return 0;
}
