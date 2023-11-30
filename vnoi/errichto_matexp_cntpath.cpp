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

struct Matrix
{
  vector<vector<ll>> base;

  int row() { return SZ(base); }
  int col() { return SZ(base[0]); }

  Matrix() = default;
  Matrix(int r, int c)
  {
    vector<vector<ll>> cur(r, vector<ll> (c));
    base = cur;
  }

  auto & operator [] (int i) { return base[i]; }
  const auto & operator [] (int i) const { return base[i]; }

  Matrix operator * (Matrix &b)
  {
    Matrix a = *this;
    Matrix res = Matrix(a.row(), b.col());
    REP(i, a.row()) REP(j, b.col()) REP(k, a.col())
    {
      res[i][j] += a[i][k] * b[k][j];
      res[i][j] %= MOD;
    }
    return res;
  }

  Matrix identity(int n)
  {
    Matrix res = Matrix(n, n);
    while(n--) res[n][n] = 1;
    return res;
  }

  Matrix Pow(ll x)
  {
    Matrix a = *this;
    Matrix res = identity(a.row());
    while(x)
    {
      if(x & 1) res = res * a;
      a = a * a;
      x >>= 1;
    }
    return res;
  }
} A;

void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  A = Matrix(N, N);
  while(M --> 0)
  {
    int u, v; cin >> u >> v;
    --u;  --v;
    A.base[u][v] = 1;
  }
  A = A.Pow(K);
  ll ans = 0;
  REP(i, N) REP(j, N)
  {
    ans += A.base[i][j];
    ans %= MOD;
  }
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


