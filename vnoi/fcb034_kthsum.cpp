#include <bits/stdc++.h>

#define pii pair<int, int>
#define se second
#define fi first

using namespace std;

const int maxN = 1e5;

int n, k;
int a[maxN + 5], b[maxN + 5];

priority_queue<pii, vector<pii>, greater<pii>> Q;

void read() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
}

void sol() {
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; ++i) Q.push({a[i] + b[1], 1});
    while(k--) {
        pii top = Q.top();  Q.pop();
        if(top.se < n) {
            Q.push({top.fi - b[top.se] + b[top.se + 1], top.se + 1});
        }
        cout << top.fi << ' ';
    }
}

int main() {

    read();
    sol();

    return 0;
}
