#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 2e5 + 5;

int n, k;
int a[maxN], h[maxN], pref[maxN];
int mark[maxN];

void read() {
    cin >> n >> k;
    pref[0] = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i ++) cin >> h[i];
}

int cal(int l, int r) {
    int res = 0;  int p = l;
    while(l <= r) {
      int mid = (l + r)/2;
      int cur_val = pref[mid] - pref[p-1];
      if(cur_val <= k) {
        l = mid+1;
        res = max(res, mid-p+1);
      }
      else r = mid-1;
    }
    return res;
}

void sol() {
    for(int i = 1, j = 0; i <= n; ){
        j = i + 1;
        while(j <= n && h[j-1] % h[j] == 0) ++j;  --j;
        for(int t = i; t <= j; t++) mark[t] = j;
        i = j+1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, cal(i, mark[i]));
    }
    cout << ans << '\n';
}

int32_t main () {

    cin.tie(0)->sync_with_stdio(0);

    int testcase; cin >> testcase;

    while(testcase--) {

      read();
      sol();

    }
    return 0;
}
