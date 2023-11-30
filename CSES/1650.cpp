#include <iostream>

using namespace std;

const int maxN = 1e6;

int T[maxN * 4 + 5], a[maxN * 4];

int n, query;

void init(int node, int l, int r) {
    if(l == r) {
        T[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = (T[node * 2] ^ T[node * 2 + 1]);
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    int Left = get(node * 2, l, mid, u, v);
    int Right = get(node * 2 + 1, mid + 1, r, u, v);
    return (Left ^ Right);
}

void read() {
    cin >> n >> query;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    init(1, 1, n);
    while(query--) {
        int u, v;   cin >> u >> v;
        cout << get(1, 1, n, u, v) << "\n";
    }
}

int main() {

    read();

    return 0;
}
