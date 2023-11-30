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

const int maxW = 1e5;
const int maxN = 1e2;
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

ll dp[maxW+5];
vector<ll> W, V;

void solve() {
  int n, m; cin >> n >> m;
  W.pb(0);  V.pb(0);
  FOR(i, 1, n)
  {
    ll w, v, a;
    cin >> w >> v >> a;
    ll tmp = 1;
    while(tmp <= a)
    {
      a -= tmp;
      W.pb(w * tmp);
      V.pb(v * tmp);
      tmp *= 2;
    }
    if(a > 0)
    {
      W.pb(w * a);
      V.pb(v * a);
    }
  }
  n = SZ(W);
  FOR(i, 1, n - 1)
  {
    FORD(j, m, 0)
    {
      if(j >= W[i]) dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
    }
  }
  cout << dp[m];
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


