#include <bits/stdc++.h>

#define int long long
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout); }

using namespace std;

const int maxN = 1e6;
const int MOD = 1e9+7;

int T[maxN*4+5], lz1[maxN*4+5], lz2[maxN*4+5];
int n, query;

void read() {
    cin >> n >> query;
}

void push(int node, int type, int l = 0, int r = 0) {
    int mid = (l + r)/2;
    if(type == 1) {
        lz1[node*2] += lz1[node];   lz1[node*2] %= MOD;
        lz1[node*2+1] += lz1[node]; lz1[node*2+1] %= MOD;
        T[node*2] += lz1[node]*(mid-l+1);   T[node*2] %= MOD;
        T[node*2+1] += lz1[node]*(r-mid);   T[node*2+1] %= MOD;
//        cout << lz1[node*2] << ' ' << lz1[node*2+1] << endl;
        lz1[node] = 0;
    } else {
        lz2[node*2] += lz2[node];       lz2[node*2] %= MOD;
        lz2[node*2+1] += lz2[node];     lz2[node*2+1] %= MOD;
        T[node*2] += lz2[node]*(l+mid)*(mid-l+1)/2;     T[node*2] %= MOD;
        T[node*2+1] += lz2[node]*(mid+r+1)*(r-mid)/2;   T[node*2+1] %= MOD;
        lz2[node] = 0;
    }
}

void update(int node, int l, int r, int u, int v, int val1, int val2) {
//  cout << l << ' ' << r << endl;
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v) {
        int tmp2 = (val2*(r+l)*(r-l+1)/2 + MOD*MOD)%MOD;
        int tmp1 = val1*(r-l+1)%MOD;
//        tmp1 = 0;
//        cout << T[node] << ' ' << tmp1 << ' ' << tmp2 << endl;
        T[node] = (T[node]+tmp1+tmp2)%MOD;
        lz1[node] += val1;  lz1[node] %= MOD;
        lz2[node] = (lz2[node]+val2)%MOD;
        return;
    }
    if(lz1[node]) push(node, 1, l, r);
    if(lz2[node]) push(node, 2, l, r);
    int mid = (l + r)/2;
    update(node*2, l, mid, u, v, val1, val2);
    update(node*2+1, mid+1, r, u, v, val1, val2);
    T[node] = (T[node*2]+T[node*2+1])%MOD;
}

int get(int node, int l, int r, int u, int v) {
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    if(lz1[node]) push(node, 1, l, r);
    if(lz2[node]) push(node, 2, l, r);
    int mid = (l + r)/2;
    int Left = get(node*2, l, mid, u, v);
    int Right = get(node*2+1, mid+1, r, u, v);
//    cout << Left << ' ' << Right << ' ' << endl;
    return (Left+Right)%MOD;
}

void sol() {
    while(query--) {
        int type;
        cin >> type;
        if(type == 1) {
            int l, r, a, b; cin >> l >> r >> a >> b;
//      cout << (b - l*a + MOD*MOD)%MOD << endl;
            update(1, 1, n, l, r, (-l*a+b+MOD*MOD)%MOD, a);
        } else {
            int l, r;   cin >> l >> r;
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    file("segtree_itladder");

    read();
    sol();

    return 0;
}


