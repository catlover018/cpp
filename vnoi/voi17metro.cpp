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

struct metro
{
  int u; ll len; int id;
  metro() = default;
  metro(int _u, ll _len, int _id)
  {
    u = _u;
    len = _len;
    id = _id;
  }
  bool operator < (const metro &o) const
  {
    return o.len < len;
  }
};

typedef pair<int, pii> piii;

vector<piii> adj[maxN+5];
int N, M, st,ed, landa;

void solve() {
  cin >> N >> M >> st >> ed >> landa;
  FOR(i, 1, M)
  {
    int u, v, w;  cin >> u >> v >> w;
    adj[u].pb({v, {w, i}});
  }

  // dijkstra
  priority_queue<metro> Q;
  vector<ll> d(N + 1, inf);
  d[st] = 0;
  Q.push(metro(st, d[st], 0));
  while(!Q.empty())
  {
    auto [u, len, id] = Q.top();  Q.pop();
    if(len > d[u]) continue;
    for(piii e : adj[u])
    {
      int v = e.fi, w = e.se.fi, ind = e.se.se;
      ll dis = d[u] + w;
      if(u != st) dis += (id * landa + ind);
      if(dis < d[v])
      {
        d[v] = dis;
        Q.push(metro(v, d[v], ind));
      }
    }
  }
  if(d[ed] == inf) d[ed] = -1;
  cout << d[ed];
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

    file("voi17metro");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


