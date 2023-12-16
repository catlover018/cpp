#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6;

int A, B;
int pr[maxN+5];

void sieve()
{
  pr[0] = pr[1] = 1;
  for(int i = 2; i * i <= maxN; ++i)
    if(pr[i] == 0) for(int j = i * i; j <= maxN; j += i)
      pr[j] = 1;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  sieve();

  cin >> A >> B;

  int ans = 0;
  while(A <= B)
  {
    if(pr[A] == 0) cout << A << '\n';
    ++A;
  }

  return 0;
}
