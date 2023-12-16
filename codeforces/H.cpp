#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 1e6;

int a[maxN+5], st, ed;
vector<pii> adj[maxN+5];
int bridge[maxN+5], n;

void read() {
  cin >> n >> st >> ed;
  for(int i = 1; i <= n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }
}

int num[maxN+5], low[maxN+5];
int Time = 0;
void dfs(int u, int p) {
  num[u] = low[u] = ++Time;
  for(auto [v, id] : adj[u]) {
    if(v == p) continue;
    if(!num[v]) {

    }
  }
}

void sol() {

}

int main() {

  return 0;
}
