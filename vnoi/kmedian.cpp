#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6;

ll pref[maxN + 5], BIT[maxN*2 + 5];
int n, k;

void read() {
    cin >> n >> k;
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int x;  cin >> x;
        x = (x >= k ? 1 : -1);
        pref[i] = pref[i - 1] + x;
    }
}

void update(int i) {
    for(; i <= 2*maxN; i+=(i&-i)) BIT[i]++;
}

ll get(int i) {
    ll res = 0;
    for(; i > 0; i-=(i&-i)) res += BIT[i];
    return res;
}

void sol() {
    ll ans = 0;
    update(maxN);
    for(int i = 1; i <= n; ++i) {
        ans += get(pref[i] + maxN);
//        cout << pref[i] << " " << get(pref[i] + maxN) << endl;
        update(pref[i] + maxN);
    }
    cout << ans;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
