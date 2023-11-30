#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

const int maxN = 1e5;

int T[maxN  * 4 + 5], lz[maxN * 4 + 5];
int n, query;
pii q[maxN];

#define fi first
#define se second

void push(int node) {
    T[node * 2] = lz[node]; T[node * 2 + 1] = lz[node];
    lz[node * 2] = lz[node];    lz[node * 2 + 1] = lz[node];
    lz[node] = 0;
}

void init(int node, int l, int r) {
    if(l == r) {
        T[node] = 0;
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2, mid + 1, r);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

void update(int node, int l, int r, int u, int v, int val) {
    if(l > r || l > v || u > r) return;
    if(u <= l && r <= v) {
        T[node] = val;
        lz[node] = val;
        return;
    }
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return 0;
    if(u <= l && r <= v) return T[node];
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    int Left = get(node * 2, l, mid, u, v);
    int Right = get(node * 2 + 1, mid + 1, r, u, v);
    T[node] = T[node * 2 + 1] + T[node * 2];
    return Left + Right;
}

void read() {
    cin >> n >> query;
    for(int i = 1; i <= query; ++i)
        cin >> q[i].fi >> q[i].se;
}

int a[maxN];

void sol() {
    init(1, 1, n);
    for(int i = 1; i <= query; ++i) {
        int r = q[i].fi, len = q[i].se;
        int _l = 1, _r = r, l = 0, t1 = 0, t2 = 0;
        while(_l <= _r) {
            int mid = (_l + _r) / 2;
            int cur_sum = get(1, 1, n, mid, r), mid_val = get(1, 1, n, mid, mid);
//            if(i == 2) cout << cur_sum << " " << mid_val << endl;
            int t = (r - mid + 1) * mid_val - cur_sum;
            if(t <= len) {
                l = mid;
                t1 = t;
                _r = mid - 1;
            } else _l = mid + 1;
        }
        if(t1 == 0) {
            t1 = len / (r - l + 1);
            int cur_val = get(1, 1, n, l, l);
            update(1, 1, n, l, r, cur_val + t1);
            t2 = len - t1 * (r - l + 1);
            int tmp = get(1, 1, n, 1, 1);   tmp = get(1, 1, n, n, n);
            update(1, 1, n, l, l + t2 - 1, cur_val + t1 + 1);
        } else {
            int cur_val = get(1, 1, n, l, l);
            update(1, 1, n, l, r, cur_val);
            int tmp = get(1, 1, n, 1, 1); tmp = get(1, 1, n, n, n);
            t2 = len - t1;
            update(1, 1, n, l, l + t2 - 1, cur_val + 1);
        }
    }
    for(int i = 1; i <= n; ++i) cout << get(1, 1, n, i, i) << " ";
}

int main() {

    freopen("test.inp", "r", stdin);

    read();
    sol();

    return 0;
}
