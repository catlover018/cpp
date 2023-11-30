#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {

    int testcase;   cin >> testcase;

    while(testcase--) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        bool ok = false;
        int ans = 1e9;
        for(int i = 0; i <= 100000; ++i) {
            int tmp = (a+i)*x - b*y;
            if(tmp % y == 0 && tmp >= 0) {
                int _y  = tmp/y;
                ans = min(ans, _y+i);
                ok = true;
            }
        }
        for(int i = 0; i <= 100000; ++i) {
            int tmp = (b+i)*y - a*x;
            if(tmp%x==0 && tmp >= 0) {
                int _x = tmp/x;
                ans = min(ans, _x+i);
                ok = true;
            }
        }
        if(ok == false) ans = -1;
        cout << ans << '\n';

    }

    return 0;
}
