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

struct dt {
    int u, v, d;
    dt() {u = 0; v = 0; d = 0;}
    dt(int _u, int _v, int _d)
    {
        u = _u;
        v = _v;
        d = _d;
    }
};

int mark[maxN+5][maxN+5];
int vst[maxN+5][maxN+5];
int n, m, p, q, s, t;
queue<dt> Q;

int cal(int k1, int k2, int u, int v, int cur_dis)
{
    if(!mark[u + k1][v + k2])
    {
        if(!vst[u + k1][v + k2])
        {
            Q.push(dt(u + k1, v + k2, cur_dis + 1));
            vst[u + k1][v + k2] = true;
            if(u + k1 == s && v + k2 == t) return cur_dis + 1;
            return 0;
        }
        return 0;
    }
    return -1;
}

void solve() {

    cin >> n >> m >> p >> q >> s >> t;

    FOR(i, 1, m)
    {
        int u, v;   cin >> u >> v;
        mark[u][v] = true;
    }

    Q.push({p, q, 0});
    vst[p][q] = true;

    while(!Q.empty())
    {
        auto [u, v, cur_dis] = Q.front();   Q.pop();

        for(int i = 1; u + i <= n && v + i <= n; ++i)
        {
            int cur = cal(i, i, u, v, cur_dis);
            if(cur > 0)
            {
                cout << cur << '\n';
                return;
            } else if(cur < 0) break;
        }

        for(int i = 1; u + i <= n && v - i >= 1; ++i)
        {
            int cur = cal(i, -i, u, v, cur_dis);
            if(cur > 0)
            {
                cout << cur << '\n';
                return;
            } else if(cur < 0) break;
        }

        for(int i = 1; u - i >= 1 && v + i <= n; ++i)
        {
            int cur = cal(-i, i, u, v, cur_dis);
            if(cur > 0)
            {
                cout << cur << '\n';
                return;
            } else if(cur < 0) break;
        }

        for(int i = 1; u - i >= 1 && v - i >= 1; ++i)
        {
            int cur = cal(-i, -i, u, v, cur_dis);
            if(cur > 0)
            {
                cout << cur << '\n';
                return;
            } else if(cur < 0) break;
        }
    }
    cout << -1;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("template");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
