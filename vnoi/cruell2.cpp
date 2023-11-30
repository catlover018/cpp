#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6 + 5;
const double lm = 1e6;
const double eps = 0.0000001;

int n;
double a[maxN];

void read() {
    cin >> n;
    for(int i = 0; i <= n; ++i) cin >> a[i];
}

double f(double x) {
    double ans = 0, cur_x = 1;
    for(int i = 0; i <= n; ++i) {
        ans += a[i] * cur_x;
        cur_x *= x;
    }
    return ans;
}

void sol() {
    double l = -lm, r = lm, res = 0;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(f(mid) * f(l) <= 0) {
            res = mid;
            r = mid;
        } else l = mid;
    }
    ll ans = res * 1000;
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
