#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 5e5;

ll a[maxN+5];
int N, P;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  cin >> N >> P;
  for(int i = 1; i <= N; ++i) cin >> a[i];


  set<pii> s; s.insert({0, 0});
  int ans = -1, sum = 0;
  for(int i = 1; i <= N; ++i)
  {
    sum += a[i];
    for(auto [x, id] : s)
    {
      if(sum - x < P) break;
      ans = max(ans, i - id);
    }
    s.insert({sum, i});
  }

  cout << ans;

  return 0;
}
