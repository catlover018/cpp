#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;

int n, q, k;
int a[maxN+5], c[maxN+5];
pii query[maxN+5];
  vector<int> v;

void read() {
  cin >> n >> q >> k; ++k;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[i] = a[i];
    v.push_back(a[i]);
  }
  sort(c+1, c+n+1);
  for(int i = 1; i <= q; ++i) {
    int l,r;  cin >> l >> r;
    ++l;  ++r;
    query[i] = make_pair(l, r);
  }
}

void mapping() {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end())-v.begin());
  for(int i = 1; i <= n; ++i) {
    int p = lower_bound(v.begin(), v.end(), a[i]) - v.begin() - 1;
    c[p] = a[i];
    a[i] = p;
  }
}

int T[maxN*4+5], lz[maxN*4+5];
int b[maxN+5];

void init(int node, int l, int r, int val) {
  if(l == r) {
    T[node] = (a[l]>=val);
    lz[node] = -1;
    return;
  }
  int mid = (l+r)>>1;
  init((node<<1), l, mid, val);
  init((node<<1)+1, mid+1, r, val);
  T[node] = T[(node<<1)]+T[(node<<1)|1];
  lz[node] = -1;
}

void push(int node, int l, int r) {
  int mid = (l+r)>>1;
  T[(node<<1)] = lz[node]*(mid - l + 1); lz[(node<<1)] = lz[node];
  T[(node<<1)|1] = lz[node]*(r - mid); lz[(node<<1)|1] = lz[node];
  lz[node] = -1;
}

int get(int node, int l, int r, int u, int v) {
  if(l > r || u > r || l > v) return 0;
  if(u <= l && r <= v) return T[node];
  if(lz[node]!=-1) push(node, l, r);
  int mid = (l+r)>>1;
  int Left = get((node<<1), l, mid, u, v);
  int Right = get((node<<1)|1, mid+1, r, u, v);
  return Left + Right;
}

void update(int node, int l, int r, int u, int v, int val) {
  if(l > r || u > r || l > v) return;
  if(u <= l && r <= v) {
    T[node] = val * (r - l + 1);
    lz[node] = val;
    return;
  }
  if(lz[node]!=-1) push(node, l, r);
  int mid = (l+r)>>1;
  update((node<<1), l, mid, u, v, val);
  update((node<<1)|1, mid+1, r, u, v, val);
  T[node] = T[(node<<1)] + T[(node<<1)|1];
}

bool check(int len) {
  init(1, 1, n, len);
  for(int i = 1; i <= q; ++i) {
    int cur = get(1, 1, n, query[i].fi, query[i].se);
    update(1, 1, n, query[i].se-cur+1, query[i].se, 1);
    update(1, 1, n, query[i].fi, query[i].se-cur, 0);
  }
  int cur = get(1, 1, n, k, k);
  return cur;
}

void sol() {
  int ans = 0, l = 1, r = n;
  while(l <= r) {
    int mid = (l+r)>>1;
    if(check(c[mid])) {
      ans = c[mid];
      l = mid+1;
    } else r = mid-1;
  }
  cout << ans;
}

void sol1() {
  int ans = 0, l = 1, r = n;
  while(l <= r) {
    int mid = (l + r)>>1;
    if(check(c[mid])) {
      ans = c[mid];
      l = mid + 1;
    } else r = mid - 1;
  }
  cout << ans;
}

void sliptsub() {
  sol1();
}

int main() {

  cin.tie(0)->sync_with_stdio(0);

  read();
  sliptsub();

  return 0;
}

