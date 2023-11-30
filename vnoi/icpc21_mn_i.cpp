#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int maxN = 1e6;

#define pii pair<int, int>
#define fi first
#define se second

int n;
pii a[maxN + 5];
int BITL[maxN + 5], BITR[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
}

int cntR[maxN + 5], cntL[maxN + 5];

void update1(int i) {
    for(; i > 0; i -= (i&(-i))) ++BITR[i];
}

int get1(int i) {
    int ans = 0;
    for(; i <= n; i += (i&(-i))) ans += BITR[i];
    return ans;
}

void update2(int i) {
    for(; i <= n; i += (i&(-i))) ++BITL[i];
}

int get2(int i) {
    int ans = 0;
    for(; i > 0; i -= (i&(-i))) ans += BITL[i];
    return ans;
}

void sol() {

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        cntR[a[i].se] = get1(a[i].se + 1) + cntR[a[i - 1].se];
        update1(a[i].se);
    }
    for(int i = n; i > 0; --i) {
        cntL[a[i].se] = get2(a[i].se - 1) + cntL[a[i + 1].se];
        update2(a[i].se);
    }

    int ans = 1e18;
    for(int i = 1; i <= n; ++i)
        ans = min(ans, cntR[a[i - 1].se] + cntL[a[i + 1].se]);

    cout << ans;
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
