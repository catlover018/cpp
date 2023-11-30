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

int f[20][maxN+5], g[20][maxN+5];

int get(int l, int r)
{
  int k = log2(int(r - l + 1));
  int mx = max(f[k][l], f[k][r - (1 << k) + 1]);
  int mn = min(g[k][l], g[k][r - (1 << k) + 1]);
  return mx - mn + 1;
}

void solve() {
  int N, Q; cin >> N >> Q;
  FOR(i, 1, N)
  {
    int x;  cin >> x;
    f[0][i] = g[0][i] = x;
  }
  FOR(k, 1, 18)
  {
    for(int i = 1; i + (1 << (k - 1)) <= N; ++i)
    {
      f[k][i] = max(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
      g[k][i] = min(g[k - 1][i], g[k - 1][i + (1 << (k - 1))]);
    }
  }
  while(Q --> 0)
  {
    int l, r; cin >> l >> r;
    int cur = get(l, r);
    if(cur == r - l + 1)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
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

    file("bedao_g10_perfect");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

