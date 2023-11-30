#include <bits/stdc++.h>

using namespace std;
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define TASK "cake"
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define iii pair<ii,int>
const int N = 1e6 + 7;
const ll oo = 1e18;
const ll M = 2e9 + 7;
int n, Q;
ll a[N];
ll dp[4004][4004];
namespace subac {
ll ans = 0;

void solve() {
    For(i, 1, n) {
        a[i + n] = a[i];
        a[0] = a[n * 2 + 1] = M;
    }
    Ford(i, 2 * n, 1) {
        dp[i][i] = a[i];
        For(j, i + 1, n * 2) {
            if ((j - i + 1) % 2 == 0) {
                int R = j + 1;
                int L = i - 1;

                if (R > n * 2)
                    R = 1;

                if (L < 1)
                    L = n * 2;

                if (a[i] >= a[R])
                    dp[i][j] = max(dp[i][j], dp[i + 1][j]);

                if (a[j] >= a[L])
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            } else {
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
            }
        }
    }

    For(i, 1, n + 1) {
        ans = max(ans, dp[i][i + n - 1]);
    }
    cout << ans;
}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    cin >> n;
    For(i, 1, n) cin >> a[i];

    subac :: solve();

    return 0;
}


