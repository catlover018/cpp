#include <bits/stdc++.h>

#define file(task) if(fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define pb push_back
#define all(X) X.begin(), X.end()
#define SZ(X) (int)((X).size())

const int maxN = 1e6;

using namespace std;

struct Qs
{
  int x, y1, y2, type;
  Qs() = default;
  Qs(int _x, int _y1, int _y2, int _type)
  {
    x = _x;
    y1 = _y1;
    y2 = _y2;
    type = _type;
  };
  bool operator < (const Qs &o) const
  {
    return (o.x == x ? o.type < type : x < o.x);
  }
};

struct Ds
{
  int l, r, val;
  Ds() = default;
  Ds(int _l, int _r, int _val)
  {
    l = _l;
    r = _r;
    val = _val;
  }
};

int N, d[maxN+5];
vector<Qs> queries;
map<int, int> mp;

void read_input()
{
  cin >> N;
  vector<int> v;
  FOR(i, 1, N)
  {
    int x, y, d, c;
    cin >> x >> y >> d >> c;
    v.pb(y);  v.pb(y + c);
    queries.pb(Qs(x, y + 1, y + c, 1));
    queries.pb(Qs(x + d, y + 1, y + c, -1));
  }
  sort(all(v));
  v.resize(unique(all(v))-v.begin());
  for(auto &[x, y1, y2, type] : queries)
  {
    int p = lower_bound(all(v), y1) - v.begin() + 1;
    mp[p] = y1;
    y1 = p;
    p  = lower_bound(all(v), y2) - v.begin() + 1;
    mp[p] = y2;
    y2 = p;
  }
}

void update(int l, int r, int val)
{
  FOR(i, l, r) d[i] += val;
}

void solve()
{
  sort(all(queries));
//  for(auto [x, y1, y2, type] : queries)
//  {
//    cout << x << ' ' << y1 << ' ' << y2 << ' ' << type << endl;
//  }
  int i = 0, lm = SZ(queries);
  while(i < lm)
  {
    vector<Ds> v;
    int idx = queries[i].x, t = queries[i].type;
    while(i < lm && queries[i].x == idx && queries[i].type == t)
    {
      v.pb(Ds(queries[i].y1, queries[i].y2, queries[i].type));
      ++i;
    }
    for(auto [l, r, val] : v)
    {
      update(mp[l], mp[r], val);
      cout << l << ' ' << r << ' ' << val << endl;
    }
    FOR(i, 1, 8) cout << d[i] << ' ';
    cout << endl;
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  file("hcm_thpt_23_c");

  read_input();
  solve();

  return 0;
}
