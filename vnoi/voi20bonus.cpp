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

const int maxN = 300;
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

int n, k;
int a[maxN+5];
ll dp[maxN+5][maxN+5][maxN/2+5];


ll calc(int i, int j, int k) {
    if(i > j)
    {
        if(!k) return 0;
        return -inf;
    }

    if(dp[i][j][k] != -1) return dp[i][j][k];

    ll res = max(calc(i + 1, j, k), calc(i, j - 1, k));

    if(i < j)
    {
        res = max(res, calc(i + 2, j, k - 1) + abs(a[i] - a[i+1]));
        res = max(res, calc(i, j - 2, k - 1) + abs(a[j] - a[j-1]));
        res = max(res, calc(i + 1, j - 1, k - 1) + abs(a[i] - a[j]));
    }

    return dp[i][j][k] = res;
}

void solve() {
    cin >> n >> k;
    FOR(i, 1, n)
    {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << calc(1, n, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
