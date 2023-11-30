#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ll n;   cin >> n;
    ll res = 1;
    while(n > 0) {
        if(n % 2 == 0) res *= 2;
        n /= 2;
    }
    cout << res;

    return 0;
}
