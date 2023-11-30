#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int a, b;

string sub2(string a, string b) {
  while(a.size() < b.size()) a = '0' + a;
  while(b.size() < a.size()) b = '0' + b;
  int lm = a.size();
  int nho = 0;
  string res = "";
  for(int i = lm-1; i >= 0; --i) {
    int c = a[i] - b[i] - nho;  nho = 0;
    if(c < 0) {
      c += 2;
      nho = 1;
    }
    res = char(c + '0') + res;
  }
  while(res.size() > 1 && res[0] == '0') res.erase(0, 1);
  return res;
}

int convert(string s) {
  int ans = 0, lm = s.size();
  for(int i = lm-1, cur = 0; i >= 0; --i, ++cur) {
    if(s[i] == '1') {
      ans += (1 << cur);
    }
  }
  return ans;
}

string s[maxN+5];

int get(string n) {
  int lm = n.size();
  s[lm+1] = '0';
  for(int i = lm, j = 0; i > 0; --i, ++j) {
    s[i] = s[i+1] + n[j];
  }
  int bonus = 1;
  int ans = 0;
  for(int i = 1; i <= lm; ++i) {
    string sub = sub2(s[i], s[i+1]);
    ans += convert(sub) * bonus;
    bonus <<= 1;
  }
  return ans;
}

void read() {
  cin >> a >> b;
}

string convert2(int n) {
  string ans = "";
  while(n > 0) {
    ans = char((n&1)+'0') + ans;
    n >>= 1;
  }
  return ans;
}

string s1, s2;

void sol() {
  string s1 = convert2(a-1), s2 = convert2(b);
  cout << get(s2) - get(s1);
}

int32_t main() {

  read();
  sol();

  return 0;
}
