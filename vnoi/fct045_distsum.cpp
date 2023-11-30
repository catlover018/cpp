#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e5;

ll x[maxN + 5], y[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
}

void sol() {
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    ll ans = 0;
    for(int i = 1; i < n; ++i)
        ans += ((x[i + 1] - x[i]) + (y[i + 1] - y[i])) * i * (n - i);
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
