#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

struct pack {
    int type, l, r, id;
    pack() {type = 0; l = 0; r = 0; id = 0;}
    pack(int _type, int _l, int _r, int _id) {
        type = _type;
        l = _l;
        r = _r;
        id = _id;
    }
    bool operator < (const pack& o) const{
        return (r == o.r ? type < o.type : r < o.r);
    }
};

int n, m;
int a[maxN + 5];
map<int, int> last;
pack d[maxN + 5];
vector<int> vec;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for(int i = 1; i <= n; ++i) {
        a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
        d[i] = pack(0, i, i, a[i]);
    }
    for(int i = 1; i <= m; ++i) {
        int l, r;   cin >> l >> r;
        d[i+n] = pack(1, l, r, i);
    }
}

int BIT[maxN + 5];
int ans[maxN + 5];

void update(int i, int val) {
    for(; i > 0; i-=(i&-i)) BIT[i] = min(BIT[i], val);
}

int get(int i) {
    int res = n+1;
    for(; i <= n; i+=(i&-i)) res = min(res, BIT[i]);
    return res;
}

void sol() {
    sort(d + 1, d + m + n + 1);
    for(int i = 1; i <= n; ++i) BIT[i] = n+1;
    for(int i = 1; i <= m+n; ++i) {
        auto [type, l, r, id] = d[i];
//        cout << type << " " << l << " " << r << " " << id << '\n';
        if(type == 0) {
            update(last[a[l]], l-last[a[l]]);
            last[a[l]] = l;
        } else {
            ans[id] = get(l);
            if(ans[id] == n+1) ans[id] = -1;
        }
    }
    for(int i = 1; i <= m; ++i) cout << ans[i] << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
