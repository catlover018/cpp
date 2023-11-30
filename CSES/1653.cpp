#include <bits/stdc++.h>

using namespace std;

const int maxN = 21;

int n, S;
int a[maxN+5];

void read() {
    cin >> n >> S;
    for(int i = 0; i < n; ++i) cin >> a[i];
}

#define pii pair<int, int>
#define fi first
#define se second
#define bit(n,i) ((n>>i)&1)

pii dp[(1<<maxN)+5];

void sol() {
    dp[0] = make_pair(1, 0);
    for(int mask = 1; mask < (1<<n); ++mask) {
        pii best = make_pair(1e9, 1e9);
        for(int i = 0; i < n; ++i) {
            if(!bit(mask, i)) continue;
            int pre_mask = (mask ^ (1<<i));
            pii cur = dp[pre_mask];
            if(cur.se + a[i] <= S) {
                cur.se += a[i];
            } else {
                cur.fi += 1;
                cur.second = a[i];
            }
            best = min(best, cur);
        }
        dp[mask] = best;
//        cout << dp[mask].fi << " " << dp[mask].se << endl;
    }
    cout << dp[(1<<n)-1].fi;
}

int main() {

    read();
    sol();

    return 0;
}
