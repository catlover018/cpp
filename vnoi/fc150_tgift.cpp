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

vector<int> adj[maxN+5];
int h[maxN+5];
int f[20][maxN+5];

void dfs(int u, int p)
{
  h[u] = h[p] + 1;
  for(int v : adj[u])
  {
    if(v != p)
    {
      f[0][v] = u;
      for(int i = 1; i <= 18; ++i)
        f[i][v] = f[i - 1][f[i - 1][v]];
      dfs(v, u);
    }
  }
}

int lca(int u, int v)
{
  if(h[u] != h[v])
  {
    if(h[u] < h[v]) swap(u, v);
    int k = h[u] - h[v];
    for(int i = 0; i <= 18; ++i)
    {
      if(bit(k, i))
      {
        u = f[i][u];
      }
    }
  }

  if(u == v) return u;

  int k = log2(h[u]);
  for(int i = k; i >= 0; --i)
  {
    if(f[i][u] != f[i][v])
    {
      u = f[i][u];
      v = f[i][v];
    }
  }
  return f[0][u];
}

int a[maxN+5];
set<int> w1[maxN+5], w2[maxN+5];

void solve() {
  int N, M, Q;
  cin >> N >> M >> Q;
  REP(i, N-1)
  {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  // build lca
  dfs(1, 0);

  FOR(i, 1, M)
  {
    cin >> a[i];
    w1[a[i]].insert(i);
  }

  FOR(i, 1, M-1)
  {
    int tmp = lca(a[i], a[i + 1]);
    w2[tmp].insert(i);
  }

//  PR(a, M);

  while(Q --> 0)
  {
    int type; cin >> type;
    if(type == 2)
    {
      int l, r, u;  cin >> l >> r >> u;
      auto p = w1[u].lower_bound(l);
      if(p != w1[u].end() && *p <= r)
      {
        cout << *p << ' ' << *p << '\n';
        continue;
      }
      p = w2[u].lower_bound(l);
      if(p != w2[u].end() && *p + 1 <= r)
      {
        cout << *p << ' ' << *p + 1 << '\n';
        continue;
      }
      cout << -1 << ' ' << -1 << '\n';
    }
    else
    {
      int i, u; cin >> i >> u;
      w1[a[i]].erase(i);
      w1[u].insert(i);
      if(i < M)
      {
        int tmp = lca(a[i], a[i + 1]);
        int _tmp = lca(u, a[i + 1]);
        w2[tmp].erase(i);
        w2[_tmp].insert(i);
      }
      if(i > 1)
      {
        int tmp = lca(a[i - 1], a[i]);
        int _tmp = lca(a[i - 1], u);
        w2[tmp].erase(i-1);
        w2[_tmp].insert(i-1);
      }
      a[i] = u;
    }
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

    file("fc150_tgift");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

