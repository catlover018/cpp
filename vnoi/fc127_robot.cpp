#include <bits/stdc++.h>

//#define int long long

using namespace std;

const int maxN = 1e3 + 5;

int n, m;
vector<vector<int>> a;
long long k;

void read() {
    cin >> n >> m;
    a.resize(n + 1);
    for(int i = 1; i <= n; ++i) a[i].resize(m + 1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
}

vector<pair<int, int>> topo;
#define fi first
#define se second

const pair<int, int> mv[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int vst[maxN][maxN];
int last_x, last_y;
void dfs(int u, int v) {
    if(u < 1 || v < 1 || u > n || v > m) return;
    vst[u][v] = true;
    if(a[u][v] == 0 && !vst[u - 1][v] && u > 1) dfs(u - 1, v);
    else if(a[u][v] == 0 && vst[u - 1][v]) last_x = u - 1, last_y = v;
    if(a[u][v] == 1 && !vst[u + 1][v] && u < n) dfs(u + 1, v);
    else if(a[u][v] == 1 && vst[u + 1][v]) last_x = u + 1, last_y = v;
    if(a[u][v] == 2 && !vst[u][v - 1] && v > 1) dfs(u, v - 1);
    else if(a[u][v] == 2 && vst[u][v - 1]) last_x = u, last_y = v - 1;
    if(a[u][v] == 3 && !vst[u][v + 1] && v < m) dfs(u, v + 1);
    else if(a[u][v] == 3 && vst[u][v + 1]) last_x = u, last_y = v + 1;
    topo.push_back({u, v});
}

//3 2
//1 2
//3 1
//0 2

pair<int, int> sub1(int u, int v, int k) {
    if(u > n) return {u - 1, v};
    if(u < 1) return {u + 1, v};
    if(v > m) return {u, v - 1};
    if(v < 1) return {u, v + 1};
    if(k == 0) return {u, v};
    if(a[u][v] == 0 && !vst[u - 1][v]) return sub1(u - 1, v, k - 1);
    if(a[u][v] == 1 && !vst[u + 1][v]) return sub1(u + 1, v, k - 1);
    if(a[u][v] == 2 && !vst[u][v - 1]) return sub1(u, v - 1, k - 1);
    if(a[u][v] == 3 && !vst[u][v + 1]) return sub1(u, v + 1, k - 1);
    return {0, 0};
}

vector<pair<int, int>> vi;

void sol() {
    cin >> k;
    if(k <= 100 * 105) {
        pair<int, int> pi = sub1(1, 1, k);
        cout << pi.fi << " " << pi.se;
        return;
    }
    dfs(1, 1);  int cnt = 0;
    if(last_x == 0 && last_y == 0) {
        if(k >= (int)topo.size()) {
            cout << topo[0].fi << " " << topo[0].se;
            return;
        } else {
            while(!topo.empty()) {
            if(k == 0) {
                cout << topo.back().fi << " " << topo.back().se;
                return;
            }
            --k;    topo.pop_back();
            }
        }
    }
    while(!topo.empty()) {
        auto top = topo.back();
        int u = top.fi, v = top.se; vi.push_back({u, v});
        if(u == last_x && v == last_y) break;
        ++cnt;  topo.pop_back();
    }
    n = topo.size();
    if(n == 1) {
        cout << 1 << " " << 1;
        return;
    }
    reverse(topo.begin(), topo.end());
    k = (k - cnt) % n;
    cout << topo[k].fi << " " << topo[k].se;
}

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    sol();

    return 0;
}
