// cre: Nguyen Hoang Hung - Train VOI 2024

#include <bits/stdc++.h>

#define int long long

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

int Pow(int a, int b)
{
  if(b == 0) return 1;
  int mid = Pow(a, b / 2);
  mid = mid * mid % MOD;
  if(b & 1) return mid * a % MOD;
  return mid % MOD;
}

void Print(int res_tu, int res_mau)
{
  cout << (res_tu * Pow(res_mau, MOD - 2)) % MOD << '\n';
}

void calc2(int d, int n)
{
  int res_tu = Pow(n-1, d+1);
  int res_mau = Pow(n, d+1);
  res_tu = (res_mau - res_tu + MOD) % MOD;
  Print(res_tu, res_mau);
}

void calc1(int d, int n, int c)
{
  int res_tu = Pow(n-1, d+1);
  int res_mau = Pow(n, d+1);
  int tu = n + c - 1;
  int mau = n + c;
  res_tu = res_tu * tu % MOD;
  res_mau = res_mau * mau % MOD;
  res_tu = (res_mau - res_tu + MOD) % MOD;
  Print(res_tu, res_mau);
}

void solve() {
  int N, M, K;
  cin >> N >> K >> M;
  if(M == 1)
  {
    int res_tu = 1, res_mau = N;
    Print(res_tu, res_mau);
  }
  else if(M == 2)
  {
    int res_tu = 1, res_mau = N;
    int tu, mau;
    N += K;
    tu = (res_mau - res_tu + MOD) % MOD;
    mau = (res_mau * N) % MOD;
    res_tu = ((res_mau*tu%MOD) + (res_tu*mau%MOD)) % MOD;
    res_mau = (res_mau * mau) % MOD;
    Print(res_tu, res_mau);
  }
  else
  {
    if(M%2==0) calc1((M-1)/2, N, K);
    else calc2(M/2, N);
  }
}

void solve_TestCase() {
  int testcase; cin >> testcase;

  while(testcase --> 0)
  {
    solve();
  }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

//    file("template");

    solve_TestCase();

//    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

