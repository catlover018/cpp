#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, x;
int a[maxN], b[maxN];

void read() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
}

void sol() {
    bool check = true;
    for(int i = 1; i < n; ++i) {
        if(a[i] > a[i + 1]) check = false;
    }
    if(check) {
        cout << "YES\n";
        return;
    }
    sort(b + 1, b + n + 1);
    for(int i = n - x + 1; i <= x; ++i) {
        if(a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--) {
        read();
        sol();
    }

    return 0;
}
