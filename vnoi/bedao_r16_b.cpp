#include <iostream>

#define int long long

using ll = long long;
using namespace std;

const int maxN = 1e5;

int a[maxN + 5], b[maxN + 5], n, k;
ll base = 0;

void read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) {
        base += a[i] * b[i] * 1ll;
    }
}

ll cal(int x, int y) {
    ll cur_ans = base - x * y * 1ll;
    int cur_k = k;
    int len = abs(y - x);
    int mn = min(x, y), mx = max(x, y);
    mn += min(len, cur_k);
    cur_k = max(cur_k - len, 0ll);
    if(cur_k > 0) {
        if(cur_k & 1) ++mn;
        cur_k /= 2;
        mn += cur_k;     mx += cur_k;
    }
    cur_ans += mx * mn * 1ll;
    return cur_ans;
}

void sol() {
    ll ans = base;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, cal(a[i], b[i]));
    }
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
