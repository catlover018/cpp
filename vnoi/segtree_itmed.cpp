#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN + 5];
long long T[maxN * 4 + 5];
int n, k;

void read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void update(int node, int l, int r, int p, int val) {
    if(l > r || l > p || r < p) return;
    if(l == r && r == p) {
        T[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, p, val);
    update(node * 2 + 1, mid + 1, r, p, val);
    T[node] = max(T[node * 2], T[node * 2 + 1]);
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return 0;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    int Left = get(node * 2, l, mid, u, v);
    int Right = get(node * 2 + 1, mid + 1, r, u, v);
    return max(Left, Right);
}

long long dp[maxN + 5];

void sol() {
    for(int i = 1; i <= n; ++i) {
        long long pre_dp = get(1, 1, n, max(i - k, 1ll), max(i - 1, 1ll));
        dp[i] = max(pre_dp + a[i], 0ll);
        update(1, 1, n, i, dp[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
