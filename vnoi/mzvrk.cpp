#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e15;

int a, b;

int get(int n) {
  int res = 0, i = 1;
  while(i <= n) {
    res += i*(n/i - n/(i<<1));
//    cout << i*(n/i - n/(i<<1)) << ' ' << i << endl;
    i <<= 1;
  }
  return res;
}

void sol() {
  cin >> a >> b;
  cout << get(b) - get(a-1);
}

int32_t main() {

  sol();

  return 0;
}
