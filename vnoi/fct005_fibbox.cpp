#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6 + 5;
const int MOD = 1e9 + 7;

int f[maxN], a[maxN];
int T[maxN * 4 + 5], n, q;

void read() {
    cin >> n >> q;
    f[0] = 0;   f[1] = 1;
    for(int i = 2; i <= n; ++i) f[i] = f[i - 1] + f[i - 2], f[i] %= MOD;
}

void sol() {
    while(q--) {
        char c; int l, r;
        cin >> c >> l >> r;
        if(c == 'D') {
            for(int i = l; i <= r; ++i) ++a[i];
        } else {
            int ans = 0;
            for(int i = l; i <= r; ++i) {
                ans += f[a[i]];
                ans %= MOD;
            }
            cout << ans << '\n';
        }
    }
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
