#include <iostream>

using namespace std;

const int maxN = 1e3;

long long a[maxN + 5][maxN + 5];
int n, query;

void read() {
    cin >> n >> query;
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
        char c; cin >> c;
        if(c == '*') a[i][j] = 1;
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
}

void sol() {
    while(query--) {
        int x, y, u, v; cin >> x >> y >> u >> v;
        cout << a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1] << '\n';
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
