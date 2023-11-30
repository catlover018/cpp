#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN + 5];
int n, q;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    cin >> q;
    while(q--) {
        int type, l, r; cin >> type >> l >> r;
        if(type == 1) {
            int ans = 1;
            for(int i = l; i <= r; ++i) {
                ans *= a[i];
            }
            int tmp = sqrt(ans);
            cout << (tmp * tmp == ans ? "YES" : "NO") << '\n';
        } else {
            a[l] *= r;
        }
    }
}

int32_t main() {

    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);

    read();

    return 0;
}
