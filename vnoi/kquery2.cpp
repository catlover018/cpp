#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()

using namespace std;

const int maxN = 1e5 + 5;
const int BLOCK = 400;

int n, a[maxN + 5];
int BIT[200][maxN + 5];

void update(int bl, int i, int val) {
    for(; i > 0; i -= (i&(-i))) BIT[bl][i] += val;
}

int get(int bl, int i) {
    int ans = 0;
    for(; i <= maxN; i += (i&(-i))) ans += BIT[bl][i];
    return ans;
}

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], update(i / BLOCK, a[i], 1);
}

void sol() {
    int query;  cin >> query;
    while(query--) {
        int type;   cin >> type;
        if(type == 0) {
            int p, val; cin >> p >> val;
            update(p / BLOCK, a[p], -1);
            update(p / BLOCK, val, 1);
            a[p] = val;
        } else {
            int u, v, k;    cin >> u >> v >> k;
            int ans = 0;
            while(u <= v && u % BLOCK != 0) {
                ans += a[u] > k;
                ++u;
            }
            while(u <= v && v % BLOCK != BLOCK - 1) {
                ans += a[v] > k;
                --v;
            }
            if(u < v) {
                int l = u / BLOCK, r = v / BLOCK;
                for(int i = l; i <= r; ++i) ans += get(i, k + 1);
            }
            cout << ans << '\n';
        }
    }

}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
