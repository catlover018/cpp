#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = (1 << 10);

ll a[maxN + 5], mark[maxN + 5];
ll dp[maxN + 5];
int n;

void read() {
    int m;  cin >> m;   n = 0;
    for(int i = 1; i <= m; ++i) {
        ll x;  cin >> x;   ll pre = x;
        bool ok = true;
        while(x > 0) {
            int tmp = x % 10;
            if(mark[tmp]) {
                ok = false;
                break;
            }
            mark[tmp] = true;
            x /= 10;
        }
        if(ok) {
            a[++n] = pre;
        }
        for(int j = 0; j <= 9; ++j) mark[j] = 0;
    }
}

void sol() {
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        int cur_mask = 0, x = a[i];
        while(x > 0) {
            cur_mask += (1 << (x % 10));
            x /= 10;
        }
        dp[cur_mask] = max(dp[cur_mask], a[i]);
        for(int pre_mask = 0; pre_mask < (1 << 10); ++pre_mask)
        if(dp[pre_mask] > 0 && (pre_mask & cur_mask) == 0) {
            int mask = pre_mask + cur_mask;
            dp[mask] = max(dp[mask], dp[pre_mask] + dp[cur_mask]);
        }
    }
    cout << *max_element(dp, dp + (1 << 10)) << '\n';
}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--) {

        read();
        sol();

    }

    return 0;
}
