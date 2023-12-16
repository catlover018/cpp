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
const ld eps = 1e-15;

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

ld D;
pair<ld, ld> P, A, B;

ld sqr(ld x)
{
  return x * x;
}

ld get(ld x, ld y, ld u, ld v)
{
  return sqrt(sqr(x * 1.0 - u) + sqr(y * 1.0 - v));
}

bool check(ld dis)
{
  if (get(0,0,A.fi,A.se) <= dis && get(P.fi, P.se, A.fi, A.se) <= dis) return 1;
  if (get(0,0,B.fi,B.se) <= dis && get(P.fi, P.se, B.fi, B.se) <= dis) return 1;
  if(get(A.fi, A.se, B.fi, B.se) > dis * 2) return 0;
  if(get(0, 0, A.fi, A.se) <= dis && get(P.fi, P.se, B.fi, B.se) <= dis) return 1;
  return 0;
}

void solve() {
  cin >> P.fi >> P.se >> A.fi >> A.se >> B.fi >> B.se;
  ld
    tmp1 = get(A.fi, A.se, 0, 0),
    tmp4 = get(B.fi, B.se, 0, 0);
  if(tmp1 > tmp4) swap(A, B);
  ld l = eps, r = 1e9,
    res = 1e9; D = r;
//  cout << tmp1 << ' ' << tmp2 << ' ' << D << '\n';
  while(r - l > eps)
  {
    ld mid = (r + l) / 2;
    if(check(mid))
    {
      res = mid;
      r = mid;
    }
    else l = mid;
  }
  cout << fixed << setprecision(10) << res << '\n';
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

    file("test");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

