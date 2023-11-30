#include <bits/stdc++.h>

using namespace std;

int main() {

    string ans = "";
    bool ok = true;
    for(int i = 1; i <= 5; ++i) {
        int x;  cin >> x;
        if(x == 1) {
            ok = false;
            ans = char(i + '0') + ans;
        }
    }
    if(ok) cout << 0;
    else cout << ans;

    return 0;
}
