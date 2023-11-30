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
#define mp make_pair
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

int n, m;
vector<pii> adj[maxN+5];
pii a[maxN+5];
int in_stack[maxN+5], vst[maxN+5], mark[maxN+5];
bool is_Cycle = false;
stack<int> S;

void dfs1(int u)
{
    in_stack[u] = vst[u] = true;
    if(is_Cycle) return;
    for(auto [v, id] : adj[u])
    {
        if(is_Cycle) return;
        S.push(id);
        if(in_stack[v])
        {
            is_Cycle = 1;
            return;
        }
        if(!vst[v])
        {
            dfs1(v);
        }
        if(is_Cycle) return;
        S.pop();
    }
    if(is_Cycle) return;
    in_stack[u] = false;
}

void dfs2(int u)
{
    in_stack[u] = vst[u] = true;
    if(is_Cycle) return;
    for(auto [v, id] : adj[u])
    {
        if(is_Cycle) return;
        if(mark[id]) continue;
        if(in_stack[v])
        {
            is_Cycle = 1;
            return;
        }
        if(!vst[v])
        {
            dfs2(v);
        }
    }
    if(is_Cycle) return;
    in_stack[u] = false;
}

void solve() {
    cin >> n >> m;
    FOR(i, 1, m)
    {
        cin >> a[i].fi >> a[i].se;
        adj[a[i].fi].pb(mp(a[i].se, i));
    }
    is_Cycle = false;
    FOR(i, 1, n)    if(!vst[i])
    {
        dfs1(i);
        if(is_Cycle) break;
    }
    vector<pii> ans;
    while(S.size() > 0)
    {
        int id = S.top();   S.pop();
        mark[id] = true;
        is_Cycle = false;
        FOR(i, 1, n)
        {
            vst[i] = false;
            in_stack[i] = false;
        }
        bool ok = true;
        FOR(i, 1, n) if(!vst[i])
        {
            dfs2(i);
            if(is_Cycle)
            {
                ok = false;
                break;
            }
        }
        if(ok) ans.pb(a[id]);
        mark[id] = false;
    }
    if(!SZ(ans))
    {
        cout << -1;
    }
    else
    {
        cout << SZ(ans) << '\n';
        sort(all(ans));
        EACH(it, ans)
        {
            cout << (it -> fi) << " " << (it -> se) << '\n';
        }
    }
}

/*
6 7
1 2
2 3
3 4
4 5
5 6
6 1
2 5
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("qbcirarc");

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}
