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
template<int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template<typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T> (args...)) {}
};

template<typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : vector<T> (n, val) {}
};

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll Rand(ll l, ll r) { return l + rand() % (r - l + 1); }

const int maxN = 1e6;
const ll inf = 1e18+7;
const int MOD = 123456789;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

vector<int> adj[maxN+5];

void solve() {
    int n, m, k;    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    vector<int> mask;
    FOR(i, 0, (1<<n)-1)
    {
        if(i & (i >> 1)) continue;
        if(i & (i << 1)) continue;
        mask.pb(i);
    }
    for(int i = 0; i < SZ(mask); ++i)
    {
        int x = mask[i];
        for(int j = 0; j < SZ(mask); ++j)
        {
            int y = mask[j];
            if(x & y) continue;
            if(x & (y >> 1)) continue;
            if(x & (y << 1)) continue;
            adj[i].pb(j);
        }
    }
    Vec<3, ll> dp(m + 1, k + 20, SZ(mask));
    dp[0][0][0] = 1;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            for(int id1 = 0; id1 < SZ(mask); ++id1)
            {
                ll pre = dp[i][j][id1];
                if(pre == 0) continue;
                for(int id2 : adj[id1])
                {
                    int cur = j + cntbit(mask[id2]);
                    if(cur > k) continue;
                    dp[i+1][cur][id2] += pre;
                    dp[i+1][cur][id2] %= MOD;
                }
            }
        }
    }
    ll res = 0;
    FOR(i, 0, SZ(mask) - 1)
    {
        res += dp[m][k][i];
        res %= MOD;
    }
    cout << res;
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

    file("icpc23_mb_d");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

