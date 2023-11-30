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
const int MOD = 1000000;
const int Hash_MOD = 1000000007;
const double PI = acos(-1);

/*
-------------------------------------------------------------------------------------
    END OF TEMPLATE
-------------------------------------------------------------------------------------
    Nguyen Hoang Hung - catlover
    Training for VOI24 gold medal
-------------------------------------------------------------------------------------
*/

string a[maxN+5];

string char_to_morse(char c)  //morse code of a character
{
  if(c == 'A') return ".-";
  if(c == 'B') return "-...";
  if(c == 'C') return "-.-.";
  if(c == 'D') return "-..";
  if(c == 'E') return ".";
  if(c == 'F') return "..-.";
  if(c == 'G') return "--.";
  if(c == 'H') return "....";
  if(c == 'I') return "..";
  if(c == 'J') return ".---";
  if(c == 'K') return "-.-";
  if(c == 'L') return ".-..";
  if(c == 'M') return "--";
  if(c == 'N') return "-.";
  if(c == 'O') return "---";
  if(c == 'P') return ".--.";
  if(c == 'Q') return "--.-";
  if(c == 'R') return ".-.";
  if(c == 'S') return "...";
  if(c == 'T') return "-";
  if(c == 'U') return "..-";
  if(c == 'V') return "...-";
  if(c == 'W') return ".--";
  if(c == 'X') return "-..-";
  if(c == 'Y') return "-.--";
  if(c == 'Z') return "--..";
  return "";
}

const int base = 2;

bool decode(char c)
{
  if(c == '.') return 0;
  return 1;
}

ll morse_to_hash(string s) //get hash a string (contain morse code only)
{
  int n = SZ(s);
  ll res = 0;
  s = ' ' + s;
  FOR(i, 1, n)
  {
    res = (res * base + decode(s[i])) % Hash_MOD;
  }
  return res;
}

string string_to_morse(string s) //convert a string to morse code (contain character only)
{
  string res = "";
  for(char c : s)
  {
    res += char_to_morse(c);
  }
  return res;
}

ll myHash[maxN+5], pw[maxN+5];

ll get(int l, int r)
{
  return (myHash[r] - myHash[l - 1] * pw[r - l + 1] +
          1ll * Hash_MOD * Hash_MOD) % Hash_MOD;
}

ll dp[maxN+5];
vector<pair<ll, ll>> v;

void solve() {
  string s;
  cin >> s;
  int N = SZ(s);
  s = ' ' + s;
  myHash[0] = 0;  pw[0] = 1;
  FOR(i, 1, N)
  {
    myHash[i] = (myHash[i - 1] * base + decode(s[i])) % Hash_MOD;
    pw[i] = pw[i - 1] * base % Hash_MOD;
  }

  int n;  cin >> n;
  FOR(i, 1, n)
  {
    cin >> a[i];
    string tmp = string_to_morse(a[i]);
    ll curHash = morse_to_hash(tmp);
    v.pb({SZ(tmp), curHash});
  }
  dp[0] = 1;
  FOR(i, 1, N)
  {
    for(auto [len, Hash] : v)
    {
      if(i < len) continue;
      if(get(i - len + 1, i) == Hash)
      {
        dp[i] += dp[i - len];
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[N];
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

    file("morsedec");

//    solve_TestCase();

    solve();

    cerr << "\nTime : " << clock()/1000.0 << "s\n";

    return 0;
}

