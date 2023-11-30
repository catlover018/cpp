#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
using ll=long long;
int n,sa,sb;
int c[25][25];
int poww(int a,int n)
{
    int ans=1;
    for(int i=1;i<=n;i++) ans*=a;
    return ans;
}
void solve()
{
    cin>>n>>sa>>sb;
    if(sa==sb)
    {
        cout<<0<<'\n';
        return ;
    }
    if(sa>sb) swap(sa,sb);
    if(sa>=n-1&&sb>=n-1)
    {
        if(sb-sa!=2) cout<<0<<'\n';
        else
        {
            cout<<c[n-1][2*n-2]*poww(2,sa-n+1)<<'\n';
        }
    }
    else
    {
        if(sb!=n) cout<<0<<'\n';
        else cout<<c[sa][sa+sb-1]<<'\n';
    }
}
int32_t main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    for(int i=1;i<=20;i++) c[0][i]=1;
    for(int i=1;i<=20;i++)
    {
        c[i][i]=1;
        for(int j=i+1;j<=20;j++) c[i][j]=c[i-1][j-1]+c[i][j-1];
    }
    int t;cin>>t;
    while(t--) solve();
}
