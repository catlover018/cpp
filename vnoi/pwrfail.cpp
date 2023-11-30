#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;
const double inf = 1e9;
const double eps = 0.000001;

int n, W, mark[maxN];
double m;

#define pid pair<double, int>
#define fi first
#define se second

pair<int, int> a[maxN + 5];
vector<pid> adj[maxN + 5];

double sqr(double x) {
    return x * x;
}

double cal(int i, int j) {
    return sqrt(sqr(a[i].fi - a[j].fi) + sqr(a[i].se - a[j].se));
}

void dijkstra(int u) {
    vector<double> d(n + 1, inf);
    priority_queue<pid, vector<pid>, greater<pid>> Q;
    d[u] = 0;   Q.push({0, u});
    while(!Q.empty()) {
        pid top = Q.top();  Q.pop();
        int u = top.se; double len = top.fi;
        if(u == n) break;
        if(len - d[u] > eps) continue;
        for(pid e : adj[u]) {
            int v = e.se;   double w = e.fi;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                Q.push({d[v], v});
            }
        }
    }
    int ans = -1;
    if(d[n] < 1e9) ans = d[n] * 1000;
    cout << ans;
}


void read() {
    cin >> n >> W >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;

    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j) {
            double cost = cal(i, j);
            if(cost - m > eps) cost = inf;
            adj[i].push_back({cost, j});
            adj[j].push_back({cost, i});
        }

    for(int i = 1; i <= W; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back({0, v});
        adj[v].push_back({0, u});
    }
}

void sol() {
    dijkstra(1);
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}

