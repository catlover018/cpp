#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

string s;

void read() {
  cin >> s;
}

void sol() {
  int n = s.size();
  bool ok = (s[0] == 'B' || s[n-1] == 'B');
  for(int i = 0; i < n-1; ++i)
      if(s[i] == s[i+1] && s[i] == 'B') ok = true;
  int cnt = 0, total = 0, mn = 1e9;
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'A') ++cnt;
    else {
      total += cnt;
      mn = min(mn, cnt);
      cnt = 0;
    }
  }
  if(cnt > 0) {
    total += cnt;
    mn = min(mn, cnt);
  }
  if(!ok) total -= mn;
  cout << total << '\n';
}

int main() {

  int testcase; cin >> testcase;

  while(testcase--) {

  read();
  sol();

  }

  return 0;
}
