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

int d1[maxN+5], d2[maxN+5];
vector<pii> adj1[maxN+5], adj2[maxN+5];
int n, m, k, s, t;

void dijkstra(int u, int d[], vector<pii> adj[])
{
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  d[u] = 0;
  Q.push({d[u], u});
  while(!Q.empty())
  {
    auto [len, u] = Q.top();  Q.pop();
    if(len > d[u]) continue;
    for(auto [v, w] : adj[u])
    {
      if(d[v] > d[u] + w)
      {
        d[v] = d[u] + w;
        Q.push({d[v], v});
      }
    }
  }
}

void solve() {
  cin >> n >> m >> k >> s >> t;
  FOR(i, 1, m)
  {
    int u, v, w;  cin >> u >> v >> w;
    adj1[u].pb({v, w});
    adj2[v].pb({u, w});
  }
  FOR(i, 1, n)
  {
    d1[i] = d2[i] = 1e9;
  }
  dijkstra(s, d1, adj1);
  ll res = d1[t];
  dijkstra(t, d2, adj2);
  FOR(i, 1, k)
  {
    int u, v, w;  cin >> u >> v >> w;
    ll cur1 = d1[u] + w + d2[v];
    ll cur2 = d2[u] + w + d1[v];
//    cout << cur1 << ' ' << cur2 << endl;
    minimize(res, cur1);
    minimize(res, cur2);
  }
  if(res == 1e9) res = -1;
  cout << res << '\n';
  FOR(i, 1, n)
  {
    adj1[i].clear();
    adj2[i].clear();
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

    file("trafficn");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


