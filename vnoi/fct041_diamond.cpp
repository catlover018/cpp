#include <bits/stdc++.h>

#define int long long

using namespace std;

const double eps = 1e-12;
const int maxN = 1e5;

int a[maxN + 5], b[maxN + 5];
int n, k;

void read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
}

#define fi first
#define se second

pair<double, int> c[maxN + 5];
void sol() {
    int x, y;
    double l = 0, r = 1e6;
    for(int _ = 0; _ < 100; ++_) {
        double mid = (l + r) / 2;
        for(int i = 1; i <= n; ++i) {
            c[i] = {a[i] - b[i] * mid, i};
        }
        sort(c + 1, c + n + 1);
        double tmp = 0;
        for(int i = n - k + 1; i <= n; ++i) tmp += c[i].fi;
        if(tmp > -eps) {
            int sum_x = 0, sum_y = 0;
            for(int i = n - k + 1; i <= n; ++i) {
                int id = c[i].se;
                sum_x += a[id];
                sum_y += b[id];
            }
            x = sum_x;
            y = sum_y;
            l = mid;
        } else r = mid;
    }
    int tmp = __gcd(x, y);
    cout << x/tmp << " " << y/tmp;
}

int32_t main() {

    read();
    sol();

    return 0;
}
