#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 1e6;

int N, K;
int w[maxN+5];

void read_input()
{
    cin >> N >> K;
    FOR(i, 1, N) cin >> w[i];
}

namespace trau
{
    int check(int limit)
    {
        multiset<int> S;
        FOR(i, 1, N) S.insert(w[i]);
        int cnt = 0;
        while(!S.empty())
        {
            ++cnt;
            int remain = limit;
            while(!S.empty())
            {
                auto it = S.upper_bound(remain);
                if(it == S.begin()) break;
                --it;
                remain -= *it;
                S.erase(it);
            }
        }
        return cnt;
    }

    void solve()
    {
        int maxW = 0, sumW = 0;
        FOR(i, 1, N)
        {
            maxW = max(maxW, w[i]);
            sumW += w[i];
        }
        int low = max(maxW, sumW / K), high = sumW;
        for(int c = low; c <= high; ++c)
        {
            if(check(c) <= K)
            {
                cout << c << '\n';
                return;
            }
        }
    }
}

namespace sub4
{
    int check(int limit)
    {
        multiset<int> S;
        FOR(i, 1, N) S.insert(w[i]);
        int cnt = 0;
        while(!S.empty())
        {
            ++cnt;
            int remain = limit;
            while(!S.empty())
            {
                auto it = S.upper_bound(remain);
                if(it == S.begin()) break;
                --it;
                remain -= *it;
                S.erase(it);
            }
        }
        return cnt;
    }

    int calc()
    {
        int maxW = 0, sumW = 0;
        FOR(i, 1, N)
        {
            maxW = max(maxW, w[i]);
            sumW += w[i];
        }
        int low = max(maxW, sumW / K), high = sumW;
        int l = 0, r = (high - low) / maxW + 1;
        int res = -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(check(low + mid * maxW) <= K)
            {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if(res == 0) return low;
        FOR(c, low + (res - 1) * maxW + 1, low + res * maxW)
        if(check(c) <= K)
        {
            return c;
        }
    }

    void solve()
    {
        cout << calc() << '\n';
    }
}

void solve()
{
    read_input();
    sub4:: solve();
}

int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);

    file("I");

    int testcase;   cin >> testcase;

    while(testcase --> 0)
    {
        solve();
    }


    return 0;
}
