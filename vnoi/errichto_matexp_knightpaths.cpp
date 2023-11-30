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
const int MOD = (1 << 32);
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
  vector<vector<unsigned int>> base;

  int row() { return SZ(base); }
  int col() { return SZ(base[0]); }

  auto & operator [] (int i) { return base[i]; }
  const auto & operator [] (int i) const { return base[i]; }

  Matrix()
  {
    base.resize(65, vector<unsigned int> (65));
  }

  Matrix operator * (Matrix &b)
  {
    Matrix a = *this;
    Matrix c = Matrix();
    REP(i, a.row()) REP(j, b.col()) REP(k, a.col())
    {
      c[i][j] += a[i][k] * b[k][j];
    }
    return c;
  }

  Matrix Pow(int x)
  {
    Matrix a = *this;
    Matrix res = Matrix();
    FOR(i, 0, 64) res[i][i] = 1;
    while(x)
    {
      if(x & 1) res = res * a;
      a = a * a;
      x >>= 1;
    }
    return res;
  }
};

void solve() {
  int K;  cin >> K;
  Matrix res = Matrix();
  res[64][64] = 1;
  FOR(i, 0, 63)
  {
    res[i][64] = 1;
    FOR(j, 0, 63)
    {
      int r1 = i / 8;
      int c1 = i % 8;
      int r2 = j / 8;
      int c2 = j % 8;
      int row = abs(r2 - r1);
      int col = abs(c2 - c1);
      if((row == 1 && col == 2) || (row == 2 && col == 1))
          res[i][j] = 1;
    }
  }
  res = res.Pow(K + 1);
  cout << res[0][64];
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


