#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<climits>
#define fori(i, d, c) for(int i = d; i <= c; i++)
#define int long long
#define MAX 10005
using namespace std;

int n;
int m;

void xuly()
{
    int l, r;   cin >> l >> r;
    int res = 1;
    for(int i = l; i <= r; ++i) res *= i;
    int n = res;
        int i = 2;
        while(i*i <= n)
        {
                if(n%i==0)
                {
                        while(n%i==0) n /= i;

                    res -= res/i;
                }
                i++;
        }
        if(n>1) res -= res/n;
        cout << res % m << endl;
}

int32_t main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);     cout.tie(0);
        cin >> m;
        int t;
        cin >> t;
        if(t > 10)
        {
            cout << -1;
            return 0;
        }
        while(t--)
        xuly();
        return 0;
}
