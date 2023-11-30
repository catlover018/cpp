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

ll T[maxN*4+5], lz[maxN*4+5];
ll a[maxN+5];

struct query
{
    int l, r;
    ll x;
    query()
    {
        l = 0;
        r = 0;
        x = 0;
    }
    query(int _l, int _r, int _x)
    {
        l = _l;
        r = _r;
        x = _x;
    }
} Q[maxN+5];

void push(int node, int l, int r)
{
    ll &val = lz[node];
    int mid = (l + r) / 2;
    T[node * 2] += (mid - l + 1) * val;
    T[node * 2 + 1] += (r - mid) * val;
    lz[node * 2] += val;
    lz[node * 2 + 1] += val;
    val = 0;
}

void init(int node, int l, int r)
{
    if(l == r)
    {
        T[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node*2, l, mid);
    init(node*2+1, mid + 1, r);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

void update(int node, int l, int r, int u, int v, ll val)
{
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v)
    {
        T[node] += (r - l + 1) * val;
        lz[node] += val;
        return;
    }
    if(lz[node])
        push(node, l, r);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

ll get(int node, int l, int r, int u, int v)
{
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    if(lz[node])
        push(node, l, r);
    int mid = (l + r) / 2;
    return (get(node * 2, l, mid, u, v) +
            get(node * 2 + 1, mid + 1, r, u, v));
}

void solve() {
    int n, q;
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    init(1, 1, n);
    FOR(i, 1, q)
    {
        int type;   cin >> type;
        if(type == 1)
        {
            int l, r, x;   cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
            Q[i] = query(l, r, x);
        }
        else if(type == 2)
        {
            int id; cin >> id;
            auto [le, ri, val] = Q[id];
            update(1, 1, n, le, ri, -val);
            Q[i] = query(le, ri, -val);
        }
        else
        {
            int l, r;   cin >> l >> r;
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

    file("bedao_g11_easyquery");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

