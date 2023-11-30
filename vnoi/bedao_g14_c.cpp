// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define debug(x) { cerr << #x << " = "; cerr << (x) << endl; }
#define PR(a,n) { cerr << #a << " = "; FOR(_,1,n) cerr << a[_] << ' '; cerr << endl; }
#define PR0(a,n) { cerr << #a << " = "; REP(_,n) cerr << a[_] << ' '; cerr << endl; }

#define bit(X, i) ((X >> i) & 1)
#define cntbit(X) __builtin_popcountll(X)
#define fi first
#define se second
#define pb push_back
#define all(X) begin(X), end(X)
#define SZ(X) ((int)(X).size())
#define RR(X) X.resize(unique(all(X)) - begin(X))
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using namespace std;

template <typename T>
bool maximize(T &x, T y)
{
  if(x < y)
    x = y;
  else
    return 0;
  return 1;
}
template <typename T>
bool minimize(T &x, T y)
{
  if(x > y)
    x = y;
  else
    return 0;
  return 1;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll Rand(ll l, ll r) { return l + rand() % (r - l + 1); }

const int maxN = 1e6;
const ll inf = 1e18+7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

ll pw[maxN+5];
int a0, a1, b0, b1;

ll Pow(ll a, ll b)
{
  if(b == 0) return 1;
  ll tmp = Pow(a, b/2);
  if(b & 1) return tmp * tmp % MOD * a % MOD;
  return tmp * tmp % MOD;
}

ll C(int n, int k)
{
  if(n < k) return 0;
  ll tu = pw[n];
  ll mau = Pow(pw[k], MOD - 2) * Pow(pw[n - k], MOD - 2) % MOD;
//  cout << n << ' ' << k << ' ' << tu * mau % MOD << '\n';
  return (tu * mau % MOD);
}

ll calc(int len, int a, int b)
{
  if(len <= 0) return 0;
  int x = a - len * b;
  if(x < 0) return 0;
  return C(x + len, x);
}

ll calc(int len)
{
  ll tmp0 = calc(len, a0, b0);
  ll tmp11 = calc(len, a1, b1);
  ll tmp12 = calc(len + 1, a1, b1);
  ll tmp13 = calc(len - 1, a1, b1);
//  cout << tmp0 << ' ' << tmp11 << ' ' << tmp12 << ' ' << tmp13 << '\n';
  ll res = tmp0 % MOD * (tmp11 * 2 + tmp12 + tmp13) % MOD;
//  cout << res << '\n';
  return res;
}

void solve() {
  pw[0] = 1;
  FOR(i, 1, maxN)
  {
    pw[i] = pw[i - 1] * i % MOD;
  }
  cin >> a0 >> a1 >> b0 >> b1;
  ll res = 0;
  for(int i = 1; i * b0 <= a0; ++i)
  {
    res = (res + calc(i)) % MOD;
  }
  cout << res << ' ';
}

void solve_TestCase() {
  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    solve();
  }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("test_code");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
