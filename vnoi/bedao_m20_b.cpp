#include <bits/stdc++.h>

#define int long long

#define mt make_tuple

using namespace std;

const int maxN = 1e6 + 5;

int T[maxN * 4 + 5], lz[maxN * 4 + 5];
int n, m;
vector<tuple<int, int, int>> query;

void read() {
    cin >> n >> m;
}

void push(int node, int l, int r) {
    int mid = (l + r) / 2;  int val = lz[node];
    if((mid - l + 1) % 2 != 0) T[node * 2] ^= val; lz[node * 2] ^= val;
    if((r - mid) % 2 != 0) T[node * 2 + 1] ^= val; lz[node * 2 + 1] ^= val;
    lz[node] = 0;
}

void update(int node, int l, int r, int u, int v, int val) {
    if(l > r || l > v || u > r) return;
    if(u <= l && r <= v) {
        if((r - l + 1) % 2 != 0) T[node] ^= val;
        lz[node] ^= val;
        return;
    }
    if(lz[node]) push(node, l, r);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = (T[node * 2] ^ T[node * 2 + 1]);
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return 0;
    if(u <= l && r <= v) return T[node];
    if(lz[node]) push(node, l, r);
    int mid = (l + r) / 2;
    int Left = get(node * 2, l, mid, u, v);
    int Right = get(node * 2 + 1, mid + 1, r, u, v);
    return (Left ^ Right);
}

void sol() {
    for(int i = 1; i <= m; ++i) {
        int type;   cin >> type;
        if(type == 1) {
            int u, v, val;  cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
            query.push_back(mt(u, v, val));
        } else {
            int u, v;   cin >> u >> v;
            cout << get(1, 1, n, u, v) << '\n';
            while(query.size() > 0) {
                auto [u, v, val] = query.back();    query.pop_back();
                update(1, 1, n, u, v, val);
            }
        }
    }
}

int32_t main() {

    read();
    sol();

    return 0;
}
