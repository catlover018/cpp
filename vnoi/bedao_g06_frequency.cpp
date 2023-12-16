#include <bits/stdc++.h>

#define int long long

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define fi first
#define se second
#define pb push_back
#define SZ(X) (int)(X.size())
#define mp make_pair

using namespace std;

typedef pair<int, int> pii;

const int maxN = 1e6;

int N, M;
vector<pii> qu[maxN+5];
int a[maxN+5], last[maxN+5], ans[maxN+5], leaf[maxN+5];
pii T[maxN*4+5], lz[maxN*4+5], inf;

void read(){}
template <typename Head, typename ...Tail>
void read(Head &H, Tail &...T)
{
    int sign = 0;
    char c;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-') sign = 1;
    H = c - '0';
    for (c = getchar(); isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign) H = -H;
    read(T...);
}

void read_input()
{
  read(N);
  FOR(i, 1, N) read(a[i]);
  read(M);
  FOR(i, 1, M)
  {
    int l, r; read(l);  read(r);
    qu[r].pb(mp(l, i));
  }
}

void push(int node)
{
  pii val = lz[node];
  T[node<<1] = T[(node<<1)+1] = val;
  lz[node<<1] = lz[(node<<1)+1] = val;
  lz[node] = mp(-1, -1);
}

void init(int node, int l, int r)
{
  if(l == r)
  {
    leaf[l] = node;
    return;
  }
  int mid = (l + r) / 2;
  init(node<<1, l, mid);
  init((node<<1)+1, mid+1, r);
}

void update(int p, pii val)
{
  int node = leaf[p];
  T[node] = val;
  lz[node] = val;
  node >>= 1;
  while(node)
  {
    T[node] = min(T[node<<1], T[(node<<1)+1]);
    node >>= 1;
  }
}

pii get(int node, int l, int r, int u, int v)
{
  if(l > r || l > v || u > r) return inf;
  if(u <= l && r <= v) return T[node];
  if(lz[node] != mp(-1ll, -1ll)) push(node);
  int mid = (l + r) / 2;
  return min(get(node<<1, l, mid, u, v),
              get((node<<1)+1, mid + 1, r, u, v));
}

void solve()
{
  memset(last, -1, sizeof(last));
  memset(lz, -1, sizeof(lz));
  memset(T, 60, sizeof(T));
  init(1, 1, N);
  inf = T[1];
  FOR(i, 1, N)
  {
    int p = last[a[i]];
    if(p != -1) update(p, inf);
    update(i, mp(p, i));
    for(pii e : qu[i])
    {
      int l = e.fi, id = e.se;
      pii t = get(1, 1, N, l, i);
      if(t.fi < l) ans[id] = a[t.se];
    }
    last[a[i]] = i;
  }
  FOR(i, 1, M)
    cout << ans[i] << '\n';
}

int32_t main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("bedao_g06_frequency");

  read_input();
  solve();

  return 0;
}
