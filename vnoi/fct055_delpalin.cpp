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

const int maxN = 1e3;
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

string s;
int n;
ll dp[maxN+5][maxN+5];

ll calc(int i, int j)
{
    if(i >= j) return 1;

    if(dp[i][j] != inf) return dp[i][j];

    ll res = inf;
    if(s[i] == s[j])
    {
        res = calc(i + 1, j - 1);
    }

    FOR(k, i, j - 1)
    {
        res = min(res, calc(i, k) + calc(k + 1, j));
    }

    return dp[i][j] = res;
}

void solve() {

    int testcase;   cin >> testcase;

    while(testcase--)
    {
        cin >> s;
        n = SZ(s);  s = ' ' + s;
        FOR(i, 1, n)    FOR(j, 1, n)
            dp[i][j] = inf;
        cout << calc(1, n) << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("fct055_delpalin");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

