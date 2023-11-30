#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, q;
vector<int> a[maxN+5];

void read() {
  cin >> n >> q;
}

void sol() {

}

void trau() {
  int mn = 1e18;
  for(int i = 1; i <= n; ++i) {
    int x;  cin >> x;
    mn = min(mn, x);
    a[0].push_back(x);
  }
  cout << mn << " ";
  for(int i = 1; i <= q; ++i) {
    int type, id, val;
    cin >> type >> id >> val;
    mn = 1e18;
    if(type == 1) {
      for(int x : a[id]) {
        a[i].push_back(x);
        mn = min(mn, x);
      }
      a[i].push_back(val);
      mn = min(mn, val);
    } else {
      for(int x : a[id]) {
        int cur_val = (x^val);
        a[i].push_back(cur_val);
        mn = min(mn, cur_val);
      }
    }
    cout << mn << " ";
  }
}

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  freopen("copyarray.inp", "r", stdin);
  freopen("copyarray.out", "w", stdout);

  read();
  trau();

  return 0;
}
