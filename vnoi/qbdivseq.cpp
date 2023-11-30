#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

int a[maxN+5], BIT[maxN+5], dp[maxN+5];
int n;

void read() {
  cin >> n;
  vector<int> v;
  for(int i = 1; i <= n; ++i) {
      cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end())-v.begin());
  for(int i = 1; i <= n; ++i) {
    a[i] = lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
  }
}

void update(int i, int val) {
  for(; i > 0; i-=(i&-i)) BIT[i] = max(BIT[i], val);
}

int get(int i) {
  int res = 0;
  for(; i <= n; i+=(i&-i)) res = max(res, BIT[i]);
  return res;
}

void sol() {
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = get(a[i]+1)+1;
    update(a[i], dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

int main() {

  read();
  sol();

  return 0;
}
