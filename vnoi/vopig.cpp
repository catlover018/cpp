#include <bits/stdc++.h>

#define int long long

using namespace std;

const int limitN = 1e9;
const int limitM = (1ll << 60) - 1;
const int maxN = 2e6;

int a[maxN + 5], dp[maxN + 5];
int n, m;

void readsub() {
    cin >> n >> m;
}

namespace sub1{
void sol() {
    int ans = 0, i = 0;
    while(ans <= n) {
        ans += (1ll << i);
        ++i;
    }
    cout << i - 1;
}
}

namespace sub2{
void sol() {
    int cnt0 = 0; int lg = 0;
    while((1ll << lg) <= n) {
        if((m&(1ll << lg))==0) cnt0++;
        ++lg;
    }
    int ans = 0; n &= m;
    for(int i = 0; i <= lg; ++i)
        if(n&(1ll << i)) ans++;

    ++ans;
    cout << ans * (1ll << cnt0) - 1;
}
}

void read() {
    for(int i = 1;i <= n; ++i) {
        cin >> a[i];
        int x = (a[i] & m); a[i] = 0;
        for(int j = 0; (1 << j) <= m; ++j) {
            if(m&(1 << j)) a[i] = a[i] * 2 + x % 2;
            x /= 2;
        }
    }
}

namespace sub3{
void sol() {
    sort(a + 1, a + n + 1);
    dp[1] = 1;
    for(int i = 2; i <= n; ++i) {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            if((a[i]|a[j])==a[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
    cout << *max_element(dp + 1, dp + n + 1);
}
}

namespace sub4{
int mark[maxN + 5], cnt[maxN + 5];
void sol() {
    int lm = 0;
    for(int i = 1; i <= n; ++i) {
        ++cnt[a[i]];    lm = max(lm, a[i]);
    }
    for(int i = 0; i <= lm; ++i) {
        for(int j = 0; (1ll << j) <= i; ++j)
            if(i&(1ll << j)) {
                int pre_mask = i - (1ll << j);
                dp[i] = max(dp[i], dp[pre_mask]);
            }
        dp[i] += cnt[i];
    }
    cout << *max_element(dp + 1, dp + lm + 1);
}
}

void solsub() {
    if(n >= limitN) {
        if(m == limitM) sub1::sol();
        else sub2::sol();
    } else {
        read();
        if(n <= 5000) sub3::sol();
        else sub4::sol();
    }
}

int32_t main() {

    readsub();
    solsub();

    return 0;
}
