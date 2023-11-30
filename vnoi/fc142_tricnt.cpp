#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;
const int MOD = 1e9+7;

#define pii pair<int, int>
#define fi first
#define se second

vector<pii> a;
int n;

void read() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        pii x;  cin >> x.fi >> x.se;
        a.push_back(x);
    }
}

int Pow(int a, int b) {
    if(b == 0) return 1;
    int tmp = Pow(a, b/2);
    if(b&1) return ((tmp*tmp)%MOD * a)%MOD;
    return (tmp*tmp)%MOD;
}

int C(int k, int n) {
    int res;
    if(k == 2) {
        res = (n*(n-1))%MOD;
        res = (res*(Pow(2, MOD-2)))%MOD;
    } else {
        res = (n*(n-1))%MOD;
        res = (res*(n-2))%MOD;
        res = (res*(Pow(6, MOD-2)))%MOD;
    }
    return res;
}

int BIT[maxN + 5];

void update(int i, int val) {
    for(; i < maxN; i+=(i&-i)) {
        BIT[i] += val;
        BIT[i] %= MOD;
    }
}

int get(int i) {
    int res = 0;
    for(; i; i-=(i&-i)) {
        res += BIT[i];
        res %= MOD;
    }
    return res;
}

void sol() {
    sort(a.begin(), a.end());

    int ans = 0;

    //tam giac deu
    for(auto [x, y] : a) {
        ans += C(3, y);
        ans %= MOD;
    }

    //tam giac can
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j)
            if(i != j) {
                if(2*a[i].fi > a[j].fi) {
                    ans += (C(2, a[i].se)*a[j].se)%MOD;
                    ans %= MOD;
                }
            }

    //tam giac thuong
    for(auto [x, y] : a) update(x, y);
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            int cur = get(a[i].fi+a[j].fi-1)-get(a[j].fi);
            while(cur < 0) cur += MOD;
            ans += ((a[i].se*a[j].se)%MOD)*cur%MOD;
            ans %= MOD;
        }
    }
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
