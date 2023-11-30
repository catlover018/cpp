#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int k, n, len[maxN+5];
vector<int> d[maxN+5];
int val[maxN+5];

void read() {
  cin >> k;
  vector<int> v;
  for(int i = 1; i <= k; ++i) cin >> len[i];
  for(int i = 1; i <= k; ++i) {
    for(int j = 1; j <= len[i]; ++j) {
      int x;  cin >> x;
      d[i].push_back(x);
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end())-v.begin());
  for(int i = 1; i <=  k; ++i) {
    for(int j = 0; j < len[i]; ++j) {
      int p = lower_bound(v.begin(), v.end(), d[i][j]) - v.begin() + 1;
      val[p] = d[i][j];
      d[i][j] = p;
    }
  }
}

int cnt[maxN+5], mark[maxN+5];

void sol() {
  for(int i = 1; i <= k; ++i) {
    for(int j = 0; j < len[i]; ++j) {
      if(!mark[d[i][j]]) {
        ++cnt[d[i][j]];
        mark[d[i][j]] = true;
      }
    }
    for(int j = 0; j < len[i]; ++j) {
        mark[d[i][j]] = false;
    }
  }
  vector<int> res;
  for(int i = 0; i < len[1]; ++i)
    if(cnt[d[1][i]] == k && !mark[d[1][i]]) {
      res.push_back(d[1][i]);
      mark[d[1][i]] = 1;
    }
  if(res.size() == 0) {
    cout << 'x';
  } else {
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); ++i)
      cout << val[res[i]] << " ";
  }
}

int main() {

  freopen("PTC.inp", "r", stdin);
  freopen("PTC.out", "w", stdout);

  read();
  sol();

  return 0;
}
