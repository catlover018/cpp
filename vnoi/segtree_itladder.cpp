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
const ll MOD = 1e9 + 7;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

ll T[maxN+5], lz1[maxN*4+5], lz2[maxN*4+5];
int n, q;

ll calc(int l, int r)
{
  return 1ll * (r + l) * (r - l + 1) / 2;
}

void add(ll &a, ll b)
{
  a += b;
  a %= MOD;
}

void push(int node, int type, int l, int r)
{
  int mid = (l + r)/2;
  if(type == 1)
  {
    ll &x = lz1[node];
    add(lz1[node*2], x);
    add(lz1[node*2+1], x);
    add(T[node*2], 1ll * ((mid - l + 1) * x) % MOD);
    add(T[node*2+1], 1ll * ((r - mid) * x) % MOD);
    x = 0;
  }
  else
  {
    ll &x = lz2[node];
    add(lz2[node*2], x);
    add(lz2[node*2+1], x);
    add(T[node*2], (x * calc(l, mid) + MOD*MOD)%MOD);
    add(T[node*2+1], (x * calc(mid + 1, r) + MOD*MOD)%MOD);
    x = 0;
  }
}

void update(int node, int l, int r, int u, int v, ll val1, ll val2)
{
//  cout << l << ' '<< r << endl;
  if(l > r || u > r || l > v) return;
  if(u <= l && r <= v)
  {
    ll cur2 = (val2 * calc(l, r)+ MOD * MOD) % MOD;
    ll cur1 = val1 * (r - l + 1) % MOD;
//    cur1 = 0;
//    cout << T[node] << ' ' << cur1 << ' ' << cur2 << endl;
    T[node] = T[node] + cur1 + cur2; T[node] %= MOD;
    lz1[node] += val1;  lz1[node] %= MOD;
    lz2[node] += val2;  lz2[node] %= MOD;
    return;
  }
  if(lz1[node]) push(node, 1, l, r);
  if(lz2[node]) push(node, 2, l, r);
  int mid = (l + r) / 2;
  update(node*2, l, mid, u, v, val1, val2);
  update(node*2+1, mid + 1, r, u, v, val1, val2);
  T[node] = (T[node*2] + T[node*2+1]) % MOD;
}

ll get(int node, int l, int r, int u, int v)
{
  if(l > r || u > r || l > v) return 0;
  if(u <= l && r <= v) return T[node];
  if(lz1[node]) push(node, 1, l, r);
  if(lz2[node]) push(node, 2, l, r);
  int mid = (l + r)/2;
  ll Left = get(node*2, l, mid, u, v);
  ll Right = get(node*2+1, mid + 1, r, u, v);
//  cout << Left << " " << Right << endl;
  return (Left + Right) % MOD;
}

void solve() {
  cin >> n >> q;
  while(q--)
  {
    int type; cin >> type;
    if(type == 1)
    {
      ll l, r, a, b; cin >> l >> r >> a >> b;
      update(1, 1, n, l, r, (b - l*a + MOD * MOD)%MOD, a);
    }
    else
    {
      int l, r; cin >> l >> r;
      cout << get(1, 1, n, l, r) << '\n';
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

    file("segtree_itladder");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


