#include <bits/stdc++.h>
#define bit(n, i) ((n >> i)&1)
#define int long long

using namespace std;

const int maxN = 20;
const int maxV

int n, k;
int c[maxN][maxN];
int dp[(1 << maxN)], f[maxN][(1 << maxN)];

void read() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> c[i][j];
}

void sol() {
    memset(dp, 60, sizeof(dp));
    memset(f, 60, sizeof(f));
    int len = (1 << n) - 1;
    for(int mask = 0; mask <= len; ++mask) {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) {
                if(bit(mask, j) && i != j) {
                    int pre_mask = mask - (1 << j);
                    f[i][mask] = min(c[i][j], f[i][pre_mask]);
                    break;
                }
            }
    }
    int ans = dp[len];  dp[len] = 0;
    for(int mask = len; mask >= 0; --mask) {
        for(int i = 0; i < n; ++i)
        if(!bit(mask, i)) {
            int pre_mask = mask + (1 << i);
            dp[mask] = min(dp[mask], dp[pre_mask] + f[i][pre_mask]);
        }
        if(__builtin_popcount(mask) == k) ans = min(ans, dp[mask]);
    }
    cout << ans;
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
