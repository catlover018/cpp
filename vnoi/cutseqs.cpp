#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int inf = 1e18;

int a[maxN+5], T[maxN*4+5], dp[maxN+5], n, m;

void read() {
  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];
}

deque<int> Q;

void build(int node, int l, int r) {
  if(l == r) {
    T[node] = inf;
    return;
  }
  int mid = (l+r)/2;
  build(node*2, l, mid);
  build(node*2+1, mid+1, r);
  T[node] = min(T[node*2], T[node*2+1]);
}

void update(int node, int l, int r, int u, int v, int val) {
  if(l > v || u > r || l > r) return ;
  if(u <= l && r <= v) {
    T[node] = val;
    return;
  }
  int mid = (l+r)/2;
  update(node*2, l, mid, u, v, val);
  update(node*2+1, mid+1, r, u, v, val);
  T[node] = min(T[node*2], T[node*2+1]);
}

void sol() {
  int sum = 0;
  build(1, 1, n);
  for(int i = 1, j = 1; i <= n; ++i) {
    if(a[i] > m) {
      cout << -1;
      return;
    }
    sum += a[i];
    while(sum > m) sum -= a[j++];
    while(Q.size() > 0 && a[Q.back()] <= a[i]) {
      int id = Q.back();
      update(1, 1, n, id, id, inf);
      Q.pop_back();
    }
    while(Q.front() < j && Q.size() > 0) {
      int id = Q.front();
      update(1, 1, n, id, id, inf);
      Q.pop_front();
    }
    if(Q.size() == 0) {
      update(1, 1, n, i, i, a[i] + dp[j-1]);
    } else {
      update(1, 1, n, Q.front(), Q.front(), a[Q.front()] + dp[j-1]);
      update(1, 1, n, i, i, a[i] + dp[Q.back()]);
    }
    Q.push_back(i);
    dp[i] = T[1];
  }
//  for(int i = 1; i <= n; ++i) cout << dp[i] << " ";
  cout << dp[n];
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sol();

  return 0;
}
