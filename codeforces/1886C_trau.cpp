#include <bits/stdc++.h>
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout); }

using namespace std;
using i64 = int64_t;
using f64 = double_t;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
//  file("1886C");
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    string s;
    i64 pos;
    cin >> s >> pos;
    i64 n = s.size(), r = 0;
    while (pos > n - r) {
      pos -= n - r;
      r += 1;
    }
    string t;
    for (char c : s) {
      while (r and not t.empty() and c < t.back()) {
        r -= 1;
        t.pop_back();
      }
      t += c;
    }
    while (r) {
      r -= 1;
      t.pop_back();
    }
    cout << t[pos - 1];
  }
}

