#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int k, n;
int a[maxN + 5];

void read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

int check(int x) {
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
            cnt += (a[i]/x);
            if(a[i] % x == 0) --cnt;
    }
    return cnt;
}

void sol() {
    int l = 1, r = 1e18;
    while(l <= r) {
        int mid = (l+r)/2;
        int cur = check(mid);
        if(cur <= k) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}

//5 2
//3 3 3 4 100

int32_t main() {

    read();
    sol();

    return 0;
}
