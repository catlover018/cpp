#include <iostream>

using namespace std;

const int maxN = 1e6;

struct Node {
    int val, pos;
    Node() {val = 0; pos = 0;}
    Node(int _val, int _pos) {
        val = _val;
        pos = _pos;
    }
};

int n, m, a[maxN + 5], h[maxN + 5];
Node T[maxN * 4 + 5];

void init(int node, int l, int r) {
    if(l == r) {
        T[node].val = a[l];
        T[node].pos = l;
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    if(T[node * 2].val >= T[node * 2 + 1].val) {
        T[node] = T[node * 2];
    } else {
        T[node] = T[node * 2 + 1];
    }
}

int get(int node, int l, int r, int value) {
    if(T[node].val < value) return 0;
    if(l == r) {
        T[node].val -= value;
        return T[node].pos;
    }
    int mid = (l + r) / 2, id = 0;
    if(T[node * 2].val >= value) {
        id = get(node * 2, l, mid, value);
    } else {
        id = get(node * 2 + 1, mid + 1, r, value);
    }
    if(T[node * 2].val >= T[node * 2 + 1].val) T[node] = T[node * 2];
    else T[node] = T[node * 2 + 1];
    return id;
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= m; ++i) cin >> h[i];
}

void sol() {
    init(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        cout << get(1, 1, n, h[i]) << ' ';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
