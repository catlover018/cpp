#include <iostream>

using namespace std;

const int maxN = 21;

int n, m, k;
int cur_n = 0;
string s;
vector<string> v;

void read() {
    cin >> n >> k;
    cur_n = n / 4;
    if((n / 2) % 2 == 0) --cur_n;
    s.resize(n);
}

void duyet1(int i) {
    if(i == cur_n) {
        v.push_back(s);
        return;
    }
    int st = 0;
    if(i == 1) st = 1;
    for(int j = st; j <= 9; ++j) {
        s[i] = char(j + '0');
        if(i + cur_n - 1 <= n / 2) s[i + cur_n] = char(j + '0');
        duyet1(i + 1);
    }
}

void duyet2(int i) {
    if(i == n) {
        cal();
        return;
    }
    for(int j = 0; j <= 9; ++j) {
        s[i] = char(j + '0');
        if(i + cur_n )
    }
}

int main() {

    return 0;
}
