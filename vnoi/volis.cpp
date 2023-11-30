#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3 + 5;
const int inf = 1e9;

int a[maxN + 5];
int n, d;

void read() {
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

int dp[maxN + 5], g[maxN + 5];

void sol() {
    int res = 0;
    dp[0] = -inf;   g[0] = -inf;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= res; ++j) {
            if(dp[j] <= a[i] + d) {
                int tmp = a[i] - d;
                if(j != 0) tmp = max(tmp, dp[j]);
                if(j + 1 <= res) g[j + 1] = min(tmp, dp[j + 1]);
                else g[j + 1] = tmp;
                if(j == res) {
                    ++res;
                    break;
                }
            }
        }
        for(int j = 0; j <= res; ++j) dp[j] = g[j];
    }
    cout << res << '\n';
}

int main() {

    read();
    sol();

    return 0;
}
