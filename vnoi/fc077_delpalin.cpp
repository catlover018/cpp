// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

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

const int maxN = 1e3;
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

ll dp[maxN+5][maxN+5];
int n;
string s;

void f()
{
  FORD(i, n, 1)
  {
    dp[i][i] = 1;
    FOR(j, i + 1, n)
    {
      if(i == j - 1)
      {
        if(s[i] == s[j])dp[i][j] = 1;
      }
      else
      {
        if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
        FOR(k, i, j - 1)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
      }
    }
  }
}

ll calc(int i, int j)
{
  if(i >= j) return 1;

  ll &x = dp[i][j];
  if(x != inf) return x;

  ll res = inf;
  if(s[i] == s[j])
  {
    res = calc(i + 1, j - 1);
  }

  FOR(k, i, j - 1)
    res = min(res, calc(i, k) + calc(k + 1, j));

  return x = res;
}

void solve() {
  cin >> s;
  n = s.size();   s = ' ' + s;
  FOR(i, 0, n+1)  FOR(j, 0, n+1)
      dp[i][j] = inf;
  cout << calc(1, n) << '\n';
}

void solve_Testcase() {
  int testcase; cin >> testcase;
  while(testcase--)
  {
    solve();
  }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("fc077_delpalin");

    solve_Testcase();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


