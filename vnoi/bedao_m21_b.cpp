#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 5e6;

vector<int> v;
int cnt[10];

bool check(int x) {
    for(int i = 0; i < 10; ++i) cnt[i] = 0;
    int _x = x*x;
    while(x > 0) {
        ++cnt[x%10];
        if(cnt[x%10] > 2) return false;
        x /= 10;
    }
    while(_x > 0) {
        ++cnt[_x%10];
        if(cnt[_x%10] > 2) return false;
        _x /= 10;
    }
    return true;
}

void init() {
    for(int i = 1; i <= maxN; ++i)
        if(check(i)) v.push_back(i);
}

int32_t main() {

    init();

    int testcase;   cin >> testcase;

    while(testcase--) {
        int x;  cin >> x;
        int p = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(v[p] >= x) {
            cout << v[p] << '\n';
        } else cout << -1 << '\n';
    }

    return 0;
}
