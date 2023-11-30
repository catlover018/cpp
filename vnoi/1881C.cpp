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

const int maxN = 2e3;
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

int a[maxN+5][maxN+5];
int cnt[maxN+5];

void solve() {
  int N;  cin >> N;
  FOR(i, 1, N)
  {
    FOR(j, 1, N)
    {
      char c; cin >> c;
      a[i][j] = c - 'a';
    }
  }
  ll ans = 0;
  FOR(i, 1, N/2)
  {
    FOR(j, 1, N/2)
    {
      int x1 = i, y1 = j;
      int x2 = j, y2 = N - i + 1;
      int x3 = N - i + 1, y3 = N - j + 1;
      int x4 = N - j + 1, y4 = i;
      ++cnt[a[x1][y1]];
      ++cnt[a[x2][y2]];
      ++cnt[a[x3][y3]];
      ++cnt[a[x4][y4]];
      int mx = 0;
      for(int k = 0; k <= 25; ++k)
      {
        mx = max(mx, cnt[k]);
        cnt[k] = 0;
      }
      cout << x1 << ' ' << y1;
      ans += (4 - mx);
    }
  }
  cout << ans << '\n';
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

    file("1881C");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


