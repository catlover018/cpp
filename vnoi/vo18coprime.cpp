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

const int maxN = 1e5;
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

vector<int> prime = {2, 3, 5, 7, 11};
int BIT[50][maxN+5];
int n;
vector<int> pr[maxN+5];
ll a[maxN+5];
int dp[maxN+5];
int mark[maxN+5];

int get(int x, int BIT[])
{
  int res = 0;
  for(; x > 0; x -= (x&-x)) res = max(res, BIT[x]);
  return res;
}

void update(int x, int val, int BIT[])
{
  for(; x <= n; x += (x&-x)) BIT[x] = max(BIT[x], val);
}

void solve() {
  vector<ll> v;
  cin >> n;
  FOR(i, 1, n)
  {
    ll x; cin >> x;
    for(int c : prime)
    {
      if(x % c == 0) pr[i].pb(c);
    }
    a[i] = x;
    v.pb(x);
  }
  sort(all(v));
  RR(v);
  FOR(i, 1, n)
  {
    a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
  }
  int ans = 0;
  FOR(i, 1, n)
  {
    for(int c : prime) mark[c] = 0;
    for(int c : pr[i])
    {
      mark[c] = true;
    }
    int cur_mask = 0;
    for(int j = 0; j < 5; ++j)
    {
      if(mark[prime[j]])
      {
        cur_mask += (1 << j);
      }
    }
    for(int mask = 0; mask <= 31; ++mask)
    {
      if((mask & cur_mask) == 0)
      {
        maximize(dp[i], get(a[i] - 1, BIT[mask]) + 1);
      }
    }
    update(a[i], dp[i], BIT[cur_mask]);
    ans = max(ans, dp[i]);
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

    file("COPRIME");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


