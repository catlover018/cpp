#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 3e3;

int N, M;
int a[maxN+5][maxN+5];
int f[maxN+5][maxN+5], g[maxN+5][maxN+5];
int pref[maxN+5][maxN+5];

void convert(int x, int y)
{
  int _x = 1001 + x - y;
  int _y = 1 + x + y;
  pref[_x][_y] = a[x][y];
}

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, N) FOR(j, 1, M)
  {
    char c; cin >> c;
    a[i][j] = (c == '*');
    convert(i, j);
  }
}

bool check(int x1, int x2, int x3)
{
  if(x1 == 1 && x2 == 1) return false;
  if(x1 == 1 && x3 == 1) return false;
  return true;
}


int calc(int x, int y, int r)
{
  int _x = 1001 + x - y;
  int _y = 1 + x + y;
  r = r * 2 + 1;
  return pref[_x][_y] - pref[_x - r][_y] - pref[_x][_y - r] + pref[_x - r][_y - r];
}

void solve()
{
  memset(g, 30, sizeof(g));
  FOR(i, 2, N) FOR(j, 2, M)
  {
    if(check(a[i][j], a[i - 1][j], a[i][j - 1]))
      f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
    g[i][j] = min(g[i][j], f[i][j]);
  }

  memset(f, 0, sizeof(f));
  FOR(i, 2, N) FORD(j, M - 1, 1)
  {
    if(check(a[i][j], a[i - 1][j], a[i][j + 1]))
      f[i][j] = min(f[i - 1][j], f[i][j + 1]) + 1;
    g[i][j] = min(g[i][j], f[i][j]);
  }

  memset(f, 0, sizeof(f));
  FORD(i, N - 1, 1) FOR(j, 2, M)
  {
    if(check(a[i][j], a[i + 1][j], a[i][j - 1]))
      f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
    g[i][j] = min(g[i][j], f[i][j]);
  }

  memset(f, 0, sizeof(f));
  FORD(i, N - 1, 1) FORD(j, M - 1, 1)
  {
    if(check(a[i][j], a[i + 1][j], a[i][j + 1]))
      f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
    g[i][j] = min(g[i][j], f[i][j]);
  }

  FOR(i, 1, 2023) FOR(j, 1, 2023)
    pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

  FOR(i, 1, N) g[i][1] = g[i][M] = 0;
  FOR(j, 1, M) g[1][j] = g[N][j] = 0;

  int cnt = 0, x, y, r;
  FOR(i, 1, N) FOR(j, 1, M)
  {
    int cur = calc(i, j, g[i][j]);
    if(cur > cnt)
    {
      cnt = cur;
      x = i;
      y = j;
      r = g[i][j];
    }
  }
  cout << cnt << ' ' << x << ' ' << y << ' ' << r;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("rbull");

  read_input();
  solve();

  return 0;
}
