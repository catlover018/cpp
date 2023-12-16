#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define FOR(i, l, r) for(int i=l ; i<=r ; i++)
#define FOD(i, r, l) for(int i=r ; i<=l ; i--)
#define fi first
#define se second
#define oo 1000000000000
const int N = (int)1e6+10;
int a[N],magic[30][N];

bool check(int l,int r,int x)
{
    int s = 0;
    FOR(j,0,30)
        if(magic[j][r]-magic[j][l-1]==(r-l+1)) s+=1<<j;
    if(s>=x) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        freopen("1878E.inp", "r", stdin);
    freopen("1878E.ans", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        FOR(i,0,30) magic[i][0] = 0;
        FOR(i,1,n)
            FOR(j,0,30) magic[j][i] = magic[j][i-1]+((a[i]>>j)&1);
        cin >> q;
        while (q--)
        {
            int x,k;
            cin >> x >> k;
            ll l = x, r = n, res = oo;
            while (l <= r)
            {
                int mid = (l+r)/2;
                if (check(x,mid,k)) res = mid, l = mid+1;
                else r = mid-1;
            }
            cout << (res==oo?-1:res) << " ";
        }
        cout << endl;
    }
    return 0;
}
