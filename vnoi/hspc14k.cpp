#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1e3;

int BIT2d[maxN+5][maxN+5],
    BIT1x[maxN+5][maxN+5],
    BIT1y[maxN+5][maxN+5],
    BIT1d[maxN+5][maxN+5];
int N, M, Q;

void read_input()
{
  cin >> N >> M >> Q;
}

void update(int BIT[maxN+5][maxN+5], int x, int y, int val)
{
  for(; x <= N; x += (x&-x))
    for(int v = y; v <= M; v += (v&-v))
      BIT[x][v] += val;
}

void update(int x, int y, int u, int v, int val)
{
  update(BIT2d, x, y, val);
  update(BIT2d, x, v + 1, -val);
  update(BIT2d, u + 1, y, -val);
  update(BIT2d, u + 1, v + 1, val);

  int val1 = (1 - y) * val;
  int val2 = (v - y + 1) * val;
  update(BIT1x, x, y, val1);
  update(BIT1x, x, v + 1, val2 - val1);
  update(BIT1x, u + 1, y, -val1);
  update(BIT1x, u + 1, v + 1, val1 - val2);

  int val3 = (1 - x) * val;
  int val4 = (u - x + 1) * val;
  update(BIT1y, x, y, val3);
  update(BIT1y, u + 1, y, val4 - val3);
  update(BIT1y, x, v + 1, -val3);
  update(BIT1y, u + 1, v + 1, val3 - val4);

  int val5 = (x - 1) * (y - 1) * val;
  int val6 = (1 - x) * (v - y + 1) * val;
  int val7 = (1 - y) * (u - x + 1) * val;
  int val8 = (u - x + 1) * (v - y + 1) * val;
  update(BIT1d, x, y, val5);
  update(BIT1d, x, v + 1, val6 - val5);
  update(BIT1d, u + 1, y, val7 - val5);
  update(BIT1d, u + 1, v + 1, val8 + val5 - val6 - val7);

}

int get(int BIT[maxN+5][maxN+5], int x, int y)
{
  int res = 0;
  for(; x > 0; x -= (x&-x))
    for(int v = y; v > 0; v -= (v&-v))
      res += BIT[x][v];
  return res;
}

int get(int x, int y)
{
  return get(BIT2d, x, y) * x * y
            + get(BIT1x, x, y) * x
              + get(BIT1y, x, y) * y
                + get(BIT1d, x, y);
}

int get(int x, int y, int u, int v)
{
  return get(u, v) - get(u, y - 1) - get(x - 1, v) + get(x - 1, y - 1);
}

void solve()
{
  while(Q --> 0)
  {
    int type; cin >> type;
    if(type == 1)
    {
      int u, v, x, y, val; cin >> x >> y >> u >> v >> val;
      update(x, y, u, v, val);
    }
    else
    {
      int u, v, x, y; cin >> x >> y >> u >> v;
      cout << get(x, y, u, v) << '\n';
    }
  }
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("hspc14k");

  read_input();
  solve();

  return 0;
}
