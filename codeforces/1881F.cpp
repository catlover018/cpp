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

int n, m;
vector<int> adj[maxN+5];
pii v1, v2;

void dfs(int u, int p, vector<int> &d)
{
  d[u] = d[p] + 1;
  for(int v : adj[u])
  {
    if(v == p) continue;
    dfs(v, u, d);
  }
}

void solve() {
  cin >> n >> m;

  // clear
  vector<int> mark;
  FOR(i, 1, n)
  {
    adj[i].clear();
  }

  // read input
  FOR(i, 1, m)
  {
    int u;  cin >> u;
    mark.pb(u);
  }
  FOR(i, 1, n - 1)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  // solve
  if(m == 1)
  {
    cout << 0 << '\n';
    return;
  }

  // dfs first time
  vector<int> d1(n + 1);
  d1[0] = -1;
  dfs(mark[0], 0, d1);
  int mx = mark[0];
  for(int x : mark)
  {
    if(d1[mx] < d1[x])
    {
      mx = x;
    }
  }

  // dfs second time
  vector<int> d2(n + 1);
  d2[0] = -1;
  dfs(mx, 0, d2);
  mx = mark[0];
  for(int x : mark)
  {
    if(d2[mx] < d2[x])
    {
      mx = x;
    }
  }

  cout << (d2[mx] + 1) / 2 << '\n';
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

    file("1881F");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


