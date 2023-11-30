#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int n, a[maxN + 5];
int Left[maxN + 5], Right[maxN + 5];
priority_queue<int, vector<int>, greater<int>> Ql;
priority_queue<int> Qr;

void read() {
    cin >> n;
    for(int i = 1; i <= 3 * n; ++i) cin >> a[i];
}

void sol() {
    int cur_sum = 0;
    for(int i = 1; i <= 3 * n; ++i) {
        cur_sum += a[i];
        Ql.push(a[i]);
        while(Ql.size() > n) {
            cur_sum -= Ql.top();    Ql.pop();
        }
        Left[i] = cur_sum;
    }
    cur_sum = 0;
    for(int i = 3 * n; i >= 1; --i) {
        cur_sum += a[i];
        Qr.push(a[i]);
        while(Qr.size() > n) {
            cur_sum -= Qr.top();    Qr.pop();
        }
        Right[i] = cur_sum;
    }
    int ans = -1e18;
    for(int i = n; i <= 2 * n; ++i) ans = max(ans, Left[i] - Right[i + 1]);
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
