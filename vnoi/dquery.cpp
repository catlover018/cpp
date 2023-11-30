#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

struct pack{
    int l, r, type, id;
    pack() {l = 0; r = 0; type = 0; id = 0;}
    bool operator < (const pack& o) const {
        return o.r == r ? type < o.type : r < o.r;
    }
};

pack a[maxN + 5];
int n, q;
int BIT[maxN], last[maxN];

void update(int i, int k) {
    for(; i <= n; i += (i&(-i))) BIT[i] += k;
}

int get(int i) {
    int ans = 0;
    for(; i; i -= (i&(-i))) ans += BIT[i];
    return ans;
}

int query[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].l;  a[i].r = i;
        a[i].type = -1;
    }
    cin >> q;
    for(int i = 1; i <= q; ++i) {
        cin >> a[i + n].l >> a[i + n].r;
        a[i + n].id = i;
    }
}

void sol() {
    sort(a + 1, a + n + q + 1);
    for(int i = 1; i <= n + q; ++i) {
        if(a[i].type == -1) {
            update(a[i].r, 1);
            if(last[a[i].l]) update(last[a[i].l], -1);
            last[a[i].l] = a[i].r;
        } else {
            query[a[i].id] = get(a[i].r) - get(a[i].l - 1);
        }
    }
    for(int i = 1; i <= q; ++i) cout << query[i] << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
