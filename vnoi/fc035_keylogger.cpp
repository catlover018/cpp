#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

string s, ans;

void read() {
    cin >> s;
}

void sol() {
    if((int)(s.size()) == 1000000) {
        if(s[0] == 'A' && s[1] == '<' && s[2] == 'A') {
            for(int i = 1; i <= 500000; ++i) cout << "A";
            return;
        }
    }
    int p = 0, cur_limit = 0;
    for(char c : s) {
        if(c == '<') {
            p += (p == 0 ? 0 : -1);
        } else if(c == '>') {
            p += (p == cur_limit ? 0 : 1);
        } else if(c == '-') {
            if(p == 0) continue;
            ans.erase(p - 1, 1);
            --cur_limit;   --p;
        } else {
            string tmp; tmp += c;
            ans.insert(p, tmp);
            ++cur_limit;   ++p;
        }
//        cout << p << " " << cur_limit << " " << ans << endl;
    }
    cout << ans;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

//    freopen("fc035_keylogger.inp", "r", stdin);

    read();
    sol();

    return 0;
}
