#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5;

int n, m, q;
vector<int> adj[maxN+5];

void read() {
  cin >> n >> m >> q;
  for(int i = 1; i <= m; ++i) {
   int u, v;  cin >> u >> v;
   adj[u].push_back(v);
   adj[v].push_back(u);
  }
}

int num[maxN+5], low[maxN+5];
int Time = 0;

void dfs(int u) {
  num[u] = low[u] = ++Time;
  for(int v : adj[u]) {
    if(!num[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);

    } else {
      low[u] = min(low[u], num[v]);
    }
  }
}


int main() {

  read();
  sol();

  return 0;
}
