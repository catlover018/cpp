#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;

struct edge {
    int u, v, w;
    edge() {u = 0; v = 0; w = 0;}
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const edge& o) const {
        return o.w < w;
    }
};

priority_queue<edge> Q;
int n;
int a[maxN + 5][maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;  cin >> x;
        Q.push(edge(n + 1, i, x));
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
}

int par[maxN + 5], sz[maxN + 5];

int Find(int u) {
    return (par[u] == u ? u : (par[u] = Find(par[u])));
}

bool Union(int u, int v) {
    u = Find(u);    v = Find(v);
    if(u == v) return false;
    if(sz[u] > sz[v]) swap(u, v);
    sz[v] += sz[u];
    par[u] = v;
    return true;
}

void sol() {
    for(int i = 1; i <= n + 1; ++i) {
        par[i] = i;
        sz[i] = i;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            Q.push(edge(i, j, a[i][j]));

    int MST_size = 0, res = 0;
    while(!Q.empty()) {
        auto [u, v, w] = Q.top();   Q.pop();
        if(Union(u, v)) {
            ++MST_size; res += w;
//            cout << u << " " << v << endl;
        }
        if(MST_size == n) break;
    }
    cout << res;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
