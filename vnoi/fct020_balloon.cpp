#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int maxK = 200;

int n, m, k;
int a[maxN+5], dp[2][maxN+5];

void read() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void sol() {
    for(int i = 1; i <= k; ++i) {
        deque<int> Q; Q.push_back(i-1);
        for(int j = i; j <= n; ++j) {
            if(j - m > 0) while(Q.front() < j-m && Q.size() > 1) Q.pop_front();
            int id = Q.front();
            dp[i%2][j] = a[j]*i+dp[(i-1)%2][id];
            while(dp[(i-1)%2][j] > dp[(i-1)%2][Q.back()] && !Q.empty()) {
                Q.pop_back();
                if(Q.empty()) break;
            }
//            cout << dp[i%2][j] << " ";
            Q.push_back(j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dp[k%2][i]);
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
