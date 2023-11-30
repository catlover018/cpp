#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 2e3;
const int maxV = 1e6;

int a[maxN+5][maxN+5], n, m;
int g[maxV+5];

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
}

int Left[maxV+5], Right[maxV+5];
void sol() {
  deque<int> Q;
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      if(a[i][j] == 0) g[j] = 0;
      else ++g[j];
    }
    for(int j = 1; j <= m; ++j) {
      while(Q.size() && g[Q.back()] >= g[j]) Q.pop_back();
      if(!Q.size()) Left[j] = 0;
      else Left[j] = Q.back();
      Q.push_back(j);
    }
    while(!Q.empty()) Q.pop_back();
    for(int j = m; j > 0; --j) {
      while(Q.size() && g[Q.back()] >= g[j]) Q.pop_back();
      if(!Q.size()) Right[j] = m+1;
      else Right[j] = Q.back();
      Q.push_back(j);
    }
    while(!Q.empty()) Q.pop_back();
    for(int j = 1; j <= m; ++j) {
      ans = max(ans, g[j] * (Right[j] - Left[j] - 1));
    }
  }
  cout << ans;
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
