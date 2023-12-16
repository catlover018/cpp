// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define int long long

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

int N;
int tin[maxN+5], tout[maxN+5], Time = 0;
vector<int> adj[maxN+5];

///////////////////////////
/**
  EULER TOUR
**/
void dfs(int u, int p)
{
  tin[u] = ++Time;
  for(int v : adj[u])
  {
    if(v != p)
    {
      dfs(v, u);
    }
  }
  tout[u] = Time;
}

////////////////////////////
/**
  SEGMENT TREE
**/
int T[maxN*4+5], lz[maxN*4+5];

void push(int node)
{
  int &x = lz[node];
  T[node * 2] = x;
  T[node * 2 + 1] = x;
  lz[node * 2] = x;
  lz[node *2 + 1] = x;
  lz[node] = -1;
}

void init(int node, int l, int r)
{
  if(l == r)
  {
    T[node] = 1;
    lz[node] = -1;
    return;
  }
  else
  {
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    lz[node] = -1;
    T[node] = max(T[node * 2], T[node * 2 + 1]);
  }
}

int get(int node, int l, int r, int u, int v)
{
  if(l > r || u > r || l > v) return -1;
  if(u <= l && r <= v) return T[node];
  int mid = (l + r) / 2;
  if(lz[node] != -1) push(node);
  return max(get(node * 2, l, mid, u, v),
             get(node * 2 + 1, mid + 1, r, u, v));
}

void update(int node, int l, int r, int u, int v, int val)
{
  if(l > r || u > r || l > v) return;
  if(u <= l && r <= v)
  {
    T[node] = val;
    lz[node] = val;
  }
  else
  {
    int mid = (l + r) / 2;
    if(lz[node] != -1) push(node);
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
  }
}

void solve() {
  cin >> N;
  FOR(i, 1, N - 1)
  {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 0);

  init(1, 1, Time);

  int M;  cin >> M;
  while(M--)
  {
    int type, u;  cin >> type >> u;
    if(type == 1)
    {
      update(1, 1, Time, tin[u], tout[u], 0);
//      FOR(i, 1, 2 * Time) cout << T[i] << ' ';
//      cout << endl;
    }
    else if(type == 2)
    {
      update(1, 1, Time, tin[u], tin[u], 1);
//      FOR(i, 1, 2 * Time) cout << T[i] << ' ';
//      cout << endl;
    }
    else
    {
      int cur = get(1, 1, Time, tin[u], tout[u]);
      cout << !cur << '\n';
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

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("343D");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


