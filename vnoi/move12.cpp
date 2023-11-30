#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxN = 1e6 + 5;
const int inf = 1e9 + 7;

struct Node{
    int fi, se;
    Node() {fi = 0; se = 0;}
    Node(int _fi, int _se) {
        fi = _fi;
        se = _se;
    }
    bool operator < (const Node& o) const {
        return se < o.se;
    }
};

int n, mark[maxN];
Node a[maxN];
vector<int> pos;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
        mark[a[i].fi] = true;;
    }
    for(int i = 1; i <= n; ++i) if(!mark[i]) pos.push_back(i);
}

struct pack {
    int lt, rt;
    pack() {lt = 0; rt = 0;}
    pack(int _lt, int _rt) {
        lt = _lt;
        rt = _rt;
    }
    bool operator < (const pack& o) const {
        return o.lt == lt ? rt < o.rt : lt < o.lt;
    }
};

pack f[maxN];
int L[maxN];

bool check(int x) {
    for(int i = 1; i <= n; ++i) {
        int dis = x / a[i].se;
        f[i].lt = max(1, a[i].fi - dis);
        f[i].rt = min(n, a[i].fi + dis);
        L[i] = f[i].lt;
        mark[i] = 0;
   }
    sort(f + 1, f + n + 1);
    priority_queue<int, vector<int>, greater<int>> Q;
    for(int i = 1, j = 1; i <= n; ++i) {
        while(j <= n && f[j].lt <= i) {
            if(f[j].rt >= i) Q.push(f[j].rt);
            ++j;
        }
        while(!Q.empty() && Q.top() < i) Q.pop();
        if(Q.empty()) return false;
        Q.pop();
    }
    return true;
}

void sol() {
    int l = 0, r = inf, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans;
}


int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
