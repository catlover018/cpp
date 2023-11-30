#include <iostream>

using namespace std;

const int maxN = 1e6;
const int inf = 1e9 + 7;

int T[maxN * 4 + 5], a[maxN + 5], n, query;

void init(int node, int l, int r) {
    if(l == r) {
        T[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = min(T[node * 2], T[node * 2 + 1]);
}

void update(int node, int l, int r, int u, int v, int val) {
    if(l > r || l > v || u > r) return;
    if(u <= l && r <= v) {
        T[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = min(T[node * 2], T[node * 2 + 1]);
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return inf;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    int Left = get(node * 2, l , mid, u, v);
    int Right = get(node * 2 + 1, mid + 1, r, u, v);
    return min(Left, Right);
}

void read() {
    cin >> n >> query;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    init(1, 1, n);
    while(query--) {
        int type, u, v; cin >> type >> u >> v;
        if(type == 1) {
            update(1, 1, n, u, u, v);
        } else {
            cout << get(1, 1, n, u, v) << '\n';
        }
    }
}

int main() {

    read();

    return 0;
}
