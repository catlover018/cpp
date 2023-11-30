#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {

    int testcase;   cin >> testcase;

    while(testcase--) {
        int t, k, n;    cin >> t >> k >> n;
        if(t > n) {
            cout << 0 << '\n';
            continue;
        }
        cout << (n - t) / k + 1 << '\n';
    }

    return 0;
}
