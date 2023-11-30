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

int a[maxN+5];
int g[20][maxN+5];

int get(int l,  int r)
{
  int k = r - l + 1;
  k = log2(k);
  return __gcd(g[k][l], g[k][r - (1 << k) + 1]);
}

void solve() {
  int n;  cin >> n;
  ++n;
  FOR(i, 1, n)
  {
    cin >> a[i];
    g[0][i] = a[i];
  }
  for(int k = 1; k <= 18; ++k)
  {
    for(int i = 1; i + (1 << (k - 1)) <= n; ++i)
    {
      g[k][i] = __gcd(g[k - 1][i], g[k - 1][i + (1 << (k - 1))]);
    }
  }
  for(int i = 2; i <= n; ++i)
  {
    int l = 1, r = i - 1;
    int cur = -1;
    while(l <= r)
    {
      int mid = (l + r) / 2;
      if(__gcd(a[i], a[mid]) == 1)
      {
        cout << a[mid] << ' ' << a[i] << '\n';
        return;
      }
      if(get(mid , i) == 1)
      {
        cur = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    if(cur == -1) continue;
    if(__gcd(a[i], a[cur]) == 1)
    {
      cout << a[cur] << ' ' << a[i] << '\n';
      return;
    }
  }
  cout << -1 << ' ' << -1 << '\n';
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

    file("bedao_g14B");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


