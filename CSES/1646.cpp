#include <iostream>

using namespace std;

const int maxN = 1e6;

int a[maxN + 5];
long long T[maxN * 4 + 5];

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

long long get(int node, int l, int r, int u, int v) {
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    long long Left = get(node * 2, l, mid, u, v);
    long long Right = get(node * 2 + 1, mid + 1, r, u, v);
    return Left + Right;
}

int query, n;

void read() {
    cin >> n >> query;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void sol() {
    init(1, 1, n);
    for(int i = 1; i <= query; ++i) {
        int l, r;   cin >> l >> r;
        cout << get(1, 1, n, l, r) << '\n';
    }
}

int main() {

    read();
    sol();

    return 0;
}
