#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1e6;

void read(){}
template <typename Head, typename ...Tail>
void read(Head &H, Tail &...T)
{
    int sign = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-') sign = 1;
    H = c - '0';
    for (c = getchar(); isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign) H = -H;
    read(T...);
}

struct Switch
{
  int x, y;
  Switch() { x = -1; y = -1; }
  Switch(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
};

int N, M, K;
vector<vector<int>> a;
vector<vector<Switch>> d;

void read_input()
{
  read(N);  read(M);  read(K);
  vector<vector<int>> base(N + 5, vector<int> (M + 5));
  vector<vector<Switch>> tmp(N + 5, vector<Switch> (M + 5));
  a = base;
  d = tmp;
  FOR(i, 1, N) FOR(j, 1, M) read(a[i][j]);
  FOR(i, 1, K)
  {
    int x, y;
    read(x);  read(y);
    read(d[x][y].x);  read(d[x][y].y);
  }
}

bool inside(int x, int y, int u, int v, int i, int j)
{
  return (x == i && i <= u && y == j && j <= v);
}

void update(int x, int y, int u, int v, int val, vector<vector<int>> &a)
{
  a[x][y] = (a[x][y] + val) % 3;
  a[x][v + 1] = (a[x][v + 1] - val + 3) % 3;
  a[u + 1][y] = (a[u + 1][y] - val + 3) % 3;
  a[u + 1][v + 1] = (a[u + 1][v + 1] + val) % 3;
}

int calc(int t, vector<vector<int>> a)
{
  int ans = 0;
  vector<vector<int>> pref(N + 5, vector<int> (M + 5, 0));
  FOR(i, 1, N) FOR(j, 1, M)
  {
    pref[i][j] = (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j]) % 3;
    if((a[i][j] + pref[i][j]) % 3 != t)
    {
      int dis = (t - a[i][j] - pref[i][j] + 3) % 3;
      if(d[i][j].x == -1) return -1;
      update(i, j, d[i][j].x, d[i][j].y, dis, pref);
      ans += dis;
    }
  }
//  FOR(i, 1, N) { FOR(j, 1, M) cout << a[i][j] << ' '; cout << endl; }
  return ans;
}

void solve()
{
  int A = calc(1, a);
  int B = calc(2, a);
  if(A == -1 && B == -1) cout << -1;
  else
  {
    if(A == -1) cout << B;
    else if(B == -1) cout << A;
    else cout << min(A, B);
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("voi20_light");

  read_input();
  solve();

  return 0;
}
