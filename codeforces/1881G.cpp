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
const int lm = 26;

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

int BIT[maxN+5];
set<int> w2, w3;
int n, Q;
string s;

void update(int x, int val)
{
  for(; x <= n; x += (x&-x))
  {
    BIT[x] = (BIT[x] + val + lm) % lm;
  }
}

int get(int x)
{
  int res = 0;
  for(; x > 0; x -= (x&-x))
  {
    res += BIT[x];
    res %= lm;
  }
  return res;
}

void updateSet(int l, int r)
{
  l = max(1, l);
  r = min(r, n);
  FOR(i, l, r)
  {
    if(i + 1 <= r)
    {
      int cur1 = get(i), cur2 = get(i + 1);
      if(cur1 == cur2) w2.insert(i);
      else w2.erase(i);
    }
    if(i + 2 <= r)
    {
      int cur1 = get(i), cur2 = get(i + 2);
      if(cur1 == cur2) w3.insert(i);
      else w3.erase(i);
    }
  }
}

void updateQ(int l, int r, int x)
{
  update(l, x);
  updateSet(l - 5, l + 5);
  update(r + 1, lm - x);
  updateSet(r - 5, r + 5);
}

void solve() {

  // read input
  cin >> n >> Q;
  cin >> s;
  s = ' ' + s;

  // reset
  w2.clear();
  w3.clear();
  FOR(i, 0, n + 1)
  {
    BIT[i] = 0;
  }

  // before solving queries
  update(1, s[1] - 'a');
  FOR(i, 2, n)
  {
    update(i, s[i] - s[i - 1] + lm);
  }
  FOR(i, 1, n)
  {
    if(i + 1 <= n)
    {
      if(s[i] == s[i + 1])
        w2.insert(i);
    }
    if(i + 2 <= n)
    {
      if(s[i] == s[i + 2])
        w3.insert(i);
    }
  }

  // solving queries
  while(Q --> 0)
  {
    int type; cin >> type;
    if(type == 1)
    {
      int l, r, x;  cin >> l >> r >> x;
      x %= lm;
      updateQ(l, r, x);
    }
    else
    {
      int l, r; cin >> l >> r;
      auto p = w2.lower_bound(l);
      if(p != w2.end() && *p + 1 <= r)
      {
        cout << "NO\n";
        continue;
      }
      p = w3.lower_bound(l);
      if(p != w3.end() && *p + 2 <= r)
      {
        cout << "NO\n";
        continue;
      }
      cout << "YES\n";
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

    file("1881G");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

