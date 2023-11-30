#include <bits/stdc++.h>

#define int long long

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;
const int MOD = 1e9+7;

int n, dp[maxN+5], BIT1[maxN+5], BIT2[maxN+5], g[maxN+5];
int a[maxN+5];

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

pii BIT[maxN+5];

void update(int i, int val1, int val2) {
  for(; i <= n; i+=(i&-i))
    if(BIT[i].fi < val1) {
      BIT[i].fi = val1;
      BIT[i].se = val2;
    } else if(BIT[i].fi == val1) {
      BIT[i].se += val2;
      BIT[i].se %= MOD;
    }
}

pii get(int i) {
  pii res;  res.fi = 0; res.se = 0;
  for(; i > 0; i-=(i&-i))
    if(res.fi < BIT[i].fi) res = BIT[i];
    else if(res.fi == BIT[i].fi) {
      res.se += BIT[i].se;
      res.se %= MOD;
    }
  return res;
}

void sol() {
  int ans = 0, cnt = 0;
  for(int i = 1; i <= n; ++i) {
    pii cur = get(a[i]-1);
    dp[i] = cur.fi+1;
    g[i] = max(cur.se, 1ll);
    update(a[i], dp[i], g[i]);
    if(dp[i] > ans) {
      ans = dp[i];
      cnt = g[i];
    } else if(dp[i] == ans) {
      cnt += g[i];
      cnt %= MOD;
    }
  }
  cout << cnt;
}

int32_t main() {

  read();
  sol();

  return 0;
}
