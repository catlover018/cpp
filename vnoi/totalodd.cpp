#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e6;

int n, m = 0;
vector<int> v;

bool check(int x) {
    if(x == 0) return false;
    while(x) {
        int tmp = x % 10;
        if(tmp % 2 == 0) return false;
        x /= 10;
    }
    return true;
}

int cal(int x) {
    int lm = lower_bound(v.begin(), v.end(), x) - v.begin();
    int res = v[lm] + v[lm];
    for(int i = 0; i <= lm; ++i) {
        while(i < lm && v[i] + v[lm - 1] >= x) --lm;
        if(v[i] + v[lm] >= x) res = min(res, v[i] + v[lm]);
    }
    return res;
}

void sieve() {
    for(int i = 1; i <= 9; i += 2) v.push_back(i);
    int pos = 0;
    for(int _i = 0; _i < 8; ++_i) {
        int cur_m = v.size();
        for(int i = pos; i < cur_m; ++i) {
            for(int j = 1; j <= 9; j += 2)
            v.push_back(v[i] * 10 + j);
        }
        pos = cur_m - 1;
    }
}

//[CASE]
//100000000
//
//[END]


void sol() {
    sieve();
    string s;   int n;
    while(cin >> s) {
        if(s == "[END]") break;
        cin >> n;
        cout << cal(n) << '\n';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    sol();

    return 0;
}
