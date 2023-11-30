#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int a[maxN + 5], n;
int lds[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

int trace[maxN + 5];
int b[maxN + 5];

void sol() {
    for(int i = 1; i <= n; ++i) {
        lds[i] = 1;
        trace[i] = 0;
        for(int j = 1; j < i; ++j) {
            if(a[i] < a[j]) {
                if(lds[i] <= lds[j] + 1) {
                    trace[i] = j;
                    lds[i] = lds[j] + 1;
                }
            }
        }
    }
    int p = max_element(lds + 1, lds + n + 1) - lds;
    vector<int> v;
    while(p > 0) {
//        cout << p << " ";
        v.push_back(p);
        p = trace[p];
    }
    int lm = v.size();
    for(int i = 0, j = lm-1; i < lm; ++i, --j) b[v[i]] = a[v[j]];
    int ans = 0;
    for(int i = 1; i <= n; ++i) if(!b[i]) b[i] = a[i];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j < i; ++j)
            if(b[j] > b[i]) ++ans;
    cout << ans;
}

int main() {

    read();
    sol();

    return 0;
}
