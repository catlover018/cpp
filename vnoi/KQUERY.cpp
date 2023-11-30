#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

struct query {
    int l, r, type, id, val;
    query() {l = 0; r = 0; type = 0; id = 0; val = 0;}
    query(int _l, int _r, int _type, int _id, int _val) {
        l = _l; r = _r;
        type = _type;   id = _id;
        val = _val;
    }
    bool operator < (const query& o) const {
        return (val == o.val ? o.type < type : o.val < val);
    }
};

query a[maxN + 5];
int n, BIT[maxN + 5], q;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int m;    cin >> m;
        a[i] = query(i, i, 0, 0, m);
    }
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        int u, v, k;    cin >> u >> v >> k;
        a[i + n] = query(u, v, 1, i, k);
    }
    sort(a + 1, a + n + q + 1);
}

int res[maxN + 5];

int get(int i) {
    int ans = 0;
    for(; i > 0; i -= (i&(-i))) ans += BIT[i];
    return ans;
}

void update(int i) {
    for(; i <= maxN; i += (i&(-i))) BIT[i]++;
}

void sol() {
    for(int i = 1; i <= n + q; ++i) {
        auto [l, r, type, id, val] = a[i];
//        cout << l << " " << r << " " << type << " " << id << " " << val << endl;
        if(type == 1) {
            res[id] = get(r) - get(l - 1);
        } else {
            update(l);
        }
    }
    for(int i = 1; i <= q; ++i) cout << res[i] << '\n';
}

int main() {

    read();
    sol();

    return 0;
}
