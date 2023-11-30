#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll a, b;

void read() {
    cin >> a >> b;
}

void sol() {
    if(a * 2 > b) {
        cout << "No\n";
        return;
    }
    ll c = b - 2 * a; a &= c;
    cout << (a  ? "No" : "Yes") << '\n';
}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--) {

        read();
        sol();

    }

    return 0;
}
