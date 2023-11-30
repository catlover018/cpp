#include <iostream>
#include <cstring>

#define int long long

using namespace std;

const int maxN = 1e5;
const int maxD = 1e2;
const int MOD = 1e9 + 7;

//dp[i][cnt][tight]

int k, n;
string s;
int dp[maxN + 5][maxD + 5][3];

void read() {
    cin >> s >> k;
    n = s.size();   s = " " + s;
    memset(dp, -1, sizeof(dp));
}

int cal(int i, int sum, int tight) {
    int& x = dp[i][sum][tight];
    if(x > -1) return x;
    x = 0;
    if(i == 1) return x;
    for(int digit = 0; digit < 10; ++digit) {
        int pre_sum = (sum - digit) % k;
        while(pre_sum < 0) pre_sum += k;
        pre_sum %= k;
        if(tight == 0) {
            x += cal(i - 1, pre_sum, 0);
            if(digit < s[i] - '0') x += cal(i - 1, pre_sum, 1);
            x %= MOD;
        } else if(tight == 2) {
            x += cal(i - 1, pre_sum, 2);
            if(digit > s[i] - '0') x += cal(i - 1, pre_sum, 1);
            x %= MOD;
        } else if(digit == s[i] - '0') {
            x += cal(i - 1, pre_sum, 1);
            x %= MOD;
        }
    }
    return x;
}

//30 4

void sol() {
    for(int digit = 0; digit < 10; ++digit) {
        int tight = 1;
        if(digit < s[1] - '0') {
            tight = 0;
        }
        if(digit > s[1] - '0') {
            tight = 2;
        }
        int& x = dp[1][digit % k] [tight];
        if(x == -1) x = 0;
        ++x;
    }
    cout << (cal(n, 0, 0) + cal(n, 0, 1) - 1 + MOD) % MOD;
}

int32_t main() {

    read();
    sol();

    return 0;
}
