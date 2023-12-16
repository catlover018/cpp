#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, k;
int a[maxN+5];

void read() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

bool ok(int len) {
  int res = 0;
  for(int i = 1; i <= n; ++i) {
    if(len <= a[i]) continue;
    res += (len - a[i]);
    if(res > k) return 0;
  }
  return 1;
}

void sol() {
  int l = 1, r = 2e9+1, ans = 0;
  while(l <= r) {
    int mid = (l+r)/2;
    if(ok(mid)) {
      ans = mid;
      l = mid+1;
    } else r = mid-1;
  }
  cout << ans << '\n';
}

int32_t main() {

  int testcase; cin >> testcase;

  while(testcase--) {

  read();
  sol();

  }

  return 0;
}
