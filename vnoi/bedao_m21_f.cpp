#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int n, q;
int a[maxN + 5];

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        char c; cin >> c;
        a[i] = c - '0';
    }
}

int cal() {
    int ans = 0;
    int cur_val = 0, cnt = 0, p = -1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == cur_val) {
            if(p == -1) p = i;
            ++cnt;
            ++ans;
            if(cnt == 2) {
                cur_val = 1 - cur_val;
                cnt = 0;
            }
        }
    }
    for(int i = 1; i < p; ++i) if(a[i] == 1) {
        ++ans;
        break;
    }
    int tmp = ans;
    ans = 0;
    cur_val = 1;    cnt = 0;    p = -1;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == cur_val) {
            if(p == -1) p = i;
            ++cnt;  ++ans;
            if(cnt == 2) {
                cur_val = 1 - cur_val;
                cnt = 0;
            }
        }
    }
    for(int i = 1; i < p; ++i) if(a[i] == 0) {
        ++ans;
        break;
    }
    ans = max(ans, tmp);
    return ans;
}

void sol() {
    cin >> q;
    while(q--) {
        int x;  cin >> x;
        a[x] = 1 - a[x];
        cout << cal() << '\n';
    }
}

int main() {

    read();
    sol();

    return 0;
}
