#include <bits/stdc++.h>

using namespace std;

string s, t;
int k;

void read() {
    cin >> s >> t >> k;
}

void sol() {
    int n = s.size(), cnt = 0;
    while(t.size() > 0) {
        int p = t.find(s);
        if(p == -1) {
            cout << "NO";
            return;
        }
        t.erase(p, n); ++cnt;
    }
    if(cnt == k) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main() {

    read();
    sol();

    return 0;
}
