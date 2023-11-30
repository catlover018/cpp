#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 350;

int dp[maxN + 5][maxN + 5];
int n;

int bcnn(int u, int v) {
    return (u * v / __gcd(u, v));
}

void sol() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            dp[i][j] = 0;
    for(int i = 0; i <= n; ++i) dp[i][0] = dp[0][i] = 1;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= i; ++j) {
        dp[i][j] = max(bcnn(dp[i - j][j - 1], j), dp[i][j - 1]);
    }
    cout << dp[n][n];
}

int32_t main() {

    int testcase;   cin >> testcase;

    while(testcase--)
    sol();

    return 0;
}
