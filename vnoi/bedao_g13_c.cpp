#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int inf = 1e9;

int a[maxN + 5], n, p[maxN + 5];
int par[maxN + 5], best[maxN + 5], Left[maxN + 5], Right[maxN + 5], sum[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) par[i] = i;
}

int find(int u) {
    return (u == par[u] ? u : (par[u] = find(par[u])));
}

int ans;

void Union(int u, int v) {
    u =  find(u);   v = find(v);
    if(u == v) return;
    if(v < u) swap(u, v);
    best[u] = max(Right[u] + Left[v], max(best[u], best[v]));
    Left[u] = max(Left[u], sum[u] + Left[v]);
    Right[u] = max(Right[v], sum[v] + Right[u]);
    sum[u] += sum[v];
    par[v] = u;
    ans = max(ans, best[u]);
}

int mark[maxN + 5];
stack<int> S;

void sol() {
    ans = -inf;
    for(int i = n; i > 0; --i) {
        int cur_p = p[i];
        best[cur_p] = a[cur_p];
        Left[cur_p] = a[cur_p];
        Right[cur_p] = a[cur_p];
        sum[cur_p] = a[cur_p];
        ans = max(ans, best[cur_p]);
        if(mark[cur_p - 1]) Union(cur_p, cur_p - 1);
        if(mark[cur_p + 1]) Union(cur_p, cur_p + 1);
        mark[cur_p] = 1;
        S.push(ans);
    }
    while(!S.empty()) {
        cout << S.top() << '\n';
        S.pop();
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
