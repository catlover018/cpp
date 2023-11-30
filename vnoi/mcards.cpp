#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int p[4] = {0, 1, 2, 3};

struct card {
  int col, val;
  bool operator < (const card& o) const {
    return col != o.col ? p[col] < p[o.col] : val < o.val;
  }
};

int c, n;
card a[maxN+5], last[maxN+5];

void read() {
  cin >> c >> n;
  for(int i = 0; i < c*n; ++i) {
    cin >> a[i].col >> a[i].val;
    --a[i].col;
  }
}

void sol() {
  int ans = n*c;
  do {
    int maxlen = 0;
    for(int i = 0; i < n*c; ++i) {
      int dp = lower_bound(last, last+maxlen, a[i])-last;
      if(dp >= maxlen) last[maxlen++] = a[i];
      else {
        last[dp] = min(last[dp], a[i]);
      }
    }
//    cout << maxlen << endl;
    ans = min(ans, n*c-maxlen);
  } while(next_permutation(p, p+c));
  cout << ans;
}

int main() {

  read();
  sol();

  return 0;
}
