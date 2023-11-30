#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n;

void read() {
    cin >> n;
}

void sol() {
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) n /= 2;
        else n = n*3 + 1;
    }
    cout << n << " ";
}

int32_t main() {

    read();
    sol();

    return 0;
}
