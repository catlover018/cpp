// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define debug(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define bit(X, i) ((X >> i) & 1)
#define cntbit(X, i) __builtin_popcountll(X)
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

/*
1  2  9  10 25 26 49 50
4  3  8  11 24 27 48 51
5  6  7  12 23 28 47 52
16 15 14 13 22 29 46 53
17 18 19 20 21 30 45 54
36 35 34 33 32 31 44 55
37 38 39 40 41 42 43 56
64 63 62 61 60 59 58 57
*/

void testcase() {
    int x, y;   cin >> x >> y;
    int n = max(x, y);
    ll cur_val = 1ll*n*n;
    if(n % 2 == 0)
    {
        int bonus1 = y - 1, bonus2 = n - x;
        cur_val -= bonus1 + bonus2;
    }
    else
    {
        int bonus1 = n - y, bonus2 = x - 1;
        cur_val -= bonus1 + bonus2;
    }
    cout << cur_val << '\n';
}

void solve() {
    int N_test; cin >> N_test;

    while(N_test--)
        testcase();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
