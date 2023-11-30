#include<bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int inf = 1e18;

int a[maxN + 5], x, n;
int mark[maxN + 5];
vector<int> v;

void read() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(!mark[a[i]]) {
            v.push_back(a[i]);
            mark[a[i]] = true;
        }
    }
}

void sol() {
    int ans = inf;
    for(int color : v) {
        bool ok = true; int cur_ans = 0;
        for(int i = 1; i <= n; ++i) {
            int tmp = color - a[i];
            if(tmp < 0 || tmp % x != 0) {
                ok = false;
                break;
            }
            tmp /= x;
            cur_ans += tmp;
        }
        if(ok) {
            ans = min(ans, cur_ans);
        }
    }
    cout << (ans == inf ? -1 : ans);
}

int32_t main() {

    read();
    sol();

    return 0;
}
