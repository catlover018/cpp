#include <iostream>

using namespace std;
using ll = long long;

const int maxN = 1e6;

int Left, Right;
int n, a[maxN + 5];
ll pref[maxN + 5];

void read() {
    cin >> n >> Left >> Right;
    for(int i = 1; i <= n; ++i) cin >> a[i], pref[i] = pref[i - 1] +  a[i];
}

void sol() {
    ll ans = -1e18;
    int idL = 0, idR = n; pref[n + 1] = 1e18;
    for(int i = 1, l = n + 1, r = 1; i <= n; ++i) {
        if(a[i] >= Left) {
            if(pref[i - 1] < pref[l]) l = i - 1;
            if(a[i] <= Right) r = i;
        } else {
            r = -1; l = n + 1;
        }
        if(l <= r && pref[i] - pref[l] > ans) {
            ans = pref[i] - pref[l];
            idL = l + 1;
            idR = i;
        }
    }
    cout << ans << '\n' << idL << " " << idR;
}

int main() {

    read();
    sol();

    return 0;
}
