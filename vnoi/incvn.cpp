// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define debug(x) { cerr << #x << " = "; cerr << (x) << endl; }
#define PR(a,n) { cerr << #a << " = "; FOR(_,1,n) cerr << a[_] << ' '; cerr << endl; }
#define PR0(a,n) { cerr << #a << " = "; REP(_,n) cerr << a[_] << ' '; cerr << endl; }

#define sqr(x) ((x) * (x))
#define bit(X, i) ((X >> i) & 1)
#define cntbit(X, i) __builtin_popcountll(X)
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

const int maxN = 2e5;
const ll inf = 1e18+7;
const int MOD = 5e6;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

int n, k;
int a[maxN+5];
ll dp[maxN+5];
ll BIT[maxN+5];

void update(int i, int val)
{
  for(; i <= maxN; i+=(i&-i)) BIT[i] = (BIT[i] + val) % MOD;
}

ll get(int i)
{
  ll res = 0;
  for(; i > 0; i-=(i&-i)) res = (res + BIT[i]) % MOD;
  return res;
}

void solve() {
  cin >> n >> k;
  FOR(i, 1, n) {
    cin >> a[i];
    ++a[i];
    dp[i] = 1;
  }
  FOR(_, 2, k)
  {
    memset(BIT, 0, sizeof(BIT));
    FOR(i, 1, n)
    {
      update(a[i], dp[i]);
      dp[i] =  get(a[i] - 1);
//      if(_ == 2) debug(dp[i]);
    }
  }
  ll ans = 0;
  FOR(i, 1, n) ans = (ans + dp[i]) % MOD;
  cout << ans;
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

    file("template");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


