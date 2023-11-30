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

const int maxN = 2e3;
const ll inf = 1e18+7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);
const pii mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

int n, m;
ll a[maxN+5][maxN+5], d[maxN+5][maxN+5], vst[maxN+5][maxN+5];
vector<pii> holes;

bool inside(int x, int y)
{
  return (x > 0 && y > 0 && x <= n && y <= m);
}

bool bfs(ll len)
{
  FOR(i, 0, n + 1)
  FOR(j, 0, m + 1)
  {
    vst[i][j] = false;
  }
  int st_x = holes[0].fi, st_y = holes[0].se;
  queue<pii> Q;
  Q.push({st_x, st_y});
  vst[st_x][st_y] = true;
  while(!Q.empty())
  {
    auto [x, y] = Q.front();  Q.pop();
    REP(i, 4)
    {
      int new_x = x + mv[i].fi,
          new_y = y + mv[i].se;
      if(vst[new_x][new_y] || !inside(new_x, new_y)) continue;
      ll cur_dis = abs(a[new_x][new_y] - a[x][y]);
      if(cur_dis > len)
      {
        continue;
      }
      Q.push({new_x, new_y});
      vst[new_x][new_y] = true;
    }
  }
  for(pii e : holes)
    if(!vst[e.fi][e.se]) return false;
  return true;
}

void solve() {
  cin >> n >> m;
  FOR(i, 1, n)  FOR(j, 1, m)
    cin >> a[i][j];
  FOR(i, 1, n)  FOR(j, 1, m)
  {
    cin >> d[i][j];
    if(d[i][j]) holes.pb({i, j});
  }
  ll ans = -1, le = 0, ri = 1e10;
  while(le <= ri)
  {
    ll mid = (le + ri) / 2;
    if(bfs(mid))
    {
      ans = mid;
      ri = mid - 1;
    }
    else le = mid + 1;
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

    file("GOLF");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


