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

typedef long double ld;

struct point { ld x, y; };

point vecto(point A, point B)
{
  point res;
  res.x = B.x - A.x;
  res.y = B.y - A.y;
  return res;
}

bool DotProduct(point A, point B)
{
  return (A.x * B.x + A.y * B.y < 0);
}

ld sqr(ld x) { return x * x; }

ld calc(point A, point B) { return sqrt(sqr(A.x - B.x) + sqr(A.y - B.y)); }

void LineEqualtion(point A, point B, ld& a, ld &b, ld &c)
{
  a = A.y - B.y;
  b = B.x - A.x;
  c = - A.x * a - A.y * b;
}

ld calcDIS(point A, ld a, ld b, ld c)
{
  ld numer = a * A.x + b * A.y + c;
  ld deno = sqrt(a * a + b * b);
  return abs(numer) / deno;
}

void solve() {
  point A, B, C;
  cin >> A.x >> A.y;
  cin >> B.x >> B.y;
  cin >> C.x >> C.y;

  point BA = vecto(A, B);
  point BC = vecto(C, B);
  point CA = vecto(A, C);
  point CB = vecto(B, C);

  if(DotProduct(BA, BC) || DotProduct(CA, CB))
  {
    cout << fixed << setprecision(6) << min(calc(A, B), calc(A, C));
  }
  else
  {
    ld a, b, c;
    LineEqualtion(B, C, a, b, c);
    cout << fixed << setprecision(6) << calcDIS(A, a, b, c);
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

    file("template");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


