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
int a[30][maxN+5], g[30][maxN+5];

void solve() {
  int n;  cin >> n;
  FOR(i,1 , n)
    FOR(j, 0, 29)
  {
    a[j][i] = 0;
    g[j][i] = 0;
  }
  FOR(i, 1, n)
  {
    int x;  cin >> x;
    FOR(j, 0, 29)
    {
      if(bit(x, j))
      {
        a[j][i] = 1;
      }
    }
  }
  FOR(i, 0, 29)
  {
    g[i][0] = 0;
    FOR(j, 1, n)
    {
      g[i][j] = g[i][j-1] + a[i][j];
    }
  }
//  FOR(i, 0, 10)
//  {
//    FOR(j, 1, n)
//    {
//      cout << a[i][j] << ' ';
//    }
//    cout << '\n';
//  }
  int q;  cin >> q;
  while(q--)
  {
    int le, k; cin >> le >> k;
    int r = n, l = le;
    int p = -1;
    while(l <= r)
    {
      int mid = (l + r) / 2;
      int ans = 0;
      for(int i = 29; i >= 0; i--)
      {
        if(g[i][mid] - g[i][le - 1] == mid - le + 1)
        {
          ans += (1 << i);
        }
      }
//      cout << g[2][le-1] << ' ' << g[2][mid] << ' ' << mid << endl;
      if(ans >= k)
      {
        p = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
      cout << p << ' ';
  }
  cout << '\n';
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

    file("1878E");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


