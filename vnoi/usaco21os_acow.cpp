#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, m, k;
int a[maxN+5];

void read() {
  cin >> n >> m >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1, greater<int>());
}

bool check(int len) {
  int cnt = 0;
  for(int i = 1; i <= len; ++i) {
    if(a[i] >= len) continue;
    if(k == 0 || m == 0) return false;
    cnt += len - a[i];
  }
  return (cnt <= m*k && a[len]+m >= len);
}

void sol() {
  int ans = 0;
  int l = 0, r = n;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      l = mid+1;
    } else r = mid-1;
  }
  cout << ans;
}

//5 5 2
//1 2 3 4 5

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
