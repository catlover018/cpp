#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5], n, q;

void read() {
  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i-1];
}

int cal(int l, int r) {
  int ans = a[r] - a[l-1];
  while(l <= r) {
    int mid = (l+r)/2;
    int Left = a[mid] - a[l-1],
        Right = a[r] - a[mid];
    if(Left <= Right) {
      ans = min(ans, Right - Left);
      l = mid + 1;
    } else {
      ans = min(ans, Left - Right);
      r = mid - 1;
    }
  }
  return ans;
}

void sol() {
  while(q--) {
    int l, r; cin >> l >> r;
    cout << cal(l, r) << '\n';
  }
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("CHENHLECH.inp", "r", stdin);
  freopen("CHENHLECH.out", "w", stdout);

  read();
  sol();

  return 0;
}
