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

int n,m;
int row[maxN+5], col[maxN+5];
map<vector<vector<char>>, int> mp;
int ans = 0;

void update(vector<vector<char>> c)
{
  vector<vector<char>> res = c;
  FOR(i, 0, n - 1)
  {
    if(row[i])
    {
      string s = "";
      FOR(j, 0, m - 1)
      {
        s += res[i][j];
      }
      reverse(all(s));
      FOR(j, 0, m - 1)
      {
        res[i][j] = s[j];
      }
    }
  }
  FOR(i, 0, m - 1)
  {
    if(col[i])
    {
      string s = "";
      FOR(j, 0, n - 1)
      {
        s += res[j][i];
      }
      reverse(all(s));
      FOR(j, 0, n - 1)
      {
        res[j][i] = s[j];
      }
    }
  }
  ans += !mp[res];
  mp[res] = true;
}

void sinh2(int i, vector<vector<char>> c)
{
  for(int j = 0; j < 2; ++j)
  {
    col[i] = j;
    if(i == m - 1)
    {
      update(c);
    } else sinh2(i + 1, c);
  }
}

void sinh(int i, vector<vector<char>> c)
{
  for(int j = 0; j < 2; ++j)
  {
    row[i] = j;
    if(i == n - 1)
    {
      sinh2(0, c);
    }
    else sinh(i + 1, c);
  }
}

void solve() {
  cin >> n >> m;
  vector<vector<char>> c(n + 1, vector<char> (m + 1));
  FOR(i, 0, n-1)
  {
    FOR(j, 0, m-1)
    {
      cin >> c[i][j];
    }
  }
  sinh(0, c);
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

    file("template");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


