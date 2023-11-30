#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5], S, pref[maxN+5];
int n;

void read() {
  cin >> n >> S; pref[0] = 0;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i-1] + a[i];
  }
}

void sol() {
  int ans = 0;
  sort(pref, pref+n+1);
  for(int i = 0, j = 1; i < n; ++i) {
    while(S + pref[i] >= pref[j] && j <= n) ++j;
    ans += n-j+1;
//    cout << pref[i] << " " << j << endl;
  }
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("ASUM.inp", "r", stdin);
  freopen("ASUM.out", "w", stdout);

  read();
  sol();

  return 0;
}
