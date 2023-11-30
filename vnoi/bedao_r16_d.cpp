#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int n;
int a[maxN + 5], b[maxN + 5];
vector<int> v[maxN + 5];
int mark[maxN], mark1[maxN];
int cur_sum = 0, cur_ans = 1e9;

#define fi first
#define se second

void ql(int i, int lm, int pos) {
    for(int j = 0; j <= 1; ++j) {
        mark1[v[pos][i]] = j;
        if(j == 0) cur_sum += abs(a[v[pos][i]] - b[v[pos][i]]);
        else cur_sum -= abs(a[v[pos][i]] - b[v[pos][i]]);
        if(i == lm) {
            if(abs(cur_sum) <= abs(cur_ans)) {
                cur_ans = cur_sum;
                for(int i = 0; i < lm; ++i)
                    mark[v[pos][i]] = mark1[v[pos][i]];
            }
        } else ql(i + 1, lm, pos);
        if(j == 0) cur_sum -= abs(a[v[pos][i]] - b[v[pos][i]]);
        else cur_sum += abs(a[v[pos][i]] - b[v[pos][i]]);
    }
}

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) {
        v[abs(a[i] - b[i])].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= 5; ++i) {
        if(v[i].size() % 2 == 0) {
            int lm = v[i].size();  lm /= 2;
            for(int j = 0; j < lm; ++j) mark[v[i][j]] = true;
        } else {
            ql(0, int(v[i].size()) - 1, i);
            ans += cur_ans;
        }
    }
    cout << abs(ans) << '\n';
    int cnt = 0;
    for(int i = 1; i <= n; ++i) if(mark[i]) ++cnt;  cout << cnt << " ";
    for(int i = 1; i <= n; ++i) if(mark[i]) cout << i << " " ;
}

int main() {

    read();

    return 0;
}
