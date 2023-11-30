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

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

int N, M;
int a[maxN+5][maxN+5];
int R[maxN+5][maxN+5], C[maxN+5][maxN+5], dp[maxN+5][maxN+5];

void solve() {
    cin >> N >> M;
    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            cin >> a[i][j];
        }
    }
    FOR(i, 1, N) a[i][0] = 2;
    FOR(i, 1, M) a[0][i] = 2;
    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            if(a[i][j] == a[i][j - 1]) R[i][j] = R[i][j - 1] + 1;
            else R[i][j] = 1;
        }
    }
    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            if(a[i][j] == a[i - 1][j]) C[i][j] = C[i - 1][j] + 1;
            else C[i][j] = 1;
        }
    }
    int res = 0;
    FOR(i, 1, N)
    {
        FOR(j, 1, M)
        {
            if(a[i][j] == a[i - 1][j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                minimize(dp[i][j], R[i][j]);
                minimize(dp[i][j], C[i][j]);
            }
            else dp[i][j] = 1;
            maximize(res, dp[i][j]);
        }
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

    file("qbsquare");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}