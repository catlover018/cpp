#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

#define pii pair<int, int>
#define fi first
#define se second

struct pack {
    int x, y, k, id;
    pack() {x = 0; y = 0; k = 0; id = 0;}
    pack(int _x, int _y, int _k, int _id) {
        x = _x; y = _y; k = _k; id = _id;
    }
    bool operator < (const pack& o) const {
        return x < o.x;
    }
};

pii a[maxN + 5];
pack q[maxN + 5];
int n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int x, y;   cin >> x >> y;
        a[i] = make_pair(x, y);
    }
    for(int i = 1; i <= m; ++i) {
        int x, y, k;    cin >> x >> y >> k;
        q[i] = pack(x, y, k, i);
    }
    sort(a + 1, a + n + 1);
    sort(q + 1, q + m + 1);
}

int cal(int l, int r, int x, int y, int k) {
    int cur_ans = 0;
    if(x >= l && x <= r) {
        if(x <= y) cur_ans += abs(y-x);
        else {
            int cur_k = abs(x-y);
            if(cur_k <= k) cur_ans += abs(y-x);
            else cur_ans = -1;
        }
    } else {
        if(x > r) {
            cur_ans += abs(r - x);
            x = r;
            if(x <= y) cur_ans += abs(y-x);
            else {
                int cur_k = abs(x-y);
                if(cur_k <= k) cur_ans += abs(y-x);
                else cur_ans = -1;
            }
        }
        if(x < l) {
            int cur_k = abs(x-l);
            if(cur_k <= k) {
                cur_ans += abs(x-l);
                x = l;
                if(x <= y) cur_ans += abs(x-y);
                else {
                    cur_k += abs(x-y);
                    if(cur_k <= k) cur_ans += abs(y-x);
                    else cur_ans = -1;
                }
            } else cur_ans = -1;
        }
    }
    return cur_ans;
}

int res[maxN + 5];

void sol() {
    for(int i = 1, j = 1; j <= m; ++j) {
        auto [x, y, k, id] = q[j];
        while(a[i].fi < x && i < n) ++i;
        auto [l, r] = a[i];
//        cout << x << " " << y << " " << k << endl;
//        cout << l << " " << r << " " << endl;
        int ans1 = cal(l, r, x, y, k), ans2 = -1;
        if(i > 1) ans2 = cal(a[i-1].fi, a[i-1].se, x, y, k);
        if(ans1 == ans2 && ans1 == -1) {
            res[id] = -1;
        } else if(ans1 == -1) {
            res[id] = ans2;
        } else if(ans2 == -1) {
            res[id] = ans1;
        } else {
            res[id] = min(ans1, ans2);
        }
    }
    for(int i = 1; i <= m; ++i) {
        cout << res[i] << '\n';
    }
}


int32_t main() {

    read();
    sol();

    return 0;
}
