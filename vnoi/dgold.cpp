#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

const int maxN = 25;
const int maxM = 1e5;

struct pack{
    int sum1, sum2, dis;
    pack() {sum1 = 0; sum2 = 0; dis = 0;}
    pack(int _sum1, int _sum2, int _dis) {
        sum1 = _sum1;   sum2 = _sum2;
        dis = _dis;
    }
    bool operator < (const pack& o) const {
        return dis < o.dis;
    }
};

vector<pack> val;
int n1, n2, a[maxN], b[maxN], o[maxN], m;
int cur_sum1 = 0, cur_sum2 = 0, ans = 0;

void read() {
    cin >> n2;
    for(int i = 1; i <= n2; ++i) cin >> o[i];
    n1 = n2 / 2;    n2 -= n1;
}

void duyet1(int i) {
    if(i == n2 + 1) {
        val.push_back(pack(cur_sum1, cur_sum2, cur_sum1 - cur_sum2));
        return;
    }
    for(int j = 0; j < 3; ++j) {
        if(j == 0) duyet1(i + 1);
        if(j == 1) {
            cur_sum1 += b[i];
            duyet1(i + 1);
            cur_sum1 -= b[i];
        }
        if(j == 2) {
            cur_sum2 += b[i];
            duyet1(i + 1);
            cur_sum2 -= b[i];
        }
    }
}

void cal(int value, int s1, int s2) {
    int l = 0, r = val.size();  --r;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(val[mid].dis + value == 0) {
            ans = max(ans, s1 + val[mid].sum1);
            l = mid + 1;
        } else if(val[mid].dis + value > 0) r = mid - 1;
        else l = mid + 1;
    }
}

void duyet2(int i) {
    if(i == n1 + 1) {
        cal(cur_sum1 - cur_sum2, cur_sum1, cur_sum2);
        return;
    }
    for(int j = 0; j < 3; ++j) {
        if(j == 0) duyet2(i + 1);
        if(j == 1) {
            cur_sum1 += a[i];
            duyet2(i + 1);
            cur_sum1 -= a[i];
        }
        if(j == 2) {
            cur_sum2 += a[i];
            duyet2(i + 1);
            cur_sum2 -= a[i];
        }
    }
}

void sol() {
    for(int i = 1; i <= n1; ++i) a[i] = o[i];
    for(int i = 1; i <= n2; ++i) b[i] = o[i + n1];
    duyet1(1);
    sort(val.begin(), val.end());
    cur_sum1 = 0;   cur_sum2 = 0;    ans = 0;
    duyet2(1);
    cout << ans;
}

int32_t main() {

    read();
    sol();

    return 0;
}
