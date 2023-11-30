#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a[maxN+5], n;

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

deque<int> Q;
int Left[maxN+5], Right[maxN+5];

void sol() {
  for(int i = 1; i <= n; ++i) {
    while(Q.size() && a[Q.back()] >= a[i]) Q.pop_back();
    if(Q.empty()) Left[i] = 0;
    else Left[i] = Q.back();
    Q.push_back(i);
  }
  while(!Q.empty()) Q.pop_back();
  for(int i = n; i > 0; --i) {
    while(Q.size() && a[Q.back()] >= a[i]) Q.pop_back();
    if(Q.empty()) Right[i] = n+1;
    else Right[i] = Q.back();
    Q.push_back(i);
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    int cur1 = a[i], cur2 = Right[i]-Left[i]-1;
    if(cur2 >= cur1) ans = max(ans, cur1);
  }
  cout << ans;
}

//2
//1 2

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
