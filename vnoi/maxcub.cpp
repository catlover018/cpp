#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 100;

int a[maxN+5][maxN+5][maxN+5];
int n;

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      for(int k = 1; k <= n; ++k) {
        cin >> a[i][j][k];
        a[i][j][k] = a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1]
                    - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1]
                    + a[i-1][j-1][k-1] + a[i][j][k];
      }
}

int get(int _x, int _y, int _z, int lim) {
  return a[_x][_y][_z]
        - a[_x-lim][_y][_z] - a[_x][_y-lim][_z] - a[_x][_y][_z-lim]
        + a[_x-lim][_y-lim][_z] + a[_x-lim][_y][_z-lim] + a[_x][_y-lim][_z-lim]
        - a[_x-lim][_y-lim][_z-lim];
}

void sol() {
  int ans = -1e18;
  for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) for(int k = 1; k <= n; ++k) {
    int lm = min(i, min(j, k));
    for(int t = 1; t <= lm; ++t) {
      int cur_sum = get(i, j, k, t);
      ans = max(ans, cur_sum);
    }
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
