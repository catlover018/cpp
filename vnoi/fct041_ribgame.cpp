#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6;

ll Left[maxN + 5], Right[maxN + 5];
int n, m;

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int u, v, c;   cin >> u >> v >> c;
        Left[v] += c;
        Right[u] += c;
    }
}

void sol() {
    for(int i = 2; i <= m; ++i) Left[i] += Left[i - 1];
    for(int i = m - 1; i > 0; --i) Right[i] += Right[i +  1];
    ll ans = 0;
    for(int i = 1; i <= m; ++i) {
        ans = max(ans, Right[i + 1] + Left[i - 1]);
    }
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}

