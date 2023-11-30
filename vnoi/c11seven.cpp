#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int MOD = 1e9 + 7;

struct Node {
    int val[7], sz;
    Node() {
        for(int i = 0; i < 7; ++i)  val[i] = 1;
        sz = 0;
    }
};

int a[maxN + 5], n, N_query;
Node T[maxN * 4 + 5];

void read() {
    cin >> n >> N_query;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

int sub(int x, int y, int mod) {
    x -= y;
    if(x < 0) x += mod;
    return x;
}

int mul(int x, int y) {
    if(y == 0) return 0;
    int tmp = mul(x, y/2) % MOD;
    tmp = (tmp + tmp) % MOD;
    if(y & 1) {
        tmp = (tmp + x) % MOD;
    }
    return tmp;
}

void build(int node, int l, int r) {
    if(l > r) return;
    if(l == r) {
        T[node].val[0] = a[l];
        T[node].sz = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    for(int i = 0; i < 7; ++i) {
        int j = sub(i, T[node*2].sz%7, 7);
        T[node].val[i] = (T[node*2].val[i] * T[node*2+1].val[j]) % MOD;
        T[node].sz = T[node*2].sz + T[node*2+1].sz;
    }
}

void update1(int node, int l, int r, int u, int v) {
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v) {
        for(int i = 0; i < 7; ++i) T[node].val[i] = 1;
        T[node].sz = 0;
        return;
    }
    int mid = (l + r) / 2;
    update1(node*2, l, mid, u, v);
    update1(node*2+1, mid+1, r, u, v);
    for(int i = 0; i < 7; ++i) {
        int j = sub(i, T[node*2].sz%7, 7);
        T[node].val[i] = (T[node*2].val[i] * T[node*2+1].val[j]) % MOD;
        T[node].sz = T[node*2].sz + T[node*2+1].sz;
    }
}

void update2(int node, int l, int r, int u, int v, int value) {
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v) {
        T[node].val[0] = value % MOD;
        return;
    }
    int mid = (l + r) / 2;
    update2(node*2, l, mid, u, v, value);
    update2(node*2+1, mid+1, r, u, v, value);
    for(int i = 0; i < 7; ++i) {
        int j = sub(i, T[node*2].sz%7, 7);
        T[node].val[i] = (T[node*2].val[i] * T[node*2+1].val[j]) % MOD;
        T[node].sz = T[node*2].sz + T[node*2+1].sz;
    }
}

int BIT[maxN + 5];

void update(int i) {
    for(; i <= n; i += (i&-i)) BIT[i]++;
}

int get(int i) {
    int res = 0;
    for(; i > 0; i -= (i&-i)) res += BIT[i];
    return res;
}

int get_val(int x) {
    int l = 1, r = n, ans = x;
    while(l <= r) {
        int mid = (l + r) / 2;
        int cur = mid - get(mid);
        if(x == cur) {
            ans = mid;
            r = mid - 1;
        } else if(x > cur) l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

void sol() {
    build(1, 1, n);
    for(int i_query = 1; i_query <= N_query; ++i_query) {
        int type;   cin >> type;
        if(type == 1) {
            int p;  cin >> p; ++p;
            p = get_val(p);
            a[p] = -1;
            update1(1, 1, n, p, p);
            update(p);
        } else if(type == 2) {
            int p, v;   cin >> p >> v;  ++p;
            p = get_val(p);
            a[p] = v;
            update2(1, 1, n, p, p, v);
        } else {
            int k;  cin >> k;   k %= 7;
//            for(int i = 1; i <= n; ++i) cout << a[i] << " ";
            cout << T[1].val[k] << '\n';
        }
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    read();
    sol();

    return 0;
}
