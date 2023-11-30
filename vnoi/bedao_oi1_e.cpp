#include <bits/stdc++.h>

#define int long long

using namespace std;

#define pii pair<int, int>
#define fi first
#define se second

const pii mv[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int maxN = 3e3;

int a[maxN+5][maxN+5];
vector<pii> tplt[maxN+5];
int mark[maxN+5][maxN+5];
int n, m;

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j) {
        char c; cin >> c;
        a[i][j] = (c == '.' ? 1 : 0);
    }
}

bool inside(int x, int y) {
  return (x > 0 && y > 0 && x <= n && y <=  m);
}

void bfs(int x, int y, int t) {
  queue<pii> Q; Q.push({x, y});
  mark[x][y] = true;
  while(!Q.empty()) {
    auto [x, y] = Q.front();  Q.pop();
    tplt[t].push_back({x, y});
    for(int i = 0; i < 4; ++i) {
      int nx = x + mv[i].fi,
          ny = y + mv[i].se;
        if(inside(nx, ny) && a[nx][ny] && !mark[nx][ny]) {
          Q.push({nx, ny});
          mark[nx][ny] = true;
        }
    }
  }
}

bool cheo(int i1, int j1, int i2, int j2) {
  if(i1 > i2 && j1 < j2) return 1;
  if(i2 > i1 && j2 < j1) return 1;
  return 0;
}

void sol() {
  int t = 0;
  for(int i = 1; i <= n; ++i)
  for(int j = 1; j <= m; ++j) {
    if(!mark[i][j] && a[i][j]) {
        ++t;
        bfs(i, j, t);
    }
  }
  int ans2 = 0, ans1 = 0, sum = 0;
  for(int i = 1; i <= t; ++i) {
    int lm = tplt[i].size();
    for(int j = 0; j < lm; ++j) {
      auto [i1, j1] = tplt[i][j];
      for(int k = j+1; k < lm; ++k) {
        auto [i2, j2] = tplt[i][k];
        if(cheo(i1, j1, i2, j2)) {
          ++ans2;
        } else if(i1 == i2) {
          bool ok = false;
          for(int d = min(j1, j2); d <= max(j1, j2); ++d)
            if(!a[i1][d]) {
              ok = true;
              break;
            }
          ans2 += ok;
        } else if(j1 == j2) {
          bool ok = false;
          for(int d = min(i1, i2); d <= max(i1, i2); ++d)
            if(!a[d][j1]) {
              ok = true;
              break;
            }
          ans2 += ok;
        }
      }
    }
    ans1 += sum*lm;
    sum += lm;
  }
  if(t == 1) ans1 = 0;
  cout << ans2+ans1;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  freopen("villa.inp", "r", stdin);
  freopen("villa.out", "w", stdout);

  read();
  sol();

  return 0;
}
