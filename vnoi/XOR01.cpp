#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int mp[maxN+5];

int main()
{
  int n;  cin >> n;
  long long ans = 0;
  while(n --> 0)
  {
    int x;  cin >> x;
    ans += mp[x >> 1];
    mp[x >> 1]++;
  }
  cout << ans;

  return 0;
}
