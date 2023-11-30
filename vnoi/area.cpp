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

const int maxN = 30500;
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
  int x, y1, y2, type;
  event()
  {
    x = 0;
    y1 = 0;
    y2 = 0;
    type = 0;
  }
  event(int _x, int _y1, int _y2, int _type)
  {
    x = _x;
    y1 = _y1;
    y2 = _y2;
    type = _type;
  }
  bool operator < (const event& o) const
  {
    return (x == o.x ? o.type < type : x < o.x);
  }
};

struct rect
{
  int x, x2, y1, y2;
  rect()
  {
    x = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
  }
  rect(int _x, int _x2, int _y1, int _y2)
  {
    x = _x;
    x2 = _x2;
    y1 = _y1;
    y2 = _y2;
  }
};

vector<rect> R;
vector<event> seg;
pii T[maxN*4+5];

void update(int node, int l, int r, int u, int v, int val)
{
  if(l > r || u > r || l > v) return;
  if(u <= l && r <= v)
  {
    T[node].se += val;
    if(val == 1)
    {
      T[node].fi = r - l + 1;
    }
    else
    {
      if(T[node].se == 0)
      {
        if(l < r)
        {
          T[node].fi = T[node*2].fi + T[node*2+1].fi;

        }
        else
        {
          T[node].fi = 0;
        }
      }
    }
    return;
  }
  int mid = (l + r) / 2;
  update(node * 2, l, mid, u, v, val);
  update(node * 2 + 1, mid + 1, r, u, v, val);
  if(T[node].se == 0 && l < r)
    T[node].fi = T[node*2].fi + T[node*2+1].fi;
}

void solve() {
  int n;  cin >> n;
  seg.pb(event(-1e9, 0, 0, 0));
  FOR(i, 1, n)
  {
    int x, y, u, v; cin >> x>> y >> u >> v;
    R.pb(rect(x, u, y, v));
    seg.pb(event(x, y + 1, v, 1));
    seg.pb(event(u, y + 1, v, -1));
  }
  sort(all(seg));
  ll ans = 0;
  int lm = SZ(seg) - 1;
  for(int i = 1; i <= lm; ++i)
  {
    ans += T[1].fi * (seg[i].x - seg[i - 1].x);
    update(1, 1, maxN, seg[i].y1, seg[i].y2, seg[i].type);
  }
  cout << ans;
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


