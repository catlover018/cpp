#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

struct Query {
  int l, r, len, type;
  Query() {l = 0; r = 0; len = 0; type = -1;}
  Query(int _l, int _r, int _len, int _type) {
    l = _l; r = _r;
    len = _len; type = _type;
  }
};

int n, m;
int par[maxN+5], cnt[maxN+5];
Query q[maxN+5];

void read() {
  cin >> n >> m;
  set<int> s;
  for(int i = 1; i <= m; ++i) {
    int l, r; string s;
    int type = -1;
    cin >> l >> r >> s;
    s.insert(l);  s.insert(r);
    if(s == "even") type = 0;
    else type = 1;
    q[i] = Query(l, r, (r-l+1)%2, type, i);
  }
  vector<int> v(s.begin(), s.end());
  for(int i = 1; i <= m; ++i) {
    q[i].l = lower_bound(v.begin(), v.end(), q[i].l) - v.begin() + 1;
    q[i].r = lower_bound(v.begin(), v.end(), q[i].r) - v.begin() + 1;
  }
  for(int i = 1; i < maxN; ++i) {
      par[i] = i;
      cnt[i] = -1;
  }
}

int Find(int u) {
  return (u == par[u] ? u : (par[u] = Find(par[u])));
}

void sol() {
  for(int i = 1; i <= m; ++i) {
    auto [l, r, len, type] = q[i];
    l = Find(l);  r = Find(r);
    if(cnt[l] == -1) {

    }N
  }
}

int main() {

  return 0;
}
