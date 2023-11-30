#include <iostream>
#include <set>

using namespace std;

const int maxN = 1e5;

int a[maxN + 5], n, m;
multiset<int> T[maxN * 4 + 5];

multiset<int> Merge(multiset<int> a, multiset<int> b) {
    a.insert(b.begin(), b.end());
    return a;
}

void init(int node, int l, int r) {
    if(l == r) {
        T[node].insert(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = Merge(T[node * 2], T[node * 2 + 1]);
}

multiset<int>::iterator it;

void update(int node, int l, int r, int p, int val) {
    while(l != r) {
        it = T[node].lower_bound(a[p]);
        T[node].erase(it);
        T[node].insert(val);
        int mid = (l + r) / 2;
        if(p <= mid) {
            node = node * 2;
            r = mid;
        } else {
            node = node * 2 + 1;
            l = mid + 1;
        }
    }
    if(l == r && r == p) {
        it = T[node].lower_bound(a[p]);
        T[node].erase(it);
        T[node].insert(val);
    }
}

int get(int node, int l, int r, int u, int v, int val) {
    if(l > r || u > r || l > v) return 1e9 + 1;
    if(u <= l && r <= v) {
        it = T[node].lower_bound(val);
        if(it == T[node].end()) return 1e9 + 1;
        return *it;
    }
    int mid = (l + r) / 2;
    int Left = get(node * 2, l, mid, u, v, val);
    int Right = get(node * 2 + 1, mid + 1, r, u, v, val);
    return min(Left, Right);
}

void read() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
}

void sol() {
    init(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        int type;   cin >> type;
        if(type == 1) {
            int p, val; cin >> p >> val;
            update(1, 1, n, p, val);
            a[p] = val;
        } else {
            int u, v, val;  cin >> u >> v >> val;
            int cur_ans = get(1, 1, n, u, v, val);
            if(cur_ans == 1e9 + 1) {
                cout << -1;
            } else {
                cout << cur_ans;
            }
            cout << '\n';
        }
    }
}

int main() {

    cin.tie(0)->sync_with_stdio(0);

    read();
    sol();

    return 0;
}
