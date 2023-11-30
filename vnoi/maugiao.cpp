#include <bits/stdc++.h>

using namespace std;

const int maxN = 20;

long long dp[(1 << maxN) + 5], cnt[(1 << maxN) + 5];
int n, a[maxN + 5][maxN + 5];

void read() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
}

#define bit(n, i) ((n>>i)&1)

void sol() {
    cnt[0] = 1;
    for(int mask = 0; mask < (1 << n); ++mask) {
        int k = max(__builtin_popcount(mask) - 1, 0);
        for(int i = 0; i < n; ++i)
        if(bit(mask, i)) {
            int pre_mask = mask - (1 << i);
            if(dp[pre_mask] + a[i][k] > dp[mask]) {
                dp[mask] = dp[pre_mask] + a[i][k];
                cnt[mask] = cnt[pre_mask];
            } else if(dp[pre_mask] + a[i][k] == dp[mask]) cnt[mask] += cnt[pre_mask];
        }
    }
    cout << dp[(1 << n) - 1] << " " << cnt[(1 << n) - 1];
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
