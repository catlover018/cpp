#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int maxN = 1e5;

priority_queue<int> Q;
set<int> S;
int n, a[maxN + 5];

int to_num(string s) {
    int ans = 0;
    for(int i = 1; i < int(s.size()); ++i) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
}

char s[maxN + 5];

int main() {

//    freopen("test.inp", "r", stdin);

    while(cin.getline(s, sizeof(s))) {
        if(s[0] == '-') {
            if(!Q.empty()) {
                int top = Q.top();
                while(!Q.empty() && Q.top() == top) Q.pop();
            }
        } else if(Q.size() < 15000) {
            Q.push(atoi(s + 1));
        }
    }
    n = 0;
    int mx = 1e9 + 7;
    while(!Q.empty()) {
        if(Q.top() != mx) a[++n] = Q.top(), mx = Q.top();
        Q.pop();
    }

    cout << n << '\n';
    for(int i = 1; i <= n; ++i) cout << a[i] << '\n';

    return 0;
}
