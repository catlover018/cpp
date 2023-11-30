#pragma GCC optimized "Ofast"
#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;

struct pack {
    int id, u, v, k;
    pack() {id = 0; u = 0; v = 0; k = 0;}
    pack(int _id, int _u, int _v, int _k) {
        id = _id;   u = _u;
        v = _v; k = _k;
    }
};

int a[maxN + 5], b[maxN + 5], c[maxN + 5];
int T1[maxN * 4 + 5], T2[maxN * 4 + 5], lz1[maxN * 4 + 5], lz2[maxN * 4 + 5];
int n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) cin >> c[i];
}

vector<pack> query1;
pack query[maxN + 5];

void push(int node, int T[], int lz[]) {
    T[node * 2] = lz[node];  T[node * 2 + 1] = lz[node];
    lz[node * 2] = lz[node];    lz[node * 2 + 1] = lz[node];
    lz[node] = 0;
}

void update(int node, int l, int r, int u, int v, int val, int T[], int lz[]) {
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v) {
        T[node] = val;
        lz[node] = val;
        return;
    }
    if(lz[node]) push(node, T, lz);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v, val, T, lz);
    update(node * 2 + 1, mid + 1, r, u, v, val, T, lz);
}

int get(int node, int l, int r, int p, int T[] , int lz[]) {
    if(l > p || p > r || l > r) return 0;
    if(l == p && p == r) return T[node];
    if(lz[node]) push(node, T, lz);
    int mid = (l + r) / 2;
    if(p <= mid) return get(node * 2, l, mid, p, T, lz);
    return get(node * 2 + 1, mid + 1, r, p, T, lz);
}

vector<tuple<int, int, int>> query3;
int ans[maxN + 5];

void sol() {
    for(int i = 1; i <= m; ++i) {
        int type, u, v, k;  cin >> type;
        if(type == 1) {
            cin >> u >> v >> k;
            query[i] = pack(0, u, v, k);
            query1.push_back(pack(i, u, v, k));
        } else if(type == 2) {
            cin >> u >> v >> k;
            query[i] = pack(0, u, v, k);
            update(1, 1, n, v, v + k - 1, i, T1, lz1);
        } else if(type == 3) {
            int p;  cin >> p;
            int get1 = get(1, 1, n, p, T1, lz1);
            if(get1 == 0) {
                ans[i] = c[p];
            } else {
                p = p + query[get1].u - query[get1].v;
                query3.push_back(make_tuple(get1, p, i));
            }
        }
    }
    sort(query3.begin(), query3.end());
    int j = 0, lm = query1.size();
    for(auto [i, p, id] : query3) {
        while(j < lm && query1[j].id < i) {
            auto [type, x, y, k] = query1[j];
            update(1, 1, n, y, y + k - 1, type, T2, lz2);
            ++j;
        }
        int get2 = get(1, 1, n, p, T2, lz2);
        if(get2 == 0) ans[id] = b[p];
        else {
            ans[id] = a[p + query[get2].u - query[get2].v];
        }
    }
    for(int i = 1; i <= m; ++i)
        if(ans[i] > 0) cout << ans[i] << '\n';
}

int main() {

//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    cin.tie(0) ->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
