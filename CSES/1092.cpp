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

void solve() {
    ll n;  cin >> n;
    vector<int> c1, c2;
    if((n * (n + 1) / 2) % 2 != 0)
    {
        cout << "NO\n";
        return;
    }
    if(n & 1)
    {
        for(int i = 1, j = n - 1; i*2 <= n;) {
            c1.pb(i);
            c1.pb(j);
            i += 2;
            j -= 2;
        }
        c2.pb(n);
        for(int i = 2, j = n - 2; i*2 <= n;) {
            c2.pb(i);
            c2.pb(j);
            i += 2;
            j -= 2;
        }
    }
    else
    {
        for(int i = 1, j = n; i*2 <= n;) {
            c1.pb(i);
            c1.pb(j);
            i += 2;
            j -= 2;
        }
        for(int i = 2, j = n - 1; i*2 <= n;) {
            c2.pb(i);
            c2.pb(j);
            i += 2;
            j -= 2;
        }
    }
    cout << "YES\n";
    sort(all(c1));  sort(all(c2));
    cout << SZ(c1) << '\n';
    EACH(x, c1) cout << *x << " ";  cout << '\n';
    cout << SZ(c2) << '\n';
    EACH(x, c2) cout << *x << " ";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

