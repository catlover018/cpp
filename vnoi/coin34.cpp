#include <bits/stdc++.h>

using namespace std;

const int maxM = 367980;
const int maxN = 35;

int a[maxN], dp[maxM], n;
int cnt[maxN], cost[maxN];
int cur_coin, ans;

void ql1(int i) {
    for(int j = 0; j <= 1; ++j) {
        cost[i] = cost[i - 1];  cnt[i] = cnt[i - 1];
        if(j == 1) cost[i] += a[i], ++cnt[i];
        if(i < 20) ql1(i + 1);
        else if(dp[cost[i]] < cnt[i]) dp[cost[i]] = cnt[i];
    }
}


void ql2(int i) {
    for(int j = 0; j <= 1; ++j) {
        cost[i] = cost[i - 1];  cnt[i] = cnt[i - 1];
        if(j == 1) cost[i] += a[i], ++cnt[i];
        if(i < 34) ql2(i + 1);
        else if((cur_coin - cost[i] >= 0) && (cur_coin - cost[i] <= maxM)) {
            if(cur_coin - cost[i] == 0) ans = max(ans, dp[cur_coin - cost[i]] + cnt[i]);
            else if(dp[cur_coin - cost[i]] != 0) ans = max(ans, dp[cur_coin - cost[i]] + cnt[i]);
        }
    }
}

void pre_processing() {
    a[1] = 2;   a[2] = 3;   a[3] = 5;
    for(int i = 4; i < 35; ++i) a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    ql1(1); cost[20] = 0;   cnt[20] = 0;
}

void sol(int test) {
    ans = 0;  cin >> cur_coin;
    if(cur_coin < maxM) ans = max(ans, dp[cur_coin]);
    ql2(21);
    cout << "Case #" << test << ": ";
    if(ans == 0) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {

    pre_processing();

    int testcase;   cin >> testcase;

    for(int i = 1; i <= testcase; ++i) sol(i);

    return 0;
}
