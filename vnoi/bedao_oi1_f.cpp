#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

int n, dp[maxN+5];
string s;

void read(){
  cin >> s;
  n = s.size();
  s = " " + s;
}

int nen(string o, string cur, int i) {
  int len = cur.size();
  int cnt = 1;
  for(; i + len < o.size(); i += len) {
    string tmp = o.substr(i+1, len);
    if(tmp == cur) {
      ++cnt;
    } else break;
  }
  int bonus1 = o.size() - (cnt-1)*len;
  int bonus2 = 0;
  while(cnt>0) {
    cnt/=10;
    ++bonus2;
  }
  return bonus1+bonus2;
}

int cal(int x, int y) {
  int len = y-x+1; int ans = 1e9;
  string cur = s.substr(x, len);
//  cout << cur << " " << x << " " << y << endl;
  for(int i = 0; i < len; ++i) {
    string tmp = "";
    for(int j = i; j < len; ++j) {
      tmp += cur[j];
      int cnt = nen(cur, tmp, j);
      ans = min(ans, cnt);
    }
  }
  return ans;
}

void sol() {
  dp[0] = 0;
  for(int i = 1; i <= n; ++i) {
    dp[i] = i*2;
    for(int j = 1; j < i; ++j) {
      dp[i] = min(dp[i], dp[j-1] + cal(j, i));
    }
//    cout << dp[i] << " ";
  }
  cout << dp[n];
}

int main() {

  freopen("compstr.inp", "r", stdin);
  freopen("compstr.out", "w", stdout);

  read();
  sol();

  return 0;
}
