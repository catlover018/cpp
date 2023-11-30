#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e4;

ll col[maxN + 5], row[maxN + 5];
int n, m, q;

void read() {
    cin >> n >> m >> q;
}

void sol() {
    while(q--) {
        int type;   cin >> type;
        if(type == 3) {
            int u1, u2, v1, v2; cin >> u1 >> v1 >> u2 >> v2;
            ll maxRow = 0, maxCol = 0;
            for(int i = u1; i <= u2; ++i) maxRow = max(maxRow, row[i]);
            for(int i = v1; i <= v2; ++i) maxCol = max(maxCol, col[i]);
            cout << maxRow + maxCol << '\n';
        } else {
            int x, val; cin >> x >> val;
            if(type == 1) row[x] += val;
            if(type == 2) col[x] += val;
        }
    }
}

int main() {

    read();
    sol();

    return 0;
}

