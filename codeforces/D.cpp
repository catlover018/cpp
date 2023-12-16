#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 2e5 + 5;

int n, k;
string s;

void read() {
    int ans = 0; int i = 1;
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    while(i <= n) {
        if(s[i] == 'B') {
            i+=k;
            ans++;
        } else ++i;
    }
    cout << ans << '\n';
}

int32_t main () {

    int testcase;   cin >> testcase;

    while(testcase--) {
      read();
    }
    return 0;
}
