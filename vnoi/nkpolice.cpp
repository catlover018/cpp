#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 1e6;

int num[maxN + 5], low[maxN + 5], tin[maxN + 5], tout[maxN + 5];
int n, m;
vector<int> adj[maxN + 5];

void read() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int Time = 0;
int par[21][maxN + 5];

void dfs(int u, int p) {
	tin[u] = ++Time;

	num[u] = ++num[0];
	low[u] = n+1;

	par[0][u] = p;
	for(int i = 1; i <= 20; ++i) par[i][u] = par[i - 1][par[i - 1][u]];

	for (auto v : adj[u]) {
		if (v == p) continue;
		if (num[v])
			low[u] = min(low[u], num[v]);
		else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
	}

	tout[u] = ++Time;
}

bool Joint(int v, int u) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int Find(int p, int v) {
	for(int i = 20; i >= 0; --i) {
		int u = par[i][v];
		if (u > 0 && u != p && Joint(u,p)) v = u;
	}
	return v;
}

bool cal1(int A, int B, int G1, int G2) {
	if (num[G1] > num[G2]) swap(G1, G2);
	if (par[0][G2] != G1) return true;
	if (low[G2] <= num[G1]) return true;
	if (Joint(A,G2) == Joint(B,G2)) return true;
	return false;
}

bool cal2(int A, int B, int C) {
	if (num[A] > num[B]) swap(A,B);
	if (par[0][B] == A) return true;
	if (Joint(B,A)) {
		if (Joint(C,A) && Joint(B,C)) {
			B = Find(C,B);
			if (low[B] < num[C]) return true;
			return false;
		}
		return true;
	}
	if (Joint(C,A) || Joint(C,B)) return true;
	if (Joint(A,C) && Joint(B,C)) {
		A = Find(C,A);
		B = Find(C,B);
		if (A == B) return true;
		if (low[A] < num[C] && low[B] < num[C]) return true;
		return false;
	}
	if (Joint(A,C) || Joint(B,C)) {
		if (Joint(B,C)) swap(A,B);
		A = Find(C,A);
		if (low[A] < num[C]) return true;
		return false;
	}
	return true;
}

void sol() {
    dfs(1, 0);
    int query;  cin >> query;
    while(query--) {
        int type;   cin >> type;
        if(type == 1) {
            int A, B, G1, G2;
            cin >> A >> B >> G1 >> G2;
            cout << (cal1(A, B, G1, G2) ? "yes" : "no") << '\n';
        } else {
            int A, B, C;
            cin >> A >> B >> C;
            cout << (cal2(A, B, C) ? "yes" : "no") << '\n';
        }
    }
}

int32_t main() {

    read();
    sol();

    return 0;
}
