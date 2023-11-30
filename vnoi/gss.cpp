#include <iostream>

#define int long long

using namespace std;

const int maxN = 1e5;
const int inf = 1e9 + 7;

struct pack {
    int mn, mx, dis;
    pack() {mx = -1e9; mn = 1e9; dis = -1e9;}
    pack(int _mx, int _mn, int _dis) {
        mx = _mx;   mn = _mn;
        dis = _dis;
    }
};

int a[maxN + 5], n;
pack T[maxN * 4 + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i],a[i] += a[i - 1];
}

pack operator + (pack a, pack b) {
    return pack(max(a.mx, b.mx),
                min(a.mn, b.mn),
                max(b.mx - a.mn, max(a.dis, b.dis)));
}

void init(int node, int l, int r) {
    if(l == r) {
        T[node].dis = a[l] - a[l - 1];
        T[node].mn = a[l - 1];
        T[node].mx = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

pack get(int node, int l, int r, int u, int v) {
    pack ans;
    if(l > r || l > v || u > r) return ans;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    pack Left = get(node * 2, l, mid, u, v);
    pack Right = get(node * 2 + 1, mid + 1, r, u, v);
    ans = Left + Right;
    return ans;
}

void sol() {
    init(1, 1, n);
    int query;  cin >> query;
    while(query--) {
        int u, v;   cin >> u >> v;
        cout << get(1, 1, n, u, v).dis << '\n';
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
