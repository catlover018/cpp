#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;
const int inf = 1e12;

int a[maxN + 5];
vector<int> adj[maxN + 5];

int ans = 1e9, n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int dijkstra(int x) {
    queue<int> Q;   Q.push(1);
    vector<int> d(n + 1, inf);   d[1] = 1;
    while(!Q.empty()) {
        int u = Q.front();    Q.pop();
        for(int v : adj[u])
            if(x >= a[v] && d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
    }
    return d[n];
}

void sol() {
    if(dijkstra(inf) == inf) {
        cout << -1;
        return;
    }
    int l = a[1], r = inf, x = 0, y = inf;
    while(l <= r) {
        int mid = (l + r) / 2;
        int cur = dijkstra(mid);
        if(mid >= cur) {
            x = mid;    y = cur;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << x - y;
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
