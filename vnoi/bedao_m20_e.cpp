#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 500;

int a[maxN + 5], b[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    for(int i = 1; i <= n; ++i) cin >> b[i], b[i] += b[i - 1];
}

int c[maxN + 5][maxN + 5];

void sol() {
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            c[i][j] = (i <= j ? a[j] - a[i - 1] : b[i] - b[j - 1]);
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    int ans = -1e9;
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            int v = 0, premin = 0;
            for(int u = 1; u <= n; ++u) {
                int cur = c[j][u] - c[i - 1][u] - c[j][v] + c[i - 1][v];
                if(premin < c[i - 1][u] - c[j][u]) {
                    premin = c[i - 1][u] - c[j][u];
                    v = u;
                }
                ans = max(ans, cur);
            }
        }
    }
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
