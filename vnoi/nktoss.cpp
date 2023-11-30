#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;
const int base = 1e9;
typedef vector<int> BigInt;

void Print(BigInt a) {
  cout << a.back();
	for(int i = a.size()-2; i >= 0; --i) printf("%09d", a[i]);
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
  BigInt c;
  int v = 0, n = a.size(), m = b.size();
  for(int i = 0; i < max(n, m); ++i) {
    if(i < n) v += a[i];
    if(i < m) v += b[i];
    c.push_back(v%base);
    v /= base;
  }
  if(v) c.push_back(v);
  Set(c);
  return c;
}

BigInt operator - (BigInt a, BigInt b) {
  Set(a); Set(b);
  BigInt c;
  int v = 0;  int n = a.size(), m = b.size();
  for(int i = 0; i < n; ++i) {
    v += a[i] - (i < m ? b[i] : 0);
    if(v < 0) {
      c.push_back(v+base);
      v = -1;
    } else {
      c.push_back(v);
      v = 0;
    }
  }
  Set(c);
  return c;
}

int n, k;
BigInt dp[2][maxN+5], sum, m2[maxN+5];

void read() {
  cin >> n >> k;
}

void sol() {
  for(int i = 0; i < k; ++i) dp[0][i] = dp[1][i] = bigint(0);
  dp[0][k] = bigint(1);
  dp[1][k] = bigint(0);

  m2[0] = bigint(1);
  for(int i = 1; i <= n; ++i) m2[i] = m2[i-1] + m2[i-1];

  sum = bigint(0);
  for(int i = k+1; i <= n; ++i) {
    sum = sum + dp[1][i-1] - dp[1][i-k];
    dp[1][i] = dp[0][i-1] + dp[1][i-1];
    dp[0][i] = sum + m2[i-k];
  }
  Print(dp[0][n] + dp[1][n]);
}

int main() {

//  freopen("nktoss.inp", "r", stdin);
//  freopen("nktoss.out", "w", stdout);

  read();
  sol();

  return 0;
}
