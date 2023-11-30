#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5];
int n, k;

void read() {
  cin >> n >> k;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

#define pii pair<int, int>
#define fi first
#define se second

bool check(int len) {
  vector<pii> dp;
  int sum = 0;
  for(int i = 1; i <= n; ++i) {
    sum += len;
    dp.push_back({sum - a[i], sum + a[i]});
  }
  sort(dp.begin(), dp.end());
  vector<int> v;  v.push_back(dp[0].se);
  for(int i = 1; i < n; ++i) {
    if(dp[i].se >= v.back()) v.push_back(dp[i].se);
    else {
      *upper_bound(v.begin(), v.end(), dp[i].se) = dp[i].se;
    }
  }
  return ((n-(int)v.size()) <= k);
}

void sol() {
  int ans = -1, l = 0, r = 1e18;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      ans = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  cout << ans;
}

int32_t main() {

  read();
  sol();

  return 0;
}
