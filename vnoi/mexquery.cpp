#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)

using namespace std;

const int maxN = 3e5;

struct Segtree
{
  int T[maxN*4+5], lz[maxN*4+5];

  Segtree()
  {
    memset(T, 0, sizeof(T));
    memset(lz, -1, sizeof(lz));
  }

  void push(int node, int l, int r)
  {
    int &val = lz[node];
    int mid = (l + r) / 2;

    T[node*2] = (mid - l + 1)*val;
    T[node*2+1] = (r - mid)*val;

    lz[node*2] = val;
    lz[node*2+1] = val;

    val = -1;
  }

  void update(int node, int l, int r, int u, int v, int val)
  {
    if(l > r || u > r || l > v) return;
    if(u <= l && r <= v)
    {
      T[node] = (r - l + 1) * val;
      lz[node] = val;
      return;
    }
    if(lz[node] != -1) push(node, l, r);
    int mid = (l + r) / 2;
    update(node*2, l, mid, u, v, val);
    update(node*2+1, mid+1, r, u, v, val);
    T[node] = T[node*2] + T[node*2+1];
  }

  int get(int node, int l, int r, int u, int v)
  {
    if(l > r || u > r || l > v) return 0;
    if(u <= l && r <= v) return T[node];
    if(lz[node] != -1) push(node, l, r);
    int mid = (l + r) / 2;
    return get(node*2, l, mid, u, v) + get(node*2+1, mid+1, r, u, v);
  }
};

int a[maxN+5];
Segtree ST[50];
int N, cnt[50];

void read_input()
{
  cin >> N;
  FOR(i, 1, N) cin >> a[i];
}

void solve()
{
  FOR(i, 1, N) ST[a[i]].update(1, 1, N, i, i, 1);

  int Q;  cin >> Q;
  while(Q --> 0)
  {
    int type, l, r; cin >> type >> l >> r;
    if(l > r) swap(l, r);
    if(type == 1)
    {
      cin >> type;
      FOR(i, 0, 30)
      {
        cnt[i] = ST[i].get(1, 1, N, l, r);
        ST[i].update(1, 1, N, l, r, 0);
      }
      if(type == 1)
      {
        int i = l, cur = 0;
        while(i <= r)
        {
          if(cnt[cur])
          {
            ST[cur].update(1, 1, N, i, i + cnt[cur] - 1, 1);
          }
          i += cnt[cur];
          ++cur;
        }
      }
      else
      {
        int i = l, cur = 30;
        while(i <= r)
        {
          if(cnt[cur])
          {
            ST[cur].update(1, 1, N, i, i + cnt[cur] - 1, 1);
          }
          i += cnt[cur];
          --cur;
        }
      }
    }
    else
    {
      FOR(i, 0, 31)
      {
        if(ST[i].get(1, 1, N, l, r) == 0)
        {
          cout << i << '\n';
          break;
        }
      }
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("mexquery");

  read_input();
  solve();

  return 0;
}
