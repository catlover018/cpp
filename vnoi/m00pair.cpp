#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;
const int base = 1e9;
typedef vector<int> BigInt;

void Print(BigInt a) {
  cout << a.back();
  int lm = a.size();
  for(int i = lm-2; i >= 0; --i)
    printf("%09d", a[i]);
  cout << '\n';
}

void Set(BigInt &a) {
  while(a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt bigint(int x) {
  BigInt a; a.push_back(x);
  return a;
}

BigInt operator + (BigInt a, BigInt b) {
  Set(a); Set(b);
  BigInt res;
  int nho = 0, n = a.size(), m = b.size();
  for(int i = 0; i < max(n, m); ++i) {
    if(i < n) nho += a[i];
    if(i < m) nho += b[i];
    res.push_back(nho%base);
    nho/=base;
  }
  if(nho) res.push_back(nho);
  Set(res);
  return res;
}

BigInt dp[maxN+5][2], m2[maxN+5];

void init(int n) {
  m2[0] = bigint(1);
  for(int i = 1; i <= n; ++i) {
    m2[i] = m2[i-1] + m2[i-1];
  }

  dp[1][1] = bigint(1); dp[1][0] = bigint(0);
  for(int i = 2; i <= n; ++i) {
    dp[i][1] = dp[i-1][0] + m2[i-2];
    dp[i][0] = dp[i-1][1];
  }
}

void sol() {
  int x;
  while(cin >> x) {
    Print(dp[x][0]);
  }
}

int main() {

//  freopen("test.inp", "r", stdin);

  init(1e4);
  sol();

  return 0;
}
