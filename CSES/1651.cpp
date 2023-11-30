#include <iostream>

using namespace std;

const int maxN = 1e6;

long long T[maxN * 4 + 5], lz[maxN * 4 + 5];
int a[maxN + 5], n, query;

void init(int node, int l, int r) {
    if(l == r) {
        T[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
}

void push(int node) {
    T[node * 2] += lz[node]; T[node * 2 + 1] += lz[node];
    lz[node * 2] += lz[node];    lz[node * 2 + 1] += lz[node];
    lz[node] = 0;
}

void update(int node, int l, int r, int u, int v, int val) {
    if(l > r || l > v || u > r) return;
    if(u <= l && r <= v) {
        T[node] += val;
        lz[node] += val;
        return;
    }
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val);
    update(node * 2 + 1, mid + 1, r, u, v, val);
}

long long get(int node, int l, int r, int p) {
    if(l > r || l > p || p > r) return 0;
    if(l == r && r == p) return T[node];
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    long long Left = get(node * 2, l, mid, p);
    long long Right = get(node * 2 + 1, mid + 1, r, p);
    if(Left == 0) return Right;
    if(Right == 0) return Left;
    return 0;
}


void read() {
    cin >> n >> query;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    init(1, 1, n);
    while(query--) {
        int type;
        cin >> type;
        if(type == 1) {
            int u, v, val;  cin >> u >> v >> val;
            update(1, 1, n, u, v, val);
        } else {
            int k;  cin >> k;
            cout << get(1, 1, n, k) << '\n';
        }
    }
}

int main() {

    read();

    return 0;
}
