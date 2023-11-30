#include <bits/stdc++.h>

using namespace std;

int n;

void read() {
    cin >> n;
}

void sol() {
    int cnt = 0;
    while(n > 1) {
        if(n % 3 != 0) {
            cout << -1 << '\n';
            return;
        }
        if(n % 6 == 0) n /= 6, cnt += 1;
        else n /= 3, cnt += 2;
    }
    cout << cnt << '\n';
}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--) {

        read();
        sol();

    }

    return 0;
}
