#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)

using namespace std;

const int maxN = 300;

int N;
int cnt[4];
long double f[maxN+5][maxN+5][maxN+5];

void read_input()
{
  cin >> N;
  FOR(i, 1, N)
  {
    int x;  cin >> x;
    ++cnt[x];
  }
}

long double dp(int x, int y, int z)
{
  if(x < 0 || y < 0 || z < 0) return 0;
  if(x == 0 && y == 0 && z == 0) return 0;
  if(f[x][y][z] > 0) return f[x][y][z];
  double cur = N + x * dp(x - 1, y, z) + y * dp(x + 1, y - 1, z) + z * dp(x, y + 1, z - 1);
  return f[x][y][z] = cur / (x + y+ z);
}

void solve()
{
  memset(f, -1, sizeof(f));
  cout << fixed << setprecision(10) << dp(cnt[1], cnt[2], cnt[3]);
}

int main()
{
  file("atcoder_dp_j");

  read_input();
  solve();

  return 0;
}
