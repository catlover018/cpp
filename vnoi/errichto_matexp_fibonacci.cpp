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

  int row() { return base.size(); }

  int col() { return base[0].size(); }

  auto & operator [] (int i) { return base[i]; }
  auto const & operator [] (int i) const { return base[i]; }

  Matrix() {}
  Matrix(int r, int c)
  {
    vector<vector<ll>> res(r, vector<ll> (c));
    base = res;
  }
  Matrix(vector<vector<ll>> res)
  {
    base = res;
  }

  Matrix operator * (Matrix b)
  {
    Matrix a = *this;
    Matrix c = Matrix(a.row(), b.col());
    REP(i, a.row())
      REP(j, b.col())
        REP(k, a.col())
        {
          c[i][j] += a[i][k] * b[k][j];
          c[i][j] %= MOD;
        }
    return c;
  }

  Matrix Identity(ll n)
  {
    Matrix res = Matrix(n, n);
    while(n--)
      res[n][n] = 1;
    return res;
  }

  Matrix Pow(ll n)
  {
    Matrix a = *this;
    Matrix res = Identity(row());
    while(n)
    {
      if(n & 1) res = res * a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }
};

Matrix A(
{
  {1, 1},
  {1, 0}
});
Matrix B = Matrix(2, 1);

void solve() {
  B[0][0] = 1;
  B[1][0] = 1;
  ll n; cin >> n;
  if(n == 0)
  {
    cout << 0;
    return;
  }
  else if(n == 1)
  {
    cout << 1;
    return;
  }
  else if(n == 2)
  {
    cout << 1;
    return;
  }
  Matrix res = A.Pow(n - 2) * B;
  cout << res[0][0];
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

