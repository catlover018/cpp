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

int T[26][maxN*4+5];
char c[maxN+5];

void update(int node, int l, int r, int p, int T[], int val)
{
    if(l > r || p > r || l > p) return;
    if(l == r && r == p)
    {
      T[node] += val;
      return;
    }
    int mid = (l + r) / 2;
    if(p <= mid) update(node*2, l, mid, p, T, val);
    else update(node*2+1, mid + 1, r ,p , T, val);
    T[node] = (T[node*2]|T[node*2+1]);
}

int get(int node, int l, int r, int u, int v, int T[])
{
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    return (get(node*2, l, mid, u, v, T) | get(node*2+1, mid+1, r, u, v, T));
}

void solve() {
  int n;  cin >> n;
  FOR(i, 1, n)
  {
    cin >> c[i];
    update(1, 1, n, i, T[c[i] - 'a'], 1);
  }
  int Q;  cin >> Q;
  while(Q --> 0)
  {
    int type; cin >> type;
    if(type == 1)
    {
      int i;  char ch; cin >> i >> ch;
      update(1, 1, n, i, T[c[i] - 'a'], -1);
      c[i] = ch;
      update(1, 1, n, i, T[c[i] - 'a'], 1);
    }
    else
    {
      int res = 0, l,  r; cin >> l >> r;
      FOR(i, 0, 25)
      {
        res += get(1, 1, n, l, r, T[i]);
      }
      cout << res << '\n';
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

    file("fc133_charcnt");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


