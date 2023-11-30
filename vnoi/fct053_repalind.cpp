#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
ll k;

void read() {
    cin >> s >> k;
    string rev = s;
    reverse(s.begin(), s.end());
    bool check = (s == rev);
    if(check) {
        cout << "YES\n";
        return;
    }
    if(k % 2 == 0) {
        cout << "NO\n";
        return;
    }
    string tmp = rev + rev + rev;
    string tmp2 = tmp;
    reverse(tmp.begin(), tmp.end());
    cout << (tmp == tmp2 ? "YES" : "NO") << '\n';

}

int main() {

    int testcase;   cin >> testcase;

    while(testcase--)

    read();

    return 0;
}
