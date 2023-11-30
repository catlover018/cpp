#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;
const int maxX = 1e2;

int a[maxN+5], pref[maxN+5], n, q;
int nxt[maxN+5][maxX+5];

void read() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) pref[i] = pref[i-1] + a[i];
    for(int x = 0; x < 101; ++x) nxt[n+1][x] = n+1;
    for(int i = n; i > 0; --i)
        for(int x = 0; x < 101; ++x) {
            if(x < a[i]) nxt[i][x] = nxt[i+1][x];
            else nxt[i][x] = i;
        }
}

void sol() {
    while(q--) {
        int x, p;   cin >> x >> p;
        int cur = p-1, l = p, r = n;
        while(l <= r) {
            int mid = (l+r)/2;
            if(pref[mid] - pref[p-1] <= x) {
                cur = mid;
                l = mid+1;
            } else r = mid-1;
        }
        x -= pref[cur]-pref[p-1];
        int ans = cur - p + 1;
        while(cur < n) {
            cur = nxt[cur+1][x];
            if(cur > n) break;
            x -= a[cur];
            ++ans;
        }
        cout << ans << '\n';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
