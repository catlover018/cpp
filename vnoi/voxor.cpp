#include <bits/stdc++.h>

#define bit(n, i) ((n>>i)&1)

using namespace std;

const int maxN = 1e5 + 5;
const int base = 20;

struct Node {
    int child[2], exist, cnt;
    Node() {
        child[0] = -1;  child[1] = -1;
        exist = 0;  cnt = 0;
    }
};

Node Trie[maxN];
int n_Node = 0;

void add(int x) {
    int cur = 0;
    for(int i = base; i >= 0; --i) {
        int c = bit(x, i);
        if(Trie[cur].child[c] == -1) Trie[cur].child[c] = ++n_Node;
        cur = Trie[cur].child[c];
        Trie[cur].cnt++;
    }
    Trie[cur].exist++;
}

int main() {

    return 0;
}
