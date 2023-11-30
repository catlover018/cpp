#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

struct pii {
  int fi, se;
  bool operator < (const pii& o) const {
    return fi == o.fi ? se > o.se : fi < o.fi;
  }
};

int n;
pii a[maxN+5];
int BIT[maxN+5];

void read() {
  cin >> n; vector<int> v;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i].fi >> a[i].se;
    v.push_back(a[i].se);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end())-v.begin());
  for(int i = 1; i <= n; ++i) {
    a[i].se = lower_bound(v.begin(), v.end(), a[i].se)-v.begin()+1;
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

int dp[maxN+5];

void sol() {
  sort(a+1, a+n+1);
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = get(a[i].se)+1;
    update(a[i].se, dp[i]);
    ans = max(ans, dp[i]);
  }
  for(int i = 1; i <= n; ++i) {
    BIT[i] = 0;
    dp[i] = 0;
  }
  cout << ans << '\n';
}

int main() {

  int testcase; cin >> testcase;

  while(testcase--) {

    read();
    sol();

  }

  return 0;
}
