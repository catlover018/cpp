#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6;

ll pref[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= maxN; ++i) pref[i] = pref[i - 1] + i;
}

void sol() {
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        int u, v;   cin >> u >> v;
        ans += pref[v] - pref[u - 1];
    }
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
