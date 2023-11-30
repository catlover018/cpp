#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e5;

int a[maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
}

bool check(int val) {
    int p = lower_bound(a + 1, a + n + 1, val) - a;
    return (n - p + 1 >= val);
}

void sol() {
    int ans = 0, l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
