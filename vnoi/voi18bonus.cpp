#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e3;

struct point {
  int x, y, u, v;
  point() {x = 0; y = 0; u = 0; v = 0;}
  point(int _x, int _y, int _u, int _v) {
    x = _x; y = _y; u = _u; v = _v;
  }
};

int a[maxN+5][maxN+5], n, k, r, p;
point d[maxN+5];

void read() {
  cin >> n >> k >> r >> p;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      cin >> a[i][j],
      a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
}

int cal(int x, int y, int u, int v) {
  if(x > u || y > v) return 0;
  return (a[u][v] - a[x-1][v] - a[u][y-1] + a[x-1][y-1]);
}

void sol() {
  int ans = 0;
  while(k--) {
      int sum = 0;
      vector<pii> e;
      for(int i = 1; i <= p; ++i) {
          int x, y; cin >> x >> y;
          e.push_back({x, y});
      }
      for(int mask = 1; mask < (1 << p); ++mask) {
        int x = 0, y = 0, u = n+1, v = n+1;
        int cnt = 0;
        for(int i = 0; i < 18; ++i)
        if((mask >> i)&1) {
          ++cnt;
          x = max(e[i].fi, x);
          y = max(e[i].se, y);
          u = min(e[i].fi+r-1, u);
          v = min(e[i].se+r-1, v);
        }
        if(cnt%2==1) sum += cal(x, y, u, v);
        else sum -= cal(x, y, u, v);
      }
      ans = max(ans, sum);
  }
  cout << ans;
}

int32_t main() {

  read();
  sol();

  return 0;
}
