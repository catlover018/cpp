#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxN = 1e3;

int n, m;
vector<pii> adj[maxN + 5];
int st, ed;

void read() {
    cin >> n >> m >> st >> ed;
    for(int i = 1; i <=  m; ++i) {
        int u, v, w;   cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

int vst[maxN + 5];
bool ok = false;

void check(int u, int len) {
    vst[u] = true;
    if(u == ed) {
        ok = true;
        return;
    }
    for(auto [v, w] : adj[u]) {
        if(!vst[v] && len <= w) check(v, len);
    }
}

//4 5 1 4
//1 2 10
//2 4 1
//1 3 5
//3 4 3
//1 4 4

void sol() {
    int ans = 0, l = 0, r = 1e4;
    while(l <= r) {
        int mid = (l + r) / 2;
        ok = false;
        check(st, mid); memset(vst, 0, sizeof(vst));
        if(ok == true) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
//        cout << mid << endl;
    }
    cout << ans;
}

int main() {

    freopen("TAITRONG.inp", "r", stdin);
    freopen("TAITRONG.out", "w", stdout);

    read();
    sol();

    return 0;
}
