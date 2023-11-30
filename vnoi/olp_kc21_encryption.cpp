#include <bits/stdc++.h>

#define int long long

using namespace std;

int l, r, a, k;

int32_t main() {

    cin >> l >> r >> a >> k;

    int tmp = k /__gcd(a, k);

    cout << r / tmp - (l - 1) / tmp;

    return 0;
}
