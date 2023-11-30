#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 33;
const int maxM = 1e5;

int a[maxN], b[maxN], n1, n2, sum = 0, ans = 0, cnt = 0;

void read() {
    cin >> n2;
    n1 = n2 / 2;
    n2 -= n1;
    for(int i = 1; i <= n1; ++i) cin >> a[i], sum += a[i];
    for(int i = 1; i <= n2; ++i) cin >> b[i], sum += b[i];
    ans = sum * 2;
}

int cur_sum = 0, val[maxM], m = 0;

void duyet1(int i) {
    if(i == n1 + 1) {
        val[++m] = cur_sum;
        return;
    }
    duyet1(i + 1);
    cur_sum += a[i];
    duyet1(i + 1);
    cur_sum -= a[i];
}

void cal() {
    int cur_cnt = 1, cur_ans = sum * 2, t = sum - 2 * cur_sum;
    int l = 1, r = m, p = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(val[mid] * 2 <= t) {
            l = mid + 1;
            p = mid;
        } else r = mid - 1;
    }
    if(p > 0) cur_ans = abs(t - 2 * val[p]);
    if(abs(t - 2 * val[p + 1]) < cur_ans) cur_ans = abs(t - 2 * val[p + 1]), ++p;

    if(cur_ans == sum * 2) return;
    if(ans < sum * 2 && cur_ans > ans) return;

    int tmp = p - 1;
    while(tmp > 0 && cur_ans == abs(t - 2 * val[tmp])) --tmp, ++cur_cnt;
    tmp = p + 1;
    while(tmp <= m && cur_ans == abs(t - 2 * val[tmp])) ++tmp, ++cur_cnt;

    if(ans > cur_ans) ans = cur_ans, cnt = cur_cnt;
    else cnt += cur_cnt;
}

void duyet2(int i) {
    if(i == n2 + 1) {
        cal();
        return;
    }
    duyet2(i + 1);
    cur_sum += b[i];
    duyet2(i + 1);
    cur_sum -= b[i];
}

void sol() {
    duyet1(1);
    sort(val + 1, val + m + 1); cur_sum = 0;
    duyet2(1);
    cout << ans << " " << cnt / 2 << '\n';
}

int32_t main() {

    read();
    sol();

    return 0;
}
