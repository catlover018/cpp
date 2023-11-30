#include <bits/stdc++.h>

#define pii pair<int, int>
#define fi first
#define se second

using namespace std;

const int maxN = 300005;
const int MOD = 1e9+7;

int n;
pii f[maxN];
pii a[maxN];
vector<int> v;
pair<int, pii> query[maxN];

pii get(int x){
    pii res(0, 1);
    for(int i = x; i > 0; i -=i&-i){
        if(res.fi < f[i].fi) res = f[i];
        else if(res.fi == f[i].fi) res.se = (res.se + f[i].se) % MOD;
    }
    res.fi++;
    return res;
}

void update(int x, pii P){
    for(int i = x; i < maxN; i +=i&-i){
        if(f[i].fi < P.fi) f[i] = P;
        else if(f[i].fi == P.fi) f[i].se = (f[i].se + P.se) % MOD;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) { cin >> a[i].fi; cin >> a[i].se; v.push_back(a[i].se);}
    sort(a, a + n); sort(v.begin(), v.end());
    int len = 0;
    pii P, res(0, 0);

    for(int i = 0; i < n; ++i) {
        int u = lower_bound(v.begin(), v.end(), a[i].se) - v.begin() + 1;
        pii t = get(u - 1);
        if(t.fi > res.fi) res = t;
        else if(t.fi == res.fi) res.se = (res.se + t.se) % MOD;
        query[len++] = make_pair(u, t);
        if(i != n - 1 && a[i + 1].fi > a[i].fi){
            for(int _i = 0; _i < len; ++_i) update(query[_i].fi, query[_i].se);
            len = 0;
        }
    }
    cout << res.fi << '\n' << res.se;

    return 0;
}
