#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;
const int MOD = 1e9 + 7;

int dp[2][maxN + 5];
int n, k, s;

void read() {
    cin >> n >> s >> k;
}

void sol() {
    for(int i = 1; i <= s; ++i) dp[1][i] = dp[1][i - 1] + 1;
    for(int i = 2; i <= k; ++i) {
//        cout << i << endl;
        for(int j = 1; j <= min(n, s); ++j) {
            dp[i % 2][j] = dp[(i - 1) % 2][min(s-j, n/j)];
            cout << j << " " << dp[i % 2][j] << '\n';
            dp[i % 2][j] += dp[i % 2][j - 1];
            dp[i % 2][j] %= MOD;
         }
        cout << endl;
    }
//    cout << dp[k % 2][min(n, s)];
}

int main(){

    read();
    sol();

    return 0;
}
