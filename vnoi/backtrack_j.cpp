#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 100;

int c[maxN+5][maxN+5];
int N, M;

void read_input()
{
  cin >> N >> M;
  FOR(i, 1, N)   FOR(j, 1, M)
  {
    char ch; cin >> ch;
    c[i][j] = (ch == '.' ? 1 : 0);
  }
}

void check()
{
  bool ok = false;
  FOR(i, 1, N) FOR(j, 1, M)
  {
    ok |= c[i][j];
    if(ok) return;
  }
  cout << "YES";
  exit(0);
}

void gen()
{
  check();
  int cnt = 0;
  FOR(i, 1, N - 1)
  {
    FOR(j, 1, M - 1)
    {
      cnt += 2;
      assert(cnt <= 18);
      if(c[i][j] && c[i + 1][j] && c[i + 1][j + 1])
      {
        c[i][j] = c[i + 1][j] = c[i + 1][j + 1] = 0;
        gen();
        c[i][j] = c[i + 1][j] = c[i + 1][j + 1] = 1;
      }
      if(c[i][j + 1] && c[i + 1][j] && c[i + 1][j + 1])
      {
        c[i][j + 1] = c[i + 1][j] = c[i + 1][j + 1] = 0;
        gen();
        c[i][j + 1] = c[i + 1][j] = c[i + 1][j + 1] = 1;
      }
    }
  }
}

void solve()
{
  gen();
  cout << "NO";
}

int main()
{
  file("backtrack_j");

  read_input();
  solve();

  return 0;
}
