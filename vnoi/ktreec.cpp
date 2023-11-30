#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4;
const int maxC = 1e2;

int d[maxC + 5][maxN + 5];
vector<int> adj[maxN + 5];
vector<int> c[maxC + 5];
int m, n;

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for(int i = 1; i <= n; ++i) {
        int x;  cin >> x;
        c[x].push_back(i);
    }
}

void bfs(int cur_col) {
    queue<int> Q;
    for(int i = 1; i <= n; ++i) d[cur_col][i] = 1e9;
    for(int x : c[cur_col]) {
        d[cur_col][x] = 0;
        Q.push(x);
    }
    while(!Q.empty()) {
        int u = Q.front();    Q.pop();
        for(int v : adj[u]) {
            if(d[cur_col][v] > d[cur_col][u] + 1) {
                d[cur_col][v] = d[cur_col][u] + 1;
                Q.push(v);
            }
        }
    }
}

void sol() {
    for(int i = 1; i <= m; ++i) bfs(i);
    int query;  cin >> query;
    while(query--) {
        int cur_col, x; cin >> x >> cur_col;
        cout << d[cur_col][x] << '\n';
    }
}

int main() {

    read();
    sol();

    return 0;
}
