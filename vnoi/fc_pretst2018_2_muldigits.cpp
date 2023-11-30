#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int maxn = 1e5;

ull b, n;

void read() {
    cin >> b >> n;
}


void sol() {
    vector<int> v;
    for(int i = min(9ull, b - 1); i > 1; --i) {
        while(n % i == 0) {
            v.push_back(i);
            n /= i;
        }
    }
    if(n > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    int lm = v.size(), i = 0;
    ull ans = 0, cur_base = 1;
    while(i < lm) {
        ull cur = 0, base = 1;
        while(i < lm && cur + v[i] * base < b) {
            cur += v[i] * base;
            base *= 10;
            ++i;
        }
        ans += cur * cur_base;
        cur_base *= b;
    }
    if(ans <= 0) {
        cout << "NO SOLUTION\n";
    } else{
        cout << ans << '\n';
    }
}

int main() {

    while(cin >> b >> n) {
        sol();
    }

    return 0;
}
