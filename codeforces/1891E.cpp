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

void solve() {
  int N, k;  cin >> N >> k;
  vector<int> a(N);
  vector<int> cnt(N + 1);
  for(int &x : a) cin >> x;
  int res = 0;
  FOR(i, 0, N - 2)
    if(a[i] == 1 || a[i + 1] == 1) ++res;
  bool ok = true;
  FOR(i, 0, N - 1)
  {
    if(a[i] == 1)
    {
      int j = i;
      while(a[j] == 1 && j < N) ++j;
      if(i != 0 && j != N) ++cnt[j - i];
      i = j - 1;
    }
    else
    {
      int j = i;
      ok = false;
      while(j < N - 1 && a[j + 1] != 1 && __gcd(a[j], a[j + 1]) == 1) ++j;
      res += (j - i);
      cnt[1] += (j - i) / 2;
      i = j;
    }
  }
  if(!ok)
  {
    res -= k;
    FOR(i, 1, N)
      while(k >= i && cnt[i])
      {
        k -= i;
        --cnt[i];
        --res;
      }
    cout << max(res, 0) << '\n';
  }
  else
  {
    cout << N - k << '\n';
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

    file("template");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


