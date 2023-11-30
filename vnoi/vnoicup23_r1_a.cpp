#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;

int n;
int f[maxN+5];

void read() {
  cin >> n;
  for(int i = 1; i <= n; ++i) cin >> f[i];
}

void sol() {
  for(int i = 1; i <= n; ++i) {
    if(f[f[f[i]]] == i) {
      cout << "<3";
      return;
    }
  }
  cout << "</3";
}

int main() {

  int testcase; cin >> testcase;

  while(testcase--) {
    read();
    sol();
    cout << '\n';
  }

  return 0;
}
