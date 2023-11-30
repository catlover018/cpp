#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int inf = 1e18 + 1;

struct pack {
    int mn, mx;
    long long dis;
    int idL, idR, idmx, idmn;
    pack() {mx = -inf; mn = inf; dis = -inf;}
    pack(int _mx, int _mn, int _dis) {
        mx = _mx;   mn = _mn;
        dis = _dis;
    }
};

int a[maxN + 5], Left, Right, n;
long long pref[maxN + 5];


pack T[maxN * 4 + 5];

pack operator + (pack a, pack b) {
    pack res;
    if(a.mx > b.mx) {
        res.idmx = a.idmx;
        res.mx = a.mx;
    } else {
        res.idmx = b.idmx;
        res.mx = b.mx;
    }

    if(a.mn < b.mn) {
        res.idmn = a.idmn;
        res.mn = a.mn;
    } else {
        res.idmn = b.idmn;
        res.mn = b.mn;
    }

    if(a.dis > b.dis) {
        res.dis = a.dis;
        res.idL = a.idL;
        res.idR = a.idR;
    } else {
        res.dis = b.dis;
        res.idL = b.idL;
        res.idR = b.idR;
    }

    if(res.dis < b.mx - a.mn) {
        res.dis = b.mx - a.mn;
        res.idL = a.idmn;
        res.idR = b.idmx;
    }

    return res;
}

void init(int node, int l, int r) {
    if(l == r) {
        T[node].dis = pref[l] - pref[l - 1];
        T[node].mn = pref[l - 1];
        T[node].mx = pref[l];
        T[node].idmx = l;
        T[node].idmn = l;
        T[node].idL = l;
        T[node].idR = l;
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

pack get(int node, int l, int r, int u, int v) {
    pack ans;
    if(l > r || l > v || u > r) return ans;
    if(u <= l && r <= v) return T[node];
    int mid = (l + r) / 2;
    pack Left = get(node * 2, l, mid, u, v);
    pack Right = get(node * 2 + 1, mid + 1, r, u, v);
    ans = Left + Right;
    return ans;
}

void read() {
    cin >> n >> Left >> Right;
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], pref[i] = pref[i - 1] + a[i];
}

stack<int> S;
int _r[maxN + 5], _l[maxN + 5];
void sol() {
    init(1, 1, n);
    a[n + 1] = -inf; a[0] = -inf;
    for(int i = 1; i <= n + 1; ++i) {
        while(!S.empty() && a[S.top()] > a[i]) {
            _r[S.top()] = i - 1;
            S.pop();
        }
        S.push(i);
    }
    while(!S.empty()) S.pop();
    for(int i = n; i >= 0; --i) {
        while(!S.empty() && a[S.top()] > a[i]) {
            _l[S.top()] = i + 1;
            S.pop();
        }
        S.push(i);
    }
    long long ans = -inf;
    int id1 = 0, id2 = 0;
    for(int i = 1; i <= n; ++i) {
        if(Left <= a[i] && a[i] <= Right) {
            pack cur_ans = get(1, 1, n, _l[i], _r[i]);
            if(cur_ans.dis > ans) {
                ans = cur_ans.dis;
                id1 = cur_ans.idL;
                id2 = cur_ans.idR;
            }
        }
    }
    cout << ans << '\n' << id1 << " " << id2;
}

int32_t main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
