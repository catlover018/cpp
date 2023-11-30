#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ll a, b, c; cin >> a >> b >> c;
    if(a >= b * 2) {
        c -= (a - 2 * b);
        a = 2 * b;
    } else {
        c -= (b - a / 2);
        b = a / 2;
        c -= (a - 2 * b);
        a = 2 * b;
    }
    if(c <= 0) {
        cout << b;
        return 0;
    }
    int tmp = c / 3;
    if(c % 3 != 0) ++tmp;

    cout << max(b - tmp, 0ll);

    return 0;
}
