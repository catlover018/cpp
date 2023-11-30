#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 2e5;

string s;

void read() {
    cin >> s;
}

void sol() {
    int query;  cin >> query;
    while(query--) {
        int type;   cin >> type;
        if(type == 1) {
            int u, v;   cin >> u >> v;
            for(int i = u - 1; i < v; ++i) {
                if(s[i] == '1') s[i] = '0';
                else s[i] = '1';
            }
            cout << s << endl;
        } else {
            int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
            bool check = (r1 - l1 == r2 - l2);
            --l1;   --l2;
            while(l1 < r1) {
                if(s[l1] != s[l2]) {
                    check = false;
                    break;
                }
                ++l1;   ++l2;
            }
            cout << (check ? "YES" : "NO") << '\n';
        }
    }
}

int32_t main() {

    freopen("bedao_r15_bittest.inp", "r", stdin);
    freopen("bedao_r15_bittest.ans", "w", stdout);

    read();
    sol();

    return 0;
}
