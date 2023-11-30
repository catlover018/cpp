#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, a, b) for(int i = (a); i <=(b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define REPD(i, a, b) for(int i = (a); i >=(b); i--)
#define TR(it, a) for(typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define RESET(a, v) memset((a), (v), sizeof((a)))
#define SZ(a) (int((a).size()))
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define LL long long
#define LD long double
#define II pair<int, int>
#define X first
#define Y second
#define VI vector<int>
const int N = 1010;
const int M = 20002;
using namespace std;
vector<II> a[N];
int n, m;
bool was[N], inStack[N], deleted[M];
bool foundCycle;

struct edge {
    int u, v;
    bool operator < (const edge &b) const {
        return MP(u, v) < MP(b.u, b.v);
    }
} e[M];

VI s;
void dfsFindFirstCycle(int u) {
    if (foundCycle) return;
    was[u] = inStack[u] = 1;
    TR(it, a[u]) {
        if (foundCycle) return;
        int v = it -> X;
        int edgeID = it -> Y;
        s.PB(edgeID);
        if (inStack[v]) {
            foundCycle = 1;
            return;
        }
        if (!was[v]) dfsFindFirstCycle(v);
        if (foundCycle) return;
        s.pop_back();
    }
    inStack[u] = 0;
}

void dfsCycleDetect(int u) {
    if (foundCycle) return;
    was[u] = inStack[u] = 1;
    TR(it, a[u]) {
        if (foundCycle) return;
        int v = it -> X;
        int edgeID = it -> Y;
        if (deleted[edgeID]) continue;
        if (inStack[v]) {foundCycle = 1; return;}
        if (!was[v]) dfsCycleDetect(v);
    }
    if (foundCycle) return;
    inStack[u] = 0;
}

bool cycleDetect() {
    REP(i, 1, n) was[i] = inStack[i] = 0;
    foundCycle = 0;
    REP(i, 1, n) if (!was[i]) {
        dfsCycleDetect(i);
        if (foundCycle) return 1;
    }
    return 0;
}

vector<edge> ans;
int main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> e[i].u >> e[i].v;
        a[e[i].u].PB(MP(e[i].v, i));
    }

    REP(i, 1, n) if (!was[i]) {
        dfsFindFirstCycle(i);
        if (foundCycle) break;
    }
    while (!s.empty()) {
        deleted[s.back()] = 1;
        cout << s.back() << '\n';
        if (!cycleDetect()) ans.PB(e[s.back()]);
        deleted[s.back()] = 0;
        s.pop_back();
    }
    if (SZ(ans) == 0) cout << -1;
    else {
        cout << SZ(ans) << '\n';
        sort(ALL(ans));
        TR(it, ans) cout << (it -> u) << ' ' << (it -> v) << '\n';
    }
    return 0;
}
