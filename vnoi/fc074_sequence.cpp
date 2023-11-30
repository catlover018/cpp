#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN + 5], n, k;
int pref[maxN + 5], s[maxN + 5];

void read() {
    cin >> n >> k;
    pref[0] = 0;    s[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
}

bool check(int x) {
    int mn = 1e9;
    for(int i = 1, j = 0; i <= n; ++i) {
        s[i] = s[i - 1] + a[i] - x;
        while(pref[i] - pref[j] >= k && j < i) {
            mn = min(mn, s[j]);
            ++j;
        }
        if(s[i] - mn >= 0) return true;
    }
    return false;
}

void sol() {
    int l = 1, r = 1e9, ans = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
