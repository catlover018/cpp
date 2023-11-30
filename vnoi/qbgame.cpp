#include <bits/stdc++.h>

#define int long long

#define bit(n, i) ((n >> i)&1)

using namespace std;

const int maxN = 1e5;
const int inf = 1e9;

int dp[maxN + 5][(1 << 8) + 5];

//bool check(int x) {
//    while(x) {
//        if(x & 1) {
//            if((x / 2) & 1) return false;
//        }
//        x /= 2;
//    }
//    return true;
//}
//int d = 0, a[1000];
//void cal() {
//    for(int i = 0; i < (1 << 8); ++i)
//        if(check(i)) a[++d] = i;
//    for(int i = 1; i <= d; ++i)  cout << a[i] << ", ";
//}

int n, a[10][maxN + 5];
vector<int> d = {0, 1, 2, 4, 5, 8, 9, 10, 16, 17, 18, 20, 21, 32, 33, 34, 36, 37, 40, 41, 42, 64, 65, 66, 68, 69, 72, 73, 74, 80, 81, 82, 84, 85, 128, 129, 130, 132, 133, 136, 137, 138, 144, 145, 146, 148, 149, 160, 161, 162, 164, 165, 168, 169, 170};

void read() {
    cin >> n;
//    for(int i = 0; i < 8; ++i)
//        for(int j = 1; j <= n; ++j) a[i][j] = a[j][i] = -inf;
    int mxval = -inf;
    for(int i = 0; i < 8; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j], mxval = max(mxval, a[i][j]);
    if(mxval < 0) {
        cout << mxval;
        exit(0);
    }
}

int mxcol[maxN];

bool check_pre_mask(int mask, int pre_mask) {
    for(int i = 0; i < 8; ++i)
        if(bit(mask, i) && bit(pre_mask, i)) return false;
    return true;
}

int get(int mask, int j) {
    int ans = 0;
    for(int i = 0; i < 8; ++i) if(bit(mask, i)) ans += a[i][j];
    return ans;
}


void pre_processing() {
    for(int i = 1; i <= n; ++i)
    for(int mask : d) {
        dp[i][mask] = -inf;
    }
}

int special_case() {
    int ans = -inf;
    for(int i = 0; i < 8; ++i)    ans = max(ans, a[i][1]);
    return ans;
}

void sol() {
    pre_processing();
    for(int i = 1; i <= n; ++i)
        for(int mask : d) {
                int cost = get(mask, i);
                for(int pre_mask : d) {
                    if(check_pre_mask(mask, pre_mask) == false) continue;
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][pre_mask] + cost);
                }
            }
    int ans = -inf;
    for(int mask : d) ans = max(ans, dp[n][mask]);
    cout << ans;
}

//2
//-1 -1
//-1 -1
//-1 -1
//-1 -1
//-1 -1
//-1 -1
//-1 -1
//-1 -1

int32_t main() {

    read();
    sol();

    return 0;
}
