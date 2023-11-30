#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int c[20];

void read() {
    cin >> n;
}

int cal(int n) {
    int m = 0;  int cnt0 = 0;
    while(n > 0) {
        if(n % 10 == 0) {
            ++cnt0;
        } else {
            c[++m] = n % 10;
        }
        n /= 10;
    }
    sort(c + 1, c + m + 1);
    int ans = c[1];
    while(cnt0) {
        ans = ans * 10;
        --cnt0;
    }
    for(int i = 2; i <= m; ++i) {
        if(c[i] == 2) {
            if(cnt0 > 0) c[i] = 0, --cnt0;
        }
        ans = ans * 10 + c[i];
    }
    return ans;
}

//21100

void sol() {
    int ans = 0;
    while(n > 20) {
        int _n = cal(n);
//        if(_n <= 20) break;
        if(_n != n) ++ans;
        int c1 = _n % 10;
        int c2 = (int)(_n / 10) % 10;
        if(c2 == 0) {
            _n -= (c1 + 1);
            ans += (c1 + 1);
        } else {
            int pre = _n;
            _n /= 10;
            if(c1 == 0) {
                _n = (_n - 1) * 10 + c2 - 1;
            } else {
                _n = _n * 10 + c2 - 1;
            }
            ans += abs(pre - _n);
        }
//        cout << _n << endl;
        n = _n;
    }
    if(n <= 20) ans += n - 1;
    cout << ans << '\n';
}

int32_t main() {

//    int testcase;   cin >> testcase;
//
//    while(testcase--) {

        read();
        sol();

//    }

    return 0;
}
