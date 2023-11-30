#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6;

ll a[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void sol() {
    ll q = a[2] - a[1];
    for(int i = 1; i < n; ++i) {
        if(a[i] + q != a[i + 1]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
