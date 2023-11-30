#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define fi first
#define se second
#define SZ(X) (int)(X.size())

using namespace std;

typedef vector<int> BigInt;

const int maxN = 1e5;
const int base = 1e4;

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

int S, N;
__int128 f[maxN+5], g[maxN+5];

void Print(__int128 x)
{
  if(x > 9) Print(x / 10);
  putchar(x % 10 + '0');
}

void solve()
{
  read(S);  read(N);
  FOR(i, 1, S) f[i] = 0, g[i] = 0;
  f[0] = 1;
  FOR(_, 1, N)
  {
    int c, m;
    read(c);  read(m);
    FOR(i, c, S)
    {
      g[i] = f[i - c];
      g[i] = g[i] + g[i - c];
      if(i >= (m + 1) * c) g[i] = g[i] - f[i - (m + 1) * c];
    }
    FOR(i, 1, S)
    {
      f[i] = f[i] + g[i];
      g[i] = 0;
    }
  }
  Print(f[S]);
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("qbmarket");

  solve();

  return 0;
}
