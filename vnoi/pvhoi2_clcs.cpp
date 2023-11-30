#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)

using namespace std;

const int maxN = 3000;

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

int N, M, R, C, lm = 0;
int a[maxN+5][maxN+5], b[maxN+5][maxN+5];

void read_input()
{
  read(N);  read(M);  read(R);  read(C);
  FOR(i, 1, N) FOR(j, 1, M)
  {
    read(a[i][j]);
    lm = max(lm, a[i][j]);
  }
}

bool check(int val)
{
  FOR(i, 1, N)  FOR(j, 1, M)
  {
    b[i][j] = (a[i][j] >= val ? 1 : 0);
    b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
  }
  FOR(i, 1, N - R + 1)  FOR(j, 1, M - C + 1)
  {
    int u = i + R - 1, v = j + C - 1;
    int cur = b[u][v] - b[i - 1][v] - b[u][j - 1] + b[i - 1][j - 1];
    if(cur >= (R * C + 1) / 2) return true;
  }
  return false;
}

void sol()
{
  int ans = 0, l = 1, r = lm;
  while(l <= r)
  {
    int mid = (l + r) / 2;
    if(check(mid))
    {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << ans;
}

int main()
{
  file("pvhoi2_clcs");

  read_input();
  sol();

  return 0;
}
