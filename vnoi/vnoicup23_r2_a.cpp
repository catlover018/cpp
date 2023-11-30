#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e3;

int a[maxN+5][maxN+5];
int n, m;

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      char c; cin >> c;
      a[i][j] = c - 'A';
//      cout << a[i][j] << " ";
    }
//    cout << endl;
  }
}

bool check(int x, int y) {
  return (a[x][y] != a[x+1][y] && a[x][y] != a[x][y+1] && a[x+1][y] != a[x][y+1] && a[x][y+1] == a[x+1][y+1]);
}

void sol() {
  for(int i = 1; i < n; ++i)
  for(int j = 1; j < m; ++j) {
    if(check(i, j)) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}

int main() {

  read();
  sol();

  return 0;
}
