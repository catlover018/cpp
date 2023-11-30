#include <bits/stdc++.h>

using namespace std;

const int maxN = 100;
int mxval = -110, mnval = 110;

int a[maxN + 5][maxN + 5];
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            mxval = max(mxval, a[i][j]);
            mnval = min(mnval, a[i][j]);
        }
}

#define pii pair<int, int>
#define fi first
#define se second

const pii mv[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};


int mark[maxN + 5][maxN + 5];
bool ok(int x, int y) {
    return x > 0 && y > 0 && x <= n && y <= n;
}
bool check(int l, int r) {
    queue<pii> Q;   Q.push({1, 1});
    memset(mark, 0, sizeof(mark));
    mark[1][1] = true;
    while(!Q.empty()) {
        auto [x, y] = Q.front();  Q.pop();
        if(x == n && y == n) return true;
        for(int i = 0; i < 4; ++i) {
            int new_x = x + mv[i].fi, new_y = y + mv[i].se;
            if(ok(new_x, new_y) && a[new_x][new_y] >= l && a[new_x][new_y] <= r && mark[new_x][new_y] == 0) {
                Q.push({new_x, new_y});
                mark[new_x][new_y] = true;
            }
        }
    }
    return false;
}

void sol() {
    int ans = mxval - mnval;
    for(int i = mnval; i <= a[1][1]; ++i) {
        int l = 0, r = ans;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(i, i + mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
    }
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
