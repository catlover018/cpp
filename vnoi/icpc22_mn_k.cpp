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

struct HTML
{
  string Name;
  int R, G, B;
  HTML()
  {
    Name = "";
    R = 0;
    G = 0;
    B = 0;
  }
  HTML(string _Name, int _R, int _G, int _B)
  {
    Name = _Name;
    R = _R;
    G = _G;
    B = _B;
  }
};

HTML color[20];

int sqr(int x)
{
  return x * x;
}

string calc(int r, int g, int b)
{
  string res = "";
  int dis = 1e9;
  FOR(i, 1, 16)
  {
    auto [Name, R, G, B] = color[i];
    int d = sqrt(sqr(r - R) + sqr(g - G) + sqr(b - B));
//    cout << d << endl;
    if(dis > d)
    {
      dis = d;
      res = Name;
    }
  }
  return res;
}

void solve() {
  color[1] = HTML("White", 255, 255, 255);
  color[2] = HTML("Silver", 192, 192, 192);
  color[3] = HTML("Gray", 128, 128, 128);
  color[4] = HTML("Black", 0, 0, 0);
  color[5] = HTML("Red", 255, 0, 0);
  color[6] = HTML("Maroon", 128, 0, 0);
  color[7] = HTML("Yellow", 255, 255, 0);
  color[8] = HTML("Olive", 128, 128, 0);
  color[9] = HTML("Lime", 0, 255, 0);
  color[10] = HTML("Green", 0, 128, 0);
  color[11] = HTML("Aqua", 0, 255, 255);
  color[12] = HTML("Teal", 0, 128, 128);
  color[13] = HTML("Blue", 0, 0, 255);
  color[14] = HTML("Navy", 0, 0, 128);
  color[15] = HTML("Fuchsia", 255, 0, 255);
  color[16] = HTML("Purple", 128, 0, 128);

  int r, g, b;
  while(cin >> r >> g >> b)
  {
    if(r == -1) break;
    cout << calc(r, g, b) << '\n';
  }
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

    file("icpc22_mn_k");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}


