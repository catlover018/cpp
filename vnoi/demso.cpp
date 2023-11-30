#include <iostream>
#include <cstring>

#define int long long

using namespace std;

const int maxN = 16;

int dp[maxN + 5][maxN + 5][10 + 5][3];
int d, k, n1, n2;
string A, B;

string sub(string a, string b) {
    while(a.size() < b.size()) a = "0" + a;
    while(b.size() < a.size()) b = "0" + b;
    int len = a.size();
    string res = "";    int nho = 0;
    for(int i = len - 1; i >= 0; --i) {
        int t = a[i] - b[i] - nho;
        if(t < 0) t += 10, nho = 1;
        res = char(t + '0') + res;
    }
    while(res[0] == '0' && res.size() > 1) res.erase(0, 1);
    return res;
}

void read() {
    cin >> A >> B >> d >> k;    A = sub(A, "1");
    A = " " + A;    B = " " + B;
}

int cal(int digit, int x) {
    if(digit < x) return 0;
    if(digit == x) return 1;
    return 2;
}

int cal(int i, int cur_k, int last, int isLess, string s) {
    int& x = dp[i][cur_k][last][isLess];
    if(x > -1) return x;
    x = 0;
    if(i == 1) return x;
    for(int digit = 0; digit <= 9; ++digit) {
        if(isLess == 0) {
            int check = cur_k - (abs(last - digit) <= d);
            if(check < 0) {
                if(i == 2 && digit == 0) check = cur_k;
                else continue;
            }
            x += cal(i - 1, check, digit, 0, s);
//            cout << i - 1 << " " << check << " " << digit << " " << 0 << " " << x << endl;
            if(last < s[i] - '0') x += cal(i - 1, check, digit, 1, s);
        } else if(isLess == 2) {
            int check = cur_k - (abs(last - digit) <= d);
            if(check < 0) {
                if(i == 2 && digit == 0) check = cur_k;
                else continue;
            }
            x += cal(i - 1, check, digit, 2, s);
//            cout << i - 1 << " " << check << " " << digit << " " << 0 << " " << x << endl;
            if(last > s[i] - '0') x += cal(i - 1, check, digit, 1, s);
        } else if(last == s[i] - '0' && digit == s[i - 1] - '0') x += cal(i - 1, cur_k - (abs(last - digit) <= d), digit, 1, s);
    }
    return x;
}

int func(string s) {
    int n = s.size();   --n;
    memset(dp, -1, sizeof(dp));
    for(int j = 0; j <= k; ++j)
    for(int digit = 0; digit < 10; ++digit) {
        int isLess = 1;
        if(s[1] - '0' < digit) isLess = 2;
        if(s[1] - '0' > digit) isLess = 0;
        int& x = dp[1][j][digit][isLess];
        if(x == -1) x = 0;
        ++x;
    }
    int res = 0;
    for(int digit = 0; digit < 10; ++digit) res += cal(n, k, digit, 0, s);
    res += cal(n, k, s[n] - '0', 1, s);
    return res - 1;
}

void sol() {

    cout << func(B) - func(A);

}

//1 13 1 0

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
