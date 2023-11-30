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

void LineEqualtion(point A, point B, ld &a, ld &b, ld &c)
{
  a = A.y - B.y;
  b = B.x - A.x;
  c = - A.x * a - A.y * b;
}

ld calc(ld a, ld b, ld c)
{
  return sqrt(a * a + b * b);
}

bool check(point A, point B, ld a, ld b, ld c)
{
  ld cur1 = a * A.x + b * A.y + c;
  ld cur2 = a * B.x + b * B.y + c;

  return (cur1 * cur2 < 0);
}

void solve() {
  point X, Y, Z;
  cin >> X.x >> X.y;
  cin >> Y.x >> Y.y;
  cin >> Z.x >> Z.y;

  ld a1, b1, c1, a2, b2, c2;
  LineEqualtion(Y, X, a1, b1, c1);
  LineEqualtion(Z, X, a2, b2, c2);

  ld m1 = calc(a1, b1, c1),
     m2 = calc(a2, b2, c2);

  ld a = a1 / m1 - a2 / m2;
  ld b = b1 / m1 - b2 / m2;
  ld c = c1 / m1 - c2 / m2;

  if(check(Y, Z, a, b, c))
  {
    cout << fixed << setprecision(10) << a << ' ' << b << ' ' << c;
    return;
  }

  a = a1 / m1 + a2 / m2;
  b = b1 / m1 + b2 / m2;
  c = c1 / m1 + c2 / m2;

  cout << fixed << setprecision(10) << a << ' ' << b << ' ' << c;
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


