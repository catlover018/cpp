#include <bits/stdc++.h>

#define int long long
#define shl(k) (1ll<<(k))

using namespace std;

const int maxN = 2e3;
const int maxM = 2e6+5e5;
const int MOD = 1e9+7;

int a[maxN+5][maxN+5], A[maxM+5], B[maxM+5], C[maxM+5], D[maxM+5], E[maxM+5], F[maxM+5], L[maxM+5];
int n, q, ans[maxM+5];
int f[20][maxN+5][maxN+5];

void get(int x[], int i, int mod) {
  if(i == 1) x[i] = (x[i-1]*x[i-1])%mod+1;
  else x[i] = (x[i-1]+x[i-2])%mod+1;
}

void read() {
  cin >> n >> q;
  cin >> A[0] >> B[0] >> C[0] >> D[0] >> E[0] >> F[0];
  for(int i = 1; i <= n; ++i) {
      get(A, i, MOD);
      get(B, i, MOD);
  }
  for(int i = 1; i <= q; ++i) {
    get(C, i, MOD);
    get(D, i, n);
    get(E, i, n);
    get(F, i, n);
    L[i] = n - max(D[i], E[i]);
  }
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      int cur_val = (A[i] + B[j])%MOD;
      a[i][j] = cur_val;
      a[i+n][j] = cur_val;
      a[i][j+n] = cur_val;
      a[i+n][j+n] = cur_val;
      f[0][i][j] = f[0][i+n][j] = cur_val;
      f[0][i][j+n] = f[0][i+n][j+n] = cur_val;
    }
  for(int k = 1; k <= 18; ++k)
  for(int i = 1; i + (1 << (k-1)) <= 2*n; ++i)
    for(int j = 1; j + (1 << (k-1)) <= 2*n; ++j) {
        f[k][i][j] = max(f[k-1][i][j],
                      max(f[k-1][i+shl(k-1)][j],
                        max(f[k-1][i][j+shl(k-1)],
                         f[k-1][i+shl(k-1)][j+shl(k-1)])));
    }
}

int cal(int u, int v, int z) {
  int k = log2(z);
  int x = u+z-1, y = v+z-1;
  return max(f[k][u][v],
          max(f[k][x-shl(k)+1][v],
             max(f[k][u][y-shl(k)+1],
             f[k][x-shl(k)+1][y-shl(k)+1])));
}

void Print() {
  for(int i = 1; i <= 2*n; ++i) {
    if(i == n+1) cout << '\n';
    for(int j = 1; j <= 2*n; ++j) {
      if(j == n+1) cout << " ";
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

void trau() {
  int cnt = 0, total = 0;
  int bonus_x = 0, bonus_y = 0;
  for(int i = 1; i <= q; ++i) {
    if(C[i]&1) {
      bonus_x += D[i];  bonus_y += E[i];
      bonus_x %= n;     bonus_y %= n;
     } else {
      int x = (D[i]+bonus_x)%n,
          y = (E[i]+bonus_y)%n,
          z = 1+(L[i]&(L[i]^F[i]));
        if(x == 0) x = n;
        if(y == 0) y = n;
//      if(z <= 0 || x <= 0 || y <= 0) cout << 1 << " " << x << " " << y << " " << z << endl;
      int res = cal(x, y, z);
      total += res; total %= MOD;
      ++cnt;
      if(cnt == 1000) {
        cout << total << '\n';
        total = 0;  cnt = 0;
      }
    }
  }
  if(cnt) {
    cout << total << '\n';
  }
}

int32_t main() {

  cin.tie(0)->sync_with_stdio(0);

//  freopen("rmq_board.inp", "r", stdin);
//  freopen("rmq_board.out", "w", stdout);

  read();
//  Print();
  trau();

  return 0;
}
