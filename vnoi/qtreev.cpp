#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e5;

int n;
ll a[maxN + 5], m;
double d[maxN + 5];
vector<int> adj[maxN + 5];

ll mul(ll a, ll b) {
    if(b == 1) return a;
    ll tmp = mul(a, b / 2);
    tmp = (tmp + tmp) % m;
    if(b & 1) tmp = (tmp + a) % m;
    return tmp;
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i < n; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int trace[maxN + 5];

void dfs(int u, int p) {
    double mx = -1;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            if(mx < d[v]) {
                mx = d[v];
                trace[u] = v;
            }
        }
    }
    if(mx == -1) {
        d[u] = log10(a[u]);
    } else {
        d[u] = log10(a[u]) + mx;
    }
}

void sol() {
    dfs(1, 0);
    stack<int> S;   int i = 1;
//    for(int i = 1; i <= n; ++i) cout << trace[i] << " ";
    while(i) {
        S.push(i);
        i = trace[i];
    }
    ll ans = 1;
    while(!S.empty()) {
        ans = mul(a[S.top()], ans); S.pop();
    }
    cout << ans;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
