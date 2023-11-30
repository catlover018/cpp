#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, m, ans = 0;
vector<int> adj[maxN+5];
int f[maxN+5];

void read() {
  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int num[maxN+5], low[maxN+5];
int Time = 0;
void dfs(int u, int p) {
  num[u] = low[u] = ++Time;
  f[u] = 1;
  for(int v : adj[u]) {
    if(v == p) continue;
    if(!num[v]) {
      dfs(v, u);
      f[u] += f[v];
      low[u] = min(low[u], low[v]);
      if(low[v] == num[v]) {
        ans += f[v]*(n-f[v]);
      }
    } else low[u] = min(low[u], num[v]);
  }
}

void sol() {
    ans = 0;
    dfs(1, 1);
    cout << ans;
}

int32_t main() {

  freopen("DDK.inp", "r", stdin);
  freopen("DDK.out", "w", stdout);

  read();
  sol();

  return 0;
}
