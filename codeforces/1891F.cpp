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

ll BIT[maxN+5];
vector<int> adj[maxN+5];
vector<pii> qu[maxN+5];
int N, n = 1, pos[maxN+5];
ll ans[maxN+5];

void update(int x, int val)
{
  for(; x <= N; x += (x&-x)) BIT[x] += val;
}

ll get(int x)
{
  ll res = 0;
  for(; x > 0; x -= (x&-x)) res += BIT[x];
  return res;
}

void dfs(int u)
{
  for(pii e : qu[u]) update(e.fi, e.se);
  ans[u] = get(N) - get(pos[u] - 1);
  for(int v : adj[u]) dfs(v);
  for(pii e : qu[u]) update(e.fi, -e.se);
}

void solve() {
  cin >> N; n = 1;  pos[1] = 1;
  FOR(i, 1, N)
  {
    int type; cin >> type;
    if(type == 1)
    {
      int u;  cin >> u;
      adj[u].pb(++n);
      pos[n] = i;
    }
    else
    {
      int u, x;
      cin >> u >> x;
      qu[u].pb({i, x});
    }
  }

  dfs(1);

  FOR(i, 1, n) cout << ans[i] << ' ';
  cout << '\n';

  FOR(i, 1, n)
  {
    BIT[i] = 0;
    qu[i].clear();
    pos[i] = 0;
    adj[i].clear();
    ans[i] = 0;
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

    file("template");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


