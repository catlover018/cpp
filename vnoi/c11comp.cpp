#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;
const int BLOCK = 450;

int col[maxN + 5], id[(maxN << 1)+ 5];
int tin[maxN + 5], tout[maxN + 5];
vector<int> adj[maxN + 5];
int n, m, k;

struct edge {
    int l, r;
    edge() {l = 0; r = 0;}
    edge(int _l, int _r) {
        l = _l; r = _r;
    }
    bool operator < (const edge& o) const {
        return (l/BLOCK == o.l/BLOCK ? r < o.r : l < o.l);
    }
};

void read() {
    cin >> n >> m >> k;
    for(int i = 2; i <= n; ++i) {
        int x;  cin >> x;
        adj[x].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> col[i];
}

int Time = 0, cnt[maxN + 5], ans = 0;
edge d[maxN + 5];

void dfs(int u) {
    tin[u] = ++Time;
    id[tin[u]] = u;
    for(int v : adj[u]) {
        dfs(v);
    }
    tout[u] = ++Time;
    d[u] = edge(tin[u], tout[u]);
}

void add(int x) {
    int cur_col = col[id[x]];
    ans += (cnt[cur_col] == 0);
    ans -= (cnt[cur_col] == k);
    ++cnt[cur_col];
}

void rem(int x) {
    int cur_col = col[id[x]];
    --cnt[cur_col];
    ans -= (cnt[cur_col] == 0);
    ans += (cnt[cur_col] == k);
}

int res[maxN + 5];

void sol() {
    dfs(1);
    sort(d + 1, d + n + 1);
    cnt[0] = 1e9;
    for(int i = 1, l = 1, r = 0; i <= n; ++i) {
        auto [cur_l, cur_r] = d[i];
        while(r < cur_r) ++r, add(r);
        while(l < cur_l) rem(l), ++l;
        while(r > cur_r) rem(r), --r;
        while(l > cur_l) --l, add(l);
        res[id[cur_l]] = ans;
    }
    int query;  cin >> query;
    while(query--) {
        int u;  cin >> u;
        cout << res[u] << '\n';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
