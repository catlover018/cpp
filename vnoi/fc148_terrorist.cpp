#include <bits/stdc++.h>

using namespace std;

const int maxN = 100;

int n;
string s;
int dp[maxN][maxN][maxN][2];
vector<int> F, C, X;

void read() {
    cin >> n >> s;  s = " " + s;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == 'F') F.push_back(i);
        else if(s[i] == 'C') C.push_back(i);
        else X.push_back(i);
    }
}

int getcount(vector<int> v, int l, int r_val) {
    int cnt = 0;
    for(int i = l; i < (int)v.size() && v[i] < r_val; ++i) ++cnt;
    return cnt;
}

void sol() {
    for(int i = 0; i < n; ++i)  for(int j = 0; j < n; ++j)
    for(int k = 0; k < n; ++k)  for(int t = 0; t < 2; ++t)
        dp[i][j][k][t] = 1e9;
    dp[0][0][0][0] = 0;
    for(int i = 0; i <= (int)F.size(); ++i)  for(int j = 0; j <= (int)C.size(); ++j)
        for(int k = 0; k <= (int)X.size(); ++k)  for(int t = 0; t < 2; ++t) {
                if(i < (int)F.size()) {
                    dp[i + 1][j][k][1] = min(dp[i + 1][j][k][1], dp[i][j][k][t] + getcount(F, i, F[i]) + getcount(C, j, F[i]) + getcount(X, k, F[i]));
                }
                if(j < (int)C.size() && t == 0) {
                    dp[i][j + 1][k][0] = min(dp[i][j + 1][k][0], dp[i][j][k][t] + getcount(F, i, C[j]) + getcount(C, j, C[j]) + getcount(X, k, C[j]));
                }
                if(k < (int)X.size()) {
                    dp[i][j][k + 1][0] = min(dp[i][j][k + 1][0], dp[i][j][k][t] + getcount(F, i, X[k]) + getcount(C, j, X[k]) + getcount(X, k, X[k]));
                }
        }
    cout << min(dp[F.size()][C.size()][X.size()][0], dp[F.size()][C.size()][X.size()][1]);
}

int main() {

    read();
    sol();

    return 0;
}
