#include <iostream>
#include <vector>
#include <algorithm>

#define int long long

using namespace std;

using ll = long long;

const int maxN = 1e6;

struct pack {
    ll W, V;
    pack() {W = 0; V = 0;}
    pack(ll _W, ll _V) {
        W = _W;
        V = _V;
    }
    bool operator < (const pack& o) const {
        return W < o.W;
    }
};

int n1, n2;
ll m;
pack a[maxN + 5], b[maxN + 5];
vector<pack> Right, Left;

void ql1(int i, ll cur_W, ll cur_V) {
    if(cur_W > m) return;
    if(i == n1 + 1) {
        Left.push_back(pack(cur_W, cur_V));
        return;
    }
    ql1(i + 1, cur_W, cur_V);
    ql1(i + 1, cur_W + a[i].W, cur_V + a[i].V);
}

void ql2(int i, ll cur_W, ll cur_V) {
    if(cur_W > m) return;
    if(i == n2 + 1) {
        Right.push_back(pack(cur_W, cur_V));
        return;
    }
    ql2(i + 1, cur_W, cur_V);
    ql2(i + 1, cur_W + b[i].W, cur_V + b[i].V);
}

void read() {
    cin >> n2 >> m;
    n1 = (int)(n2 / 2);
    n2 -= n1;
    for(int i = 1; i <= n1; ++i) cin >> a[i].W >> a[i].V;
    for(int i = 1; i <= n2; ++i) cin >> b[i].W >> b[i].V;
}

ll cur_Value[maxN * 4 + 5];

int lower_bound(ll x) {
    int ans = -1;
    int l = 0, r = n2 - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(Right[mid].W <= x) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

void sol() {
    ql1(1, 0, 0);
    ql2(1, 0, 0);
    sort(Right.begin(), Right.end());
    n1 = Left.size();   n2 = Right.size();
    cur_Value[0] = Right[0].V;
    for(int i = 1; i < n2; ++i) cur_Value[i] = max(cur_Value[i - 1], Right[i].V);
    ll ans = cur_Value[n2 - 1];
    for(int i = 0; i < n1; ++i) {
        int p = lower_bound(m - Left[i].W);
        if(p != -1) {
            ans = max(ans, cur_Value[p] + Left[i].V);
        }
        ans = max(ans, Left[i].V);
    }
    cout << ans;
}

int32_t main() {

    read();
    sol();


    return 0;
}
