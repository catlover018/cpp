#include <iostream>
#include <stack>
#include <queue>

#define int long long

using namespace std;
using ll = long long;

const int maxN = 2e5;
int a[maxN + 5];

void sol() {
    int n;  cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    stack<int> Q;
    for(int i = n; i; --i) {
        int cur_val = a[i];
        while(!Q.empty() && Q.top() > cur_val) {
            cur_val += Q.top();
            Q.pop();
        }
        Q.push(cur_val);
    }
    cout << Q.size() << '\n';
}

int32_t main() {

    int testcase;   cin >> testcase;

    while(testcase--) {
        sol();
    }

    return 0;
}
