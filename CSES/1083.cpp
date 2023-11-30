#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, a[maxN+5];

void read() {
    cin >> n;
    for(int i = 1; i < n; ++i) cin >> a[i];
    sort(a+1, a+n);
}

void sol() {
    for(int i = 1; i <= n; ++i)
    if(a[i] != i) {
        cout << i;
        return;
    }
}

int32_t main() {

    read();
    sol();

    return 0;
}
