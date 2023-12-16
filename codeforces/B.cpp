#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

void read() {
    cin >> n;
    long long res = 1;
    vector<int> adj; adj.resize(n);
    int dem = 0;
    int min_value = 1e9;
    int lm = adj.size();
    for(int i = 0; i < lm; ++i) {
        int tmp; cin >> tmp;
        if(tmp) {
          res *= tmp;
          min_value = min(min_value, tmp);
        }
        if(tmp == 0) dem ++;
    }
    if(dem > 1) {
      cout << 0 << '\n';
      return;
    }
    if(dem == 0) {
      cout << res / min_value * (min_value + 1) << '\n';
      return;
    }
    cout << res << '\n';
}

int32_t main () {

    int testcase; cin >> testcase;

    while(testcase--) {
      read();

    }
    return 0;
}
