#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

string s;
int n;

void read() {
  cin >> s;
  int lm = s.size();
  for(int i = 1; i < lm; ++i) {
    if(s[i] >= '0' && s[i] <= '9') continue;
    if(s[i-1] == ')') {
      s.insert(i, "1");
      ++lm;
    }
  }
//  cout << s << endl;
}

stack<int> S;

int convert(char c) {
  if(c >= '0' && c <= '9') return c-'0';
  if(c == '(') return -1;
  if(c == ')') return -2;
  if(c == 'C') return 12;
  if(c == 'H') return 1;
  if(c == 'O') return 16;
  return 0;
}

void sol() {
  for(char c : s) {
      int cur = convert(c);
      if(cur == -2) {
        int sum = 0;
        while(S.size() && S.top() != -1) {
          sum += S.top(); S.pop();
        }
        S.pop();
        S.push(sum);
      } else if(0 <= cur && cur <= 9 && c != 'H') {
        int tmp = S.top();  S.pop();
        S.push(tmp*cur);
      } else S.push(cur);
  }
  int res = 0;
  while(S.size()) {
    res += S.top(); S.pop();
  }
  cout << res;
}

int main() {

  read();
  sol();

  return 0;
}
