#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5], b[maxN+5];
int n;

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i <= n; ++i) cin >> b[i];
  sort(a+1, a+n+1);
  sort(b+1, b+n+1, greater<int>());
}

void sol() {
  int ans = 0;
  for(int i = 1; i <= n; ++i)
    ans += max(a[i], b[i]);
  cout << ans << '\n';
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  int testcase; cin >> testcase;

  while(testcase--) {

  read();
  sol();

  }

  return 0;
}
