#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define SZ(X) (int)(X.size())
#define all(X) X.begin(), X.end()

using namespace std;

const int maxN = 1e6;

string S;
int N, C, cost[maxN+5];
int mark[maxN+5], Time = 0;

void read_input()
{
  cin >> S >> C;
  N = SZ(S);
  S = ' ' + S;
  FOR(i, 1, N) cin >> cost[i];
}

int calcR(int id)
{
  int ans = 0;
  int old = id;
  while(id <= N)
  {
    int x = id, y = N - id + 1;
    if(S[x] != S[y] && mark[x] != Time && mark[y] != Time)
    {
      if(y > old) swap(x, y);
      ans += C + cost[x];
      mark[x] = mark[y] = Time;
    }
    ++id;
  }
  id = old - 1;
  while(id >= 1)
  {
    int x = id, y = N - id + 1;
    if(S[x] != S[y] && mark[x] != Time && mark[y] != Time)
    {
      if(x > old) swap(x, y);
      ans += C + cost[x];
      mark[x] = mark[y] = Time;
    }
    --id;
  }
  return ans;
}

int calcL(int id)
{
  int ans = 0;
  int old = id;
  while(id >= 1)
  {
    int x = id, y = N - id + 1;
    if(S[x] != S[y] && mark[x] != Time && mark[y] != Time)
    {
      if(x > old) swap(x, y);
      ans += C + cost[x];
      mark[x] = mark[y] = Time;
    }
    --id;
  }
  id = old + 1;
  while(id <= N)
  {
    int x = id, y = N - id + 1;
    if(S[x] != S[y] && mark[x] != Time && mark[y] != Time)
    {
      if(y > old) swap(x, y);
      ans += C + cost[x];
      mark[x] = mark[y] = Time;
    }
    ++id;
  }
  return ans;

}

void solve()
{
  FOR(i, 1, N)
  {
    ++Time; int x = calcL(i);
    ++Time; int y = calcR(i);
    cout << x << ' ' << y << ' ';
    return;
  }
  cout << '\n';
}

int main()
{
  file("palin");

  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    read_input();
    solve();
  }


  return 0;
}
