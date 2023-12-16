#include <bits/stdc++.h>

using namespace std;

const int maxN = 100;

int a[maxN+5][maxN+5];

void init() {
  for(int i = 1; i <= 10; ++i)
    a[1][i] = a[10][i] = 1;
  for(int i = 2; i <= 9; ++i)
    a[2][i] = a[9][i] = 2;
  for(int i = 3; i <= 8; ++i)
    a[3][i] = a[8][i] = 3;
  for(int i = 4; i <= 7; ++i)
    a[4][i] = a[7][i] = 4;
  for(int i = 5; i <= 6; ++i)
    a[5][i] = a[6][i] = 5;
  for(int i = 1; i <= 10; ++i)
    a[i][1] = a[i][10] = 1;
  for(int i = 2; i <= 9; ++i)
    a[i][2] = a[i][9] = 2;
  for(int i = 3; i <= 8; ++i)
    a[i][3] = a[i][8] = 3;
  for(int i = 4; i <= 7; ++i)
    a[i][4] = a[i][7] = 4;
  for(int i = 5; i <= 6; ++i)
    a[i][5] = a[i][6] = 5;
}

int main() {

  init();
  int testcase; cin >> testcase;
  while(testcase--) {
    int ans = 0;
    for(int i = 1; i <= 10; ++i)
    for(int j = 1; j <= 10; ++j) {
      char c; cin >> c;
      if(c == 'X') ans += a[i][j];
    }
    cout << ans << '\n';
  }

  return 0;
}
