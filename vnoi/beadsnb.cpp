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

int n;
int a[maxN+5], b[maxN+5], lis[maxN+5], lds[maxN+5], BIT1[maxN+5], BIT2[maxN+5];

int get(int x, int BIT[])
{
  int res = 0;
  for(; x > 0; x -= (x&-x)) res = max(res, BIT[x]);
  return res;
}

void update(int x, int val, int BIT[])
{
  for(; x <= n; x += (x&-x)) BIT[x] = max(BIT[x], val);
}

void solve() {
  cin >> n;
  vector<int> v1, v2;
  FOR(i, 1, n)
  {
    cin >> a[i];
    v1.pb(a[i]);
    b[i] = -a[i];
    v2.pb(b[i]);
  }
  sort(all(v1)); sort(all(v2));
  RR(v1);  RR(v2);
  FOR(i, 1, n)
  {
    a[i] = lower_bound(all(v1), a[i]) - v1.begin() + 1;
    b[i] = lower_bound(all(v2), b[i]) - v2.begin() + 1;
  }

  reverse(a + 1, a + n + 1);
  //processing
  FOR(i, 1, n) //lis
  {
    lis[i] = get(a[i] - 1, BIT1) + 1;
    update(a[i], lis[i], BIT1);
  }

  reverse(b + 1, b + n + 1);
  FOR(i, 1, n)  //lds
  {
    lds[i] = get(b[i] - 1, BIT2) + 1;
    update(b[i], lds[i], BIT2);
  }

  int res = 0;
  FOR(i, 1, n)
  {
    res = max(res, lis[i] + lds[i] - 1);
  }

  cout << res;
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

    file("beadsnb");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


