#include <bits/stdc++.h>

using namespace std;

const int maxN = 3000;
const int base = 1e6;

int n, a[maxN + 5];
int dp[maxN + 5][maxN + 5];
int last[base * 4 + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += base;
}

void Clear() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) dp[i][j] = 0;
}

void sol() {
    Clear();
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            dp[i][j] = 2;
            if(a[i] - a[j] < -base) continue;
            int k = last[a[i] - a[j] + base];
            if(k > 0 && k < j) {
                dp[i][j] = dp[j][k] + 1;
            }
            ans = max(ans, dp[i][j]);
            last[a[j]] = j;
        }
        for(int j = 1; j < i; ++j) {
            last[a[j]] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int testcase;
      cin >> testcase;

    while(testcase--) {

    read();
    sol();

    }

    return 0;
}

