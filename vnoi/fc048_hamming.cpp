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
typedef unsigned long long ull;
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

vector<ull> hamming, pw2, pw3, pw5;

void build()
{
  ull lm = 1e18;
  ull i2 = 1;
  while(i2 <= lm)
  {
    pw2.pb(i2);
    i2 *= 2;
  }

  ull i3 = 1;
  while(i3 <= lm)
  {
    pw3.pb(i3);
    i3 *= 3;
  }

  ull i5 = 1;
  while(i5 <= lm)
  {
    pw5.pb(i5);
    i5 *= 5;
  }

  for(ull x2 : pw2)
  {
    for(ull x3 : pw3)
    {
      for(ull x5 : pw5)
      {
        ull cur = x2 * x3 * x5;
        if(cur < x2 || cur < x3 || cur < x5 || cur > lm)
        {
          continue;
        }
        hamming.pb(cur);
      }
    }
  }
}

void solve() {
  build();
  sort(all(hamming));
  int N;  cin >> N;
  while(N --> 0)
  {
    ull x;  cin >> x;
    int p = lower_bound(all(hamming), x) - hamming.begin();
    if(hamming[p] == x)
    {
      cout << p + 1 << '\n';
    }
    else
    {
      cout << "Not in sequence\n";
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

    file("fc048_hamming");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


