#include<bits/stdc++.h>
using namespace std;

void read(int &x)
{
    x = 0;
    char C = getchar();
    while(C > '9' || C < '0') C = getchar();
    while(C >= '0' && C <= '9')
    {
        x = x * 10 + C - 48;
        C = getchar();
    }
}


const int N = 2e5+7;

int p[20][N],h[N],d[N],cx[N];
int n,m;
vector<pair<int,int>> g[N];

void dfs(int u)
{
    for(auto [v,i] : g[u]) if(v!=p[0][u])
    {
        p[0][v] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int lca(int u, int v)
{
    if(h[u] < h[v]) swap(u,v);
    int d = h[u] - h[v];
    for(int i=17; i>=0; i--)
        if((d>>i)&1) u = p[i][u];

    if(u == v) return u;

    for(int i=17; i>=0; i--)
        if(p[i][u] != p[i][v])
    {
        u = p[i][u];
        v = p[i][v];
    }

    return p[0][u];
}

void spread(int u)
{
    for(auto [v,i] : g[u]) if(v!=p[0][u])
    {
        spread(v);
        d[u] += d[v];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int u,v;
    read(n);
    for(int i=1; i<n; i++)
    {
        read(u);
        read(v);
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }

    dfs(1);
    for(int i=1; i<=17; i++) for(int v = 1; v + (1 << (i)) <= n; v++) p[i][v] = p[i-1][p[i-1][v]];

    read(m);
    while(m--)
    {
        read(u);
        read(v);
        int p = lca(u,v);
        d[u]++,d[v]++;
        d[p]-=2;
    }
    spread(1);

    int cnt = 0;
    for(int i=2; i<=n; i++) if(!d[i]) cnt++;
    cout<<cnt;
}

