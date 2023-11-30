#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

vector<pair<int, int>> mv = {{2, 1}, {-2, 1}, {-2, -1}, {2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

int x1, y, x2, _y;

void read() {
    cin >> x1 >> y >> x2 >> _y;
}


void sol() {
    for(int i = 0; i < 8; ++i) {
        if(x1 + mv[i].fi == x2 && y + mv[i].se == _y) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

int main() {

    read();
    sol();

    return 0;
}
