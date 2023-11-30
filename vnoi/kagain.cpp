#include <bits/stdc++.h>

using namespace std;

const int maxN =  1e5;

int a[maxN+5], n;

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

int Left[maxN+5], Right[maxN+5];
deque<int> Q;

void sol() {
  for(int i = 1; i <= n; ++i) {
    while(Q.size() && a[Q.back()] >= a[i]) Q.pop_back();
    if(!Q.size()) Left[i] = 0;
    else Left[i] = Q.back();
    Q.push_back(i);
  }
  while(!Q.empty()) Q.pop_back();
  for(int i = n; i > 0; --i) {
    while(Q.size() && a[Q.back()] >= a[i]) Q.pop_back();
    if(!Q.size()) Right[i] = n+1;
    else Right[i] = Q.back();
    Q.push_back(i);
  }
  while(!Q.empty()) Q.pop_back();
  int ans = 0, x = -1, y = -1;
  for(int i = 1; i <= n; ++i) {
    int cur = a[i]*(Right[i]-Left[i]-1);
    if(cur > ans) {
      ans = cur;
      x = Left[i] + 1;
      y = Right[i] - 1;
    } else if(cur == ans) {
      if(x > Left[i] + 1) {
        x = Left[i] + 1;
        y = Right[i] - 1;
      }
    }
  }
  cout << ans << " " << x << " " << y << '\n';
}

int main() {

  int testcase; cin >> testcase;

  while(testcase--) {

  read();
  sol();

  }

  return 0;
}
