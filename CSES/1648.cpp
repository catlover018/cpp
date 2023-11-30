#include <iostream>

using namespace std;

typedef long long ll;

const int maxN = 1e6;

int n, a[maxN  + 5];
ll T[maxN * 4 + 5];

void init(int node, int l, int r) {
    if(l == r) {
        T[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = T[node * 2] + T[node * 2 + 1];
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
    T[node] = T[node * 2] + T[node * 2 + 1];
}

ll get(int node, int l, int r, int u, int v) {
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) {
        return T[node];
    }
    int mid = (l + r) / 2;
    ll Left = get(node * 2, l , mid, u, v);
    ll Right = get(node * 2 + 1, mid + 1, r, u, v);
    return Left + Right;
}

int query;

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

    cin.tie(0)->sync_with_stdio(0);

    read();

    return 0;
}
