#include <bits/stdc++.h>

#define int long long

using namespace std;

const int base = 31;
const int maxN = 2e5;
const int MOD = 1e9 + 7;

struct Node {
    int _val, _sz;
    Node() {_val = 0; _sz = 0;}
    Node(int val, int sz) {
        _val = val; _sz = sz;
    }
};

string s1, s2;
Node T1[maxN * 4 + 5], T2[maxN * 4 + 5], curT[maxN * 4 + 5];
int Pow[maxN + 5], lz[maxN * 4 + 5];
int n;

Node operator + (Node a, Node b) {
    return Node((a._val * Pow[b._sz] + b._val) % MOD, a._sz + b._sz);
}

void read() {
    cin >> s2; s1 = s2;
    n = s1.size();  s1 = ' ' + s1;  s2 = ' ' + s2;
    Pow[0] = 1;
    for(int i = 1; i <= n; ++i) {
        s2[i] = (s1[i] == '1' ? '0' : '1');
        Pow[i] = (Pow[i - 1] * base) % MOD;
    }
}

void init(int node, int l, int r, string s, Node T[]) {
    if(l == r) {
        T[node] = Node(s[l] - '0' + 1, 1);
        return;
    }
    int mid = (l + r) / 2;
    init(node * 2, l, mid, s, T);
    init(node * 2 + 1, mid + 1, r, s, T);
    T[node] = T[node * 2] + T[node * 2 + 1];
}

void cal(int node) {
    curT[node] = (curT[node]._val == T1[node]._val ? T2[node] : T1[node]);
}

void push(int node) {
    cal(node * 2);  cal(node * 2 + 1);
    lz[node * 2] = 1;   lz[node * 2 + 1] = 1;
    lz[node] = 0;
}

void update(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return;
    if(u <= l && r <= v) {
        cal(node);
        lz[node] = 1;
        return;
    }
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    update(node * 2, l, mid, u, v);
    update(node * 2 + 1, mid + 1, r, u, v);
    curT[node] = curT[node * 2] + curT[node * 2 + 1];
}

Node get(int node, int l, int r, int u, int v) {
    if(l > r || l > v || u > r) return Node(0, 0);
    if(u <= l && r <= v) return curT[node];
    if(lz[node]) push(node);
    int mid = (l + r) / 2;
    Node Left = get(node * 2, l, mid, u, v);
    Node Right = get(node * 2 + 1, mid + 1, r, u, v);
    if(Left._sz == 0) return Right;
    if(Right._sz == 0) return Left;
    return Left + Right;
}

void sol() {
    init(1, 1, n, s1, curT);
    init(1, 1, n, s1, T1);
    init(1, 1, n, s2, T2);
    int query;  cin >> query;
    while(query--) {
        int type;   cin >> type;
        if(type == 1) {
            int u, v;   cin >> u >> v;
            update(1, 1, n, u, v);
        } else {
            int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
            Node tmp1 = get(1, 1, n, l1, r1);
            Node tmp2 = get(1, 1, n, l2, r2);
            cout << (tmp1._val == tmp2._val ? "YES" : "NO") << '\n';
        }
    }
}

//01101011
//4
//2 1 2 6 7
//2 3 5 6 8
//1 3 4
//2 3 5 6 8

int32_t main() {

    freopen("bedao_r15_bittest.inp", "r", stdin);
    freopen("bedao_r15_bittest.out", "w", stdout);


    read();
    sol();

    return 0;
}
