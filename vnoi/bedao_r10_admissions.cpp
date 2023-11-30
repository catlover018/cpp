// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define debug(x) { cerr << #x << " = "; cerr << (x) << endl; }
#define PR(a,n) { cerr << #a << " = "; FOR(_,1,n) cerr << a[_] << ' '; cerr << endl; }
#define PR0(a,n) { cerr << #a << " = "; REP(_,n) cerr << a[_] << ' '; cerr << endl; }

#define bit(X, i) ((X >> i) & 1)
#define cntbit(X) __builtin_popcountll(X)
#define fi first
#define se second

#define pb push_back
#define all(X) begin(X), end(X)
#define SZ(X) ((int)(X).size())
#define RR(X) X.resize(unique(all(X)) - begin(X))
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using namespace std;

template <typename T>
bool maximize(T &x, T y)
{
  if(x < y)
    x = y;
  else
    return 0;
  return 1;
}
template <typename T>
bool minimize(T &x, T y)
{
  if(x > y)
    x = y;
  else
    return 0;
  return 1;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll Rand(ll l, ll r) { return l + rand() % (r - l + 1); }

const int maxN = 1e6;
const ll inf = 1e18+7;
const int MOD = 1e9 + 7;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

struct student
{
  int f, s, t, id, mark;
  student()
  {
    f = 0;
    s = 0;
    t = 0;
    id = 0;
    mark = 0;
  }
  student(int _f, int _s, int _id, int _mark)
  {
    f = _f;
    s = _s;
    id = _id;
    mark = _mark;
    t = f + s;
  }
};

bool cmp1(student &a, student &b)
{
  return (a.f == b.f ? a.id < b.id : a.f > b.f);
}

bool cmp2(student &a, student &b)
{
  if(a.mark == b.mark)
  {
    return (a.s == b.s ? a.id < b.id : a.s > b.s);
  }
  return a.mark > b.mark;
}

bool cmp3(student &a, student &b)
{
  if(a.mark == b.mark)
  {
    return (a.t == b.t ? a.id < b.id : a.t > b.t);
  }
  return a.mark > b.mark;
}

student a[maxN+5];

void solve() {
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  FOR(i, 1, N)
  {
    int x;  cin >> x;
    a[i].f = x;
  }
  FOR(i, 1, N)
  {
    int x;  cin >> x;
    a[i] = student(a[i].f, x, i, 0);
  }

  vector<int> res;

  // A highest marks at math
  sort(a + 1, a + N + 1, cmp1);
  int i = 1;
  while(A --> 0)
  {
    res.pb(a[i].id);
    a[i].mark = -1;
    ++i;
  }

  // B highest marks at IT
  sort(a + 1, a + N + 1, cmp2);
  i = 1;
  while(B --> 0)
  {
    if(a[i].mark >= 0) res.pb(a[i].id);
    a[i].mark = -1;
    ++i;
  }

  // C highest sum of IT + math marks
  sort(a + 1, a + N + 1, cmp3);
  i = 1;
  while(C --> 0)
  {
    if(a[i].mark >= 0) res.pb(a[i].id);
    a[i].mark = -1;
    ++i;
  }

  sort(all(res));
  for(int x : res) cout << x << '\n';
}

void solve_TestCase() {
  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    solve();
  }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    file("bedao_r10_admissions");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


