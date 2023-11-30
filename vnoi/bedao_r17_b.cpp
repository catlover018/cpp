// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
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

ll n;
ll p[maxN+5];
vector<ll> prime, prime3;

void sieve()
{
    p[1] = 1;
    for(int i = 1; i * i < maxN; ++i)
        if(!p[i]) for(int j = i * i; j < maxN; j += i)
            p[j] = 1;
    for(int i = 1; i < maxN; ++i) {
        if(!p[i])
        {
            prime.pb(i);
            prime3.pb(1ll*i*i*i);
        }
    }
}

void solve() {
    sieve();
    ll n;   cin >> n;
    ll ans = 0;
    for(int i = 0; i < SZ(prime3); ++i)
    {
        ll x = prime3[i];
        ll tmp = n / x;
        if(tmp == 0) break;
        int p = lower_bound(prime3.begin() + i, prime3.end(), tmp) - prime3.begin();
            if(tmp != prime3[p]) --p;
        if(p >= i && p < SZ(prime3))
        {
            ans += p - i;
        }
    }
    cout << ans;
}

void solve_TestCase()
{
    int TestCase;   cin >> TestCase;

    while(TestCase--)
    {
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

