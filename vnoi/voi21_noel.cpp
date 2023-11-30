#include<bits/stdc++.h>

using namespace std;

const int maxN = 2e3;

int a[maxN+5];
int n, d;
int dp[maxN+5][maxN+5], g[maxN+5][maxN+5];
vector<int> v[maxN+5];

void read() {
  cin >> n >> d; n <<= 1;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i)
    for(int j = n; j > i; --j)
      if(abs(a[i] - a[j]) <= d) v[i].push_back(j);
}

int BIT[maxN+5][maxN+5];

void update(int i, int d, int val) {
  for(; i <= n; i+=(i&-i)) BIT[d][i] = max(BIT[d][i],  val);
}

int get(int i, int d) {
  int res = 0;
  for(; i > 0; i-=(i&-i)) res = max(res, BIT[d][i]);
  return res;
}

int x[maxN+5];

void sol() {
  int ans = 0;
  for(int l = 1; l < n; ++l) {
    int lm = 0;
    for(int i = 1; i <= l; ++i) {
      for(int j : v[i]) if(j > l) x[++lm] = j;
    }
    for(int i = 1; i <= lm; ++i) {
      int cur = get(x[i]-1, l) + 1;
      ans = max(ans, cur);
      update(x[i], l, cur);
    }
  }
  cout << ans;
}

int main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("test.inp", "r", stdin);
  freopen("test.out", "w", stdout);

  read();
  sol();

  return 0;
}
