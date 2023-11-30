#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
using ll = long long;

const int maxN = 1e5 + 5;
const double pi = 3.14159265358979;
const double eps = 0.0000001;

ll a[maxN];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = a[1];
}

double get_angle(int p, double x) {
    return 2 * a[p] * a[p + 1] / ((a[p] + x) * (a[p + 1] + x));
}

double cal(double x) {
    double ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += acos(1 - get_angle(i, x));
    }
    return ans;
}

void sol() {
    double l = 0.01, ans = 0, r = 1e9;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(cal(mid) < 2 * pi) {
            ans = mid;
            r = mid ;
        } else l = mid;
    }
    cout << fixed << setprecision(3) << ans;
}

int main() {

    read();
    sol();

    return 0;
}
