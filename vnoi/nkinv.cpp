#include <iostream>

#define int long long

using namespace std;

const int maxN = 1e6;

int BIT[maxN + 5];
int n, a[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

int get(int i) {
    int ans = 0;
    for(; i < maxN; i += (i&(-i))) ans += BIT[i];
    return ans;
}

void update(int i, int val) {
    for(; i; i -= (i&(-i))) BIT[i] += val;
}

void sol() {
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += get(a[i] + 1);
        update(a[i], 1);
    }
    cout << ans;
}

//6
//6 2 3 5 1 4
//6
//2 3 1 4 5 6

int32_t main() {

    read();
    sol();

    return 0;
}
