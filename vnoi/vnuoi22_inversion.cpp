#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int maxN = 3e5;

#define pii pair<int, int>
#define fi first
#define se second

pii a[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].fi, a[i].se = i;
}

int BIT1[maxN + 5], BIT2[maxN + 5];
int cnt1[maxN + 5], cnt2[maxN + 5];

void update1(int i) {
    for(; i <= n; i+=(i&(-i))) BIT1[i]++;
}

void update2(int i) {
    for(; i > 0; i-=(i&(-i))) BIT2[i]++;
}

int get2(int i) {
    int ans = 0;
    for(; i <= n; i+=(i&(-i))) ans += BIT2[i];
    return ans;
}

int get1(int i) {
    int ans = 0;
    for(; i > 0; i-=(i&(-i))) ans += BIT1[i];
    return ans;
}

void sol() {
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        cnt1[a[i].se] = get2(a[i].se + 1) + cnt1[a[i - 1].se];
        update2(a[i].se);
    }
    for(int i = n; i > 0; --i) {
        cnt2[a[i].se] = get1(a[i].se - 1) + cnt2[a[i + 1].se];
        update1(a[i].se);
    }
    int cur_mx = cnt1[a[n].se], ans = 1e18, x = 0;
    for(int i = 1; i <= n; ++i) {
        int cur_ans = cnt1[a[i - 1].se] + cnt2[a[i + 1].se];
        if(cur_ans < ans) {
            ans = cur_ans;
            x = i;
        }
    }
    cout << x << " " << cur_mx - ans;
}


int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
