#include <iostream>
#include <queue>
#include <math.h>

//#define int long long

using namespace std;
using ll = long long;

const int maxN = 3e5;

struct pack{
    int u, v, id;
    ll w;
    pack() {u = 0; v = 0; w = 0; id = 0;}
    pack(int _u, int _v, ll _w, int _id) {
        u = _u; v = _v;
        w = _w; id = _id;
    }
    bool operator < (const pack& o) const {
        return o.w < w;
    }
};

pack vertex[maxN + 5];
int par[maxN + 5], mark[maxN + 5];
priority_queue<pack> Q;
vector<int> MST;
ll cur_ans = 0;
int n, m;

void init() {
    for(int i = 1; i <= n; ++i) par[i] = i;
}

int Find(int u) {
    return (u == par[u] ? u : (par[u] = Find(par[u])));
}

bool Union(int u, int v) {
    u = Find(u);    v = Find(v);
    if(u == v) return false;
    par[u] = v;
    return true;
}


void Kosaraju() {
    while(!Q.empty()) {
        if(int(MST.size()) == n - 1) break;
        pack top = Q.top(); Q.pop();
        int x = top.u, y = top.v;
        if(Union(x, y)) {
            mark[top.id] = true;
            cur_ans += top.w;
            MST.push_back(top.id);
        }
    }
}

#define pii pair<int, ll>
#define fi first
#define se second

int h[maxN + 5], l[18][maxN + 5];
ll dis[18][maxN + 5];
int vst[maxN + 5];
vector<pii> adj[maxN];

void dfs(int u) {
    for(pii e : adj[u]) {
        int v = e.fi, w = e.se;
        if(v == l[0][u]) continue;
        h[v] = h[u] + 1;
        l[0][v] = u;
        dis[0][v] = w;
        for(int i = 1; i < 18; ++i) {
            l[i][v] = l[i - 1][l[i - 1][v]];
            dis[i][v] = max(dis[i - 1][v], dis[i - 1][l[i - 1][v]]);
        }
        dfs(v);
    }
}

#define bit(n, i) ((n >> i)&1)

ll lca(int u, int v) {
    ll ans = 0;
    if(h[u] != h[v]) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u] - h[v];
        for(int i = 0; (1 << i) <= k; ++i)
            if(bit(k, i)) ans = max(ans, dis[i][u]), u = l[i][u];
    }
    if(u == v) return ans;
    int k = log2(h[u]);
    for(int i = k; i >= 0; --i)
        if(l[i][u] != l[i][v]) {
            ans = max(ans, dis[i][u]);    u = l[i][u];
            ans = max(ans, dis[i][v]);    v = l[i][v];
        }
    ans = max(ans, dis[0][u]);    ans = max(ans, dis[0][v]);
    return ans;
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y, len;  cin >> x >> y >> len;
        vertex[i] = pack(x, y, len, i);
        Q.push(vertex[i]);
    }
}

void sol() {
    init();
    Kosaraju();
    for(int i : MST) {
        int x = vertex[i].u, y = vertex[i].v, len = vertex[i].w;
        adj[x].push_back({y, len});
        adj[y].push_back({x, len});
    }
    dfs(1);
    for(int i = 1; i <= m; ++i) {
        if(mark[i]) cout << cur_ans;
        else {
            int x = vertex[i].u, y = vertex[i].v, len = vertex[i].w;
            cout << cur_ans - lca(x, y) + len;
        } cout << '\n';
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
