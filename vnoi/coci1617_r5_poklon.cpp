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

struct event
{
    int l, r, type;
    event()
    {
        l = 0;
        r = 0;
        type = 0;
    }
    event(int _l, int _r, int _type)
    {
        l = _l;
        r = _r;
        type = _type;
    }
    bool operator < (const event& o) const
    {
        return (o.r == r ? type < o.type : r < o.r);
    }
};

int h[maxN+5];
ll BIT[maxN+5];

void update(int x, int k)
{
    for(; x < maxN; x += (x&-x)) BIT[x] += k;
}

ll get(int x)
{
    ll res = 0;
    for(; x > 0; x -= (x&-x)) res += BIT[x];
    return res;
}

ll res[maxN+5];
int last[maxN+5], lastx2[maxN+5], lastx3[maxN+5];

void solve() {

    //read input
    int n, Q;  cin >> n >> Q;
    vector<int> v;
    FOR(i, 1, n)
    {
        cin >> h[i];
        v.pb(h[i]);
    }
    sort(all(v));
    RR(v);
    vector<event> d;
    FOR(i, 1, n)
    {
        int cur = lower_bound(all(v), h[i]) - v.begin() + 1;
        d.pb(event(cur, i, -1));
    }
    FOR(i, 1, Q)
    {
        int l, r;   cin >> l >> r;
        d.pb(event(l, r, i));
    }

    //solving query
    sort(all(d));

    for(auto [l, r, id] : d)
    {
        if(id == -1)
        {
            int &x1 = last[l];
            int &x2 = lastx2[l];
            int &x3 = lastx3[l];
            if(x1) update(x1, 1);
            if(x2) update(x2, -2);
            if(x3) update(x3, 1);
            x3 = x2;
            x2 = x1;
            x1 = r;
        }
        else
        {
            res[id] = get(r) - get(l - 1);
        }
    }

    FOR(i, 1, Q)
    {
        cout << res[i] << '\n';
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

    file("coci1617_r5_poklon");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
