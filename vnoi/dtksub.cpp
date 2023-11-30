#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int base = 31;
const int maxN = 1e6;
const ll MOD = 1e6 + 9;

int n, k;
string s;
ll hashS[maxN + 5], Pow[maxN + 5];
int cnt[MOD + 5];

ll getHash(int l, int r) {
    return (hashS[r] - hashS[l - 1] * Pow[r - l + 1] + MOD * MOD) % MOD;
}

void read() {
    cin >> n >> k >> s;
    s = " " + s;
    hashS[0] = 0;   Pow[0] = 1;
    for(int i = 1; i <= n; ++i) {
        hashS[i] = (hashS[i - 1] * base + s[i] - 'a' + 1) % MOD;
        Pow[i] = Pow[i - 1] * base % MOD;
    }
}

bool check(int len) {
    for(int i = 0; i <= MOD; ++i) cnt[i] = 0;
    for(int i = 1; i <= n - len + 1; ++i) {
        ll tmp = getHash(i, i + len - 1);
        if(++cnt[tmp] == k) return true;
    }
    return false;
}

void sol() {
    int l = 1, r = n;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
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
